
import java.awt.*;
import java.awt.event.*;
import java.awt.event.KeyEvent;


import javax.imageio.ImageIO;
import javax.swing.*;

import java.awt.image.BufferedImage;
import java.awt.image.ImageObserver;
import java.io.File;

public class kaboom extends JPanel implements KeyListener {
	
public final static JFrame myF= new JFrame("symulator rakiety");		
static int ile=10,zlo=3; //ile ma byc smieci
ImageObserver observer = new ImageObserver(){public boolean imageUpdate(Image image, int flags, int x, int y, int width, int height) {return true;}};
static smiec[] smieci;
static int wynik=0;

//konstruktor panela
public kaboom() {
	 myF.addKeyListener(this);
	 smieci = new smiec[ile+zlo];
	 smieci[0]=new smiec("rakieta.jpg");
	 int i;
	 for (i=1;i<ile;i++){
		 smieci[i]=new smiec("enemy.jpg");
	 }	 
	 for (i=smieci.length-zlo-1;i<smieci.length-1;i++){
		 smieci[i]=new smiec("szatan.jpg");
	 }	
}

static boolean lewo = false;
static boolean prawo = false;
static boolean gora = false;
static boolean dol = false;
static boolean fajer = false;

public void keyReleased ( KeyEvent e ){ 
	int a=e.getKeyCode();
	if (a==32)fajer = false;
	if (a==37)lewo = false; 
	if (a==39)prawo = false; 
	if (a==38)gora = false; 
	if (a==40)dol = false; 
}   
public void keyPressed ( KeyEvent e){  
	int a=e.getKeyCode();
	if (a==32)fajer = true;
	if (a==37)lewo = true; 
	if (a==39)prawo = true; 
	if (a==38)gora = true; 
	if (a==40)dol = true; 
}  

public void keyTyped ( KeyEvent e ){}      

//fred co przesuwa obrazki i spradza czy sie cos nie zderzylo
static Thread Fred1=new Thread(){
	public void run(){
		while (true){ 
			int i;
			for (i=0;i<ile+zlo;i++)
				if (smieci[i]!=null){
					smieci[i].x+=smieci[i].Fx;
					smieci[i].y+=smieci[i].Fy;
					if (smieci[i].y>700) smieci[i].y=0;
					if (smieci[i].x>700) smieci[i].x=0;
					if (smieci[i].y<-40) smieci[i].y=700;
					if (smieci[i].x<-40) smieci[i].x=700;
		
		//wykrywacz zderzen 
					if (i!=0){
						if (((smieci[i].x>=smieci[0].x-40) && (smieci[i].x<=smieci[0].x+40))&&
							((smieci[i].y>=smieci[0].y-40) && (smieci[i].y<=smieci[0].y+40)))
							{
								if (i<ile-1)
								{
									smieci[i]=null;dodaj();
									wynik++;
								}else
								{
									wynik=0;
								while(!fajer)try{Thread.sleep(100);} catch( InterruptedException e ) 
								{System.out.println("Interrupted Exception caught");}	
								smieci[0].x+=100;
								smieci[0].y+=100;
								}
							}
						}
				}
try{Thread.sleep(30);} catch( InterruptedException e ) 
{System.out.println("Interrupted Exception caught");}
	}
	}	
};

//fred co przerysowuje panel
static Thread Fred2=new Thread(){
	public void run()
	{
	while (true){ 
		myF.repaint(); 
try{Thread.sleep(20);} catch( InterruptedException e ) 
{System.out.println("Interrupted Exception caught");}
 	}
	}
	};
	
//fred co zmienia predkosc
static Thread Fred3=new Thread(){
	public void run()
	{
	while (true){ 
		
		if (lewo==true) smieci[0].Fx--;
		if (prawo==true) smieci[0].Fx++;
		if (gora==true) smieci[0].Fy--;
		if (dol==true) smieci[0].Fy++;

try{Thread.sleep(40);} catch( InterruptedException e ) 
{System.out.println("Interrupted Exception caught");}
 	}
	}
	};	

 public static void dodaj(){
	 int i;
	 for (i=0;i<ile-1;i++)
		 if (smieci[i]==null) break;
	 if (i<ile)
	 {
		smieci[i]=new smiec("nowy.jpg"); 
	 }
 }
 
   // rysuje panel z zawartoscia
   public void paint(final Graphics g) {
	   BufferedImage img = null;
	   try {img = ImageIO.read(new File("tlo.jpg"));}catch(Exception ex){}
	   g.drawImage(img,0,0, observer);
	   g.drawString(Integer.toString(wynik),0,0);
	   int i;
		 for (i=0;i<ile+zlo;i++){
			 if (smieci[i]!=null)
	   g.drawImage(smieci[i].img,smieci[i].x, smieci[i].y, observer);
		 }
		 g.drawString(Integer.toString(wynik),15,25);
   } 

   // glowna
   public static void main(final String[] args) {
      // tworzy okienko i dodaje panel (klase glowna)
      myF.add(new kaboom());
      myF.setSize(700, 700);
      myF.setVisible(true);
      myF.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

     Fred1.start();
     Fred2.start();
     Fred3.start();
   }
}
