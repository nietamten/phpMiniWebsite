import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.net.URL;
import javax.imageio.ImageIO;
import java.io.IOException;

public class cos extends Applet implements Runnable
{
private static final long serialVersionUID = 1L;
private Image img,off;
private int x=44,y=55,Vx=1,Vy=1;
private boolean q = true;
private Thread Fred1;
private Graphics gr;

     public void init()
     {	  
    	 try {
    		     URL url = new URL(getCodeBase(), "zdjecie.jpg");
	             img = ImageIO.read(url);
	         } catch (IOException e) {System.out.println("Nie moge przeczytac pliku");}
			
	    off= createImage(400, 200);
	    gr = off.getGraphics();
        gr.drawImage(img, 200, 0, this);
		q=true;
    	Fred1 =  new Thread(this); 
    	Fred1.start();
     }

     public void stop()
     {
    	 q=false;
     }

     public void update(Graphics g)
     {   	
    	 gr.setColor(Color.yellow);
    	 gr.fillRect(0, 0, 200, 200);
    	 gr.setColor(Color.black);
    	 gr.drawString("Costam napisane ble",40,90);
         gr.drawString("costam ble ble ble",40,110);
         gr.setColor(Color.red);
         gr.drawOval(x, y, 10, 10);
         g.drawImage(off, 0, 0, this);
    }

	public void run() {
		while(q){
		if(x>185 || x<0) Vx*=-1;
		if(y>185 || y<0) Vy*=-1;
		if((y==70 || y==110) && x>30 && x<135)Vy*=-1;
		if((x==30 || x==135) && y>70 && y<110)Vx*=-1;
		x+=Vx;
		y+=Vy;
    	repaint();
    	
    	try{Thread.sleep(10);} catch( InterruptedException e ) 
    	{System.out.println("Błąd przerwania działania wątku");}		
		}
     }
}
  
