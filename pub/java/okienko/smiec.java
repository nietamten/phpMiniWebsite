import java.awt.image.BufferedImage;
import java.util.Random;
import java.io.File;

import javax.imageio.ImageIO;

	public class smiec {//extends Thread{
		public int x,y,Fx,Fy,r;
		BufferedImage img = null;
		Random ra = new Random();
		
		smiec (String imgn){
			x=ra.nextInt(700);
			y=ra.nextInt(700);
			Fx=(ra.nextInt(10))-5;
			Fy=(ra.nextInt(10))-5;			
			try {img = ImageIO.read(new File(imgn));}
			catch(Exception ex){}
		}
}