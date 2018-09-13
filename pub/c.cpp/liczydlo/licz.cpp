#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <glib.h>


GtkWidget *window,*box,*box2,*box3,*butt,*e1,*e2,*e3,*e4,*e5;
GtkWidget *l,*PB,*BUF,*sw;
GtkTextBuffer *p3;
double x,y,z,w;
char wynik[1000000],b[10000];
int i,j,k,q;
bool co = FALSE;
pthread_t on;


gboolean update_PB (gpointer data)
{
    double t;
    if (co == TRUE)
	t = double(i)/double(q);
    else{
	t = 0;
	gtk_button_set_label (GTK_BUTTON(butt),"Licz"); 
	}
		
    gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR (data),t);
    sprintf (b,"%f = (%f * %i) + (%f * %i) + (%f * %i)\n",w,x,i,y,j,z,k);
    gtk_label_set_text(GTK_LABEL(l),b);
    gtk_text_buffer_set_text(p3,wynik,strlen(wynik)-1);

    return co;
}

void *argument_thread (void *args)
{	
    double o;

    for (i=0;i<q;i++)
	for (j=0;j<q;j++){
	    for (k=0;k<q;k++){
		o =  ( (x*(double)i) + (y*(double)j) + (z*(double)k) );				
				
		if ( abs(o*10000-w*10000) == 0 ){			
		    strcat(wynik," a = ");
		    sprintf(b, "%i ", i);
		    strcat(wynik,b);
		    strcat(wynik," b = ");
		    sprintf(b, "%i ", j);
		    strcat(wynik,b);
		    strcat(wynik," c = ");
		    sprintf(b, "%i \n", k);
		    strcat(wynik,b);
						}		
			    }
		if ( co == FALSE)
		    break;
			}
    i = 0;
    co = FALSE; 	
    return 0;
}

static void hello( GtkWidget *widget, gpointer   data )
{   
    if (co != TRUE){
	x = strtod (gtk_entry_get_text(GTK_ENTRY(e1)),NULL);
	y = strtod (gtk_entry_get_text(GTK_ENTRY(e2)),NULL);
	z = strtod (gtk_entry_get_text(GTK_ENTRY(e3)),NULL);
	w = strtod (gtk_entry_get_text(GTK_ENTRY(e4)),NULL);
	q = atoi (gtk_entry_get_text(GTK_ENTRY(e5)));	
	strcpy(wynik,"");
	strcpy(b,"");
	co = TRUE;
	gdk_threads_add_timeout (100, update_PB, PB);
	pthread_create (&on, NULL, argument_thread,NULL);	
	gtk_button_set_label (GTK_BUTTON(butt),"Stop");   
    }else{		
	co = FALSE;
	gtk_button_set_label (GTK_BUTTON(butt),"Licz"); 
	}

}

static gboolean delete_event( GtkWidget *widget, GdkEvent  *event,gpointer   data )
{
    gtk_main_quit ();
    return TRUE;
}

static void destroy( GtkWidget *widget, gpointer   data )
{
    gtk_main_quit ();
}

void dod1 (const char m[],GtkWidget *b){
    GtkWidget *h;
    h = gtk_cell_view_new_with_text(m);
    gtk_box_pack_start (GTK_BOX(b), h, TRUE, TRUE, 10);
    gtk_widget_show (h);
}

void dod2 (GtkWidget* *h,const char m[],GtkWidget *b){	
    *h = gtk_entry_new();
    gtk_box_pack_start (GTK_BOX(b), *h, TRUE, TRUE, 10);
    gtk_entry_set_text( GTK_ENTRY(*h),m);
    gtk_widget_show (*h);}

int main( int argc,char *argv[] )
{ 
//inicjacja
    g_thread_init (NULL);
    gdk_threads_init ();
    gtk_init (&argc, &argv);
//okno
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);    
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_show (window);
//pudla  
    box = gtk_vbox_new (FALSE,0);
    gtk_container_add (GTK_CONTAINER (window), box);
    gtk_widget_show(box);
    box2 = gtk_hbox_new (FALSE,0);
    gtk_box_pack_start (GTK_BOX(box), box2, TRUE, TRUE, 10);
    gtk_widget_show(box2);
    box3 = gtk_hbox_new (FALSE,0);
    gtk_box_pack_start (GTK_BOX(box), box3, TRUE, TRUE, 10);
    gtk_widget_show(box3);
//edity i opisy
    dod1(" x = ",box2);
    dod2(&e1,"1,2",box2);
    dod1(" y = ",box2);
    dod2(&e2,"2,3",box2);
    dod1(" z = ",box2);
    dod2(&e3,"3,4",box2);
    dod1(" w = ",box3);
    dod2(&e4,"55,5",box3);
    dod1("a,b,c (0,max) max = ",box3);
    dod2(&e5,"1000",box3);   
    l = gtk_label_new("w = (x * a) + (y * b) + (z * c)");
    gtk_box_pack_start (GTK_BOX(box), l, TRUE, TRUE, 10);
    gtk_widget_show (l);
//progressbar
    PB = gtk_progress_bar_new();
    gtk_box_pack_start (GTK_BOX(box), PB, TRUE, TRUE, 10);
    gtk_widget_show (PB); 
//przycisk
    butt = gtk_button_new_with_label ("Licz");
    gtk_box_pack_start (GTK_BOX(box), butt, TRUE, TRUE, 10);
    gtk_widget_show (butt);  
//wynik
    BUF = gtk_text_view_new();
    gtk_widget_set_size_request (BUF,100,100);
    gtk_widget_show (BUF);
    p3 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(BUF));    
    GtkObject  *vadj;
    vadj = gtk_adjustment_new(0.0, 0.0, 1.0, 0.01, 0.1, 0.1);
    sw = gtk_scrolled_window_new(GTK_ADJUSTMENT(vadj),NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(sw),
		    GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    gtk_container_add (GTK_CONTAINER (sw), BUF);
    gtk_box_pack_start (GTK_BOX(box), sw, TRUE, TRUE, 10);
    gtk_widget_show (sw);
//sygnaly
    g_signal_connect (window, "delete-event",G_CALLBACK (delete_event), NULL);
    g_signal_connect (window, "destroy",G_CALLBACK (destroy), NULL);
    g_signal_connect (butt, "clicked",G_CALLBACK(hello), NULL);
//sterowanie
	
    gdk_threads_enter ();
    gtk_main ();     
    gdk_threads_leave ();
    
    return 0;
}
