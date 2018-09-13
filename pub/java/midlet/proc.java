import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;

import javax.microedition.io.Connector;
import javax.microedition.io.ContentConnection;
import javax.microedition.io.HttpConnection;
import javax.microedition.io.HttpsConnection;
import javax.microedition.lcdui.Alert;
import javax.microedition.lcdui.AlertType;
import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.Form;
import javax.microedition.lcdui.Gauge;
import javax.microedition.pki.CertificateException;

//klasa abstrakcyjna po której dzidziczą wszystkie klasy realizujące 
//jakąś funkcjonalność
//realizuje:
//- częściowo obsługę klawitury
//- obsługę połączenia w osobnym stworznym do tego celu wątku
//- GUI informujące o stanie połączenia
//- obsługę błędów połączenia
//- częściowo GUI funkcjonalności
abstract class proc implements CommandListener,Runnable {

	//komendy przycisków
	protected Command cm1 = new Command("Wstecz",Command.BACK,0); 
	protected Command cm2 = new Command("Zrob",Command.OK,0);
	
	//zmienne niezbędne do połączenia
    private ContentConnection hc;
	private InputStream is;
    private OutputStream os;
    
    //jezeli true to uzywa https, jesli nie http
    //ustalana przez konstruktor na podstawie URL'a
	private boolean ssl;
    
	//startowy ekran funkcjonalności
    protected Form F;
    //ekran informacji o stanie połączenia
	private	pusta Info;
	//ustalany przez konstruktor obiekt wyswietlacz
    protected Display d;
    //ustalany przez konstruktor poprzedni ekran
    protected Displayable f;
    //pasek postępu połączenia
    protected Gauge G;
    //zmienna na odebraną od serwera wiadomość
    protected StringBuffer m=null;
    //zmienna na wysyłaną wiadomość
    private StringBuffer In = null;
    //URL ustalany przez konstruktor
    protected String adres; 
    //pomocniczy bufor
    private StringBuffer InB;
    //dane do utoryzacji ustalane przez konstruktor
	protected String auth;
	
	
	//konstruktor kopiuje parametry do zmiennych i przelacza ekran na F
    public proc(Display d,Displayable f,String auth,String adres){
    	// kopiuje parametry
    	this.d=d;
    	this.f=f;  	
    	this.adres=adres;
    	this.auth=auth;
    	//ustalam zmienną ssl
    	ssl = adres.startsWith("https");
    	
    	//tworze nowy ekran a obsługą klawiatury
    	F= new Form("<<>>");
    	F.setCommandListener(this);
    	F.addCommand(cm1);
        F.addCommand(cm2);	

        //ustawiam aktualny ekran na F
	   	d.setCurrent(F);
    }

	//metoda wysyła parametr do serwera jako żądanie i zwraca odpowiedź
    //jeżeli błąd zwraca null
    //używa do połączenia zmiennych: adres, auth oraz ssl
    public StringBuffer wez(String Out){
		
    	int v = 0 ; //kod odpowiedzi serwera
				
    	try{
    		//TODO nie wszystkie wyjątki złapane
   	  	
    	System.out.println("-"+adres+"-");
    	G.setLabel("Połączenie:\n Otwieram połączenie");
		G.setValue(0);
		
		if (ssl){ 
			hc = (HttpsConnection) Connector.open(adres);
			((HttpsConnection) hc).setRequestMethod(HttpsConnection.POST);
		} else{
			hc = (HttpConnection) Connector.open(adres);  
			((HttpConnection) hc).setRequestMethod(HttpConnection.POST);
		}
			      		
		System.out.println("\nwyjscie");		
		G.setLabel("Połączenie:\n Otwieram wyjście");
		G.setValue(2);
		
			os = hc.openOutputStream(); 
			
		System.out.println("otwarto strumien wyjsciowy");		
		G.setLabel("Połączenie: Wysyłam żądanie");
		G.setValue(2);
		
		String d1;
		if (auth != null)
			d1=auth+Out;
		else
			d1=Out;
			
	    byte[] b = d1.getBytes();
		os.write(b);
		
		try{
		if(ssl)
		v= ((HttpsConnection) hc).getResponseCode();
		else
		v= ((HttpConnection) hc).getResponseCode();	
		
		}	catch (CertificateException e){
			d.setCurrent(new  Alert("Błąd połączenia: ", "nie zaakceptowano certyfikatu", null, AlertType.ERROR ));
			d.setCurrent(f);
			e.printStackTrace();
		}
		
		System.out.println(Integer.toString(v)+" wyslano: "+ d1);					
		G.setLabel("Połączenie:\n Otwieram wejście");
		G.setValue(2);
		
			is = hc.openInputStream(); 
			
		System.out.println("otwarto strumien wejsciowy");
		G.setLabel("Połączenie:\n Odbieram odpowiedź");
		G.setValue(5);
		
		InB = new StringBuffer();
		 int c;
		 while ((c = is.read()) != -1) InB.append((char)c);; 
		In=InB;
		
		System.out.println("odebrano: "+ In);
		G.setLabel("Połączenie:\n Zamykam połączenie");
		G.setValue(9);
		
				if (is != null) is.close();
				if (os != null) os.close();
				if (hc != null) hc.close();
				
		G.setLabel("Połączenie:\n Zamknięto połączenie");
		G.setValue(10);
		System.out.println("zamknieto polaczenie");		
		
	} catch (IOException e) {
		d.setCurrent(new  Alert("Błąd połączenia: ", "połączenie nie zostanie zrealizowane", null, AlertType.ERROR ));
		d.setCurrent(F);
		e.printStackTrace();
		return null;}

	
	
	d.setCurrent(F);
	System.out.println("zakonczono metode polaczenia");
	
	if (v == 200)
	return In;
	else
		return null;
	
    }

    //obsługa klawiatury dodaje przyciski 'wstecz' oraz 'zrob'
    //zazwyczaj nie jest koniecznie przedefinowywanie tej metody
	public void commandAction(Command c, Displayable s) {

		//WSTECZ wraca do listy funkcjonalnosci
			  if (c==cm1){ d.setCurrent(f);	}
			  
	    //ZROB uruchamia wątek
			  if (c==cm2){ 
			    	Info = new pusta("Czekaj",d,F,true);
			    	G = new Gauge(null, false, 10, 0);
			    	Info.append(G);				  
			    	d.setCurrent(Info); 
			    	
			    	new Thread(this).start();   
			    	}

}

	//przykładowy watek, powinien zostac przedefinoiwany
	public void run() {
		m=wez("CODE=0");
		F.append(m.toString());
	}
    
}


