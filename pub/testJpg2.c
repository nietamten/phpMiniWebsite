#include <sys/types.h>
#include <dirent.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <time.h>

#include </usr/include/jpeglib.h>
#include <unistd.h>

#include <setjmp.h>
#include <err.h>
 
struct my_error_mgr {
	struct jpeg_error_mgr pub;	
	jmp_buf setjmp_buffer;	
};
typedef struct my_error_mgr * my_error_ptr;

METHODDEF(void)
my_error_exit (j_common_ptr cinfo)
{
	my_error_ptr myerr = (my_error_ptr) cinfo->err;

	if(	cinfo->err->msg_code != 52)
		(*cinfo->err->output_message) (cinfo);
	longjmp(myerr->setjmp_buffer, 1);
}

METHODDEF(void)
my_emit_message(j_common_ptr cinfo, int msg_level)
{
	my_error_ptr myerr = (my_error_ptr) cinfo->err;
	if (msg_level == -1)
	{
		(*cinfo->err->output_message) (cinfo);
		longjmp(myerr->setjmp_buffer, 1);
	}
}

void CloseFile(FILE *f, int fd, int header, int toDel, char* fname)
{
	if (toDel)
		//printf("trunc");
		ftruncate(fd,toDel);

	fclose(f);	
	close(fd);
	
	if (!header)
		//printf("del");
		remove(fname);	
	
	exit(1);
}

int main(int argc, char**argv)
{
	int header = 0;
	int toDel = 0;
	
	int fd = open(argv[1], O_RDWR);
	if(fd != -1)
	{
		FILE *f = fdopen(fd,"rw");
		
		struct jpeg_decompress_struct cinfo;
		struct my_error_mgr jerr;
		cinfo.err = jpeg_std_error(&jerr.pub);
		jerr.pub.error_exit = my_error_exit;	
		jerr.pub.emit_message = my_emit_message	;
		if (setjmp(jerr.setjmp_buffer)) {

			jpeg_destroy_decompress(&cinfo);
			
			if(cinfo.err->msg_code == 52)
				header = 0;
			
			toDel = ftell(f) - cinfo.src->bytes_in_buffer;

			//printf("errNum:%d",cinfo.err->msg_code);
			CloseFile(f,fd,header,toDel,argv[1]);		
		}
		jpeg_create_decompress(&cinfo);
		jpeg_stdio_src(&cinfo, f);

		jpeg_read_header(&cinfo, FALSE);
		if( cinfo.global_state == 200)
			CloseFile(f,fd,header,toDel,argv[1]);
		
		header = 1;

		jpeg_start_decompress(&cinfo);
	
		int row_stride = cinfo.output_width * cinfo.output_components;
		JSAMPARRAY buffer = (*cinfo.mem->alloc_sarray)
			((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

		while (cinfo.output_scanline < cinfo.output_height) {
			(void) jpeg_read_scanlines(&cinfo, buffer, 1);
			//put_scanline_someplace(buffer[0], row_stride);
		}
		
		toDel = ftell(f) - cinfo.src->bytes_in_buffer;
		
		jpeg_finish_decompress(&cinfo);
		jpeg_destroy_decompress(&cinfo);

		CloseFile(f,fd,header,toDel,argv[1]);
	}
	else
	{
		err(1, "%s", argv[1]);
		return 1;
	}
	return 2;
}
