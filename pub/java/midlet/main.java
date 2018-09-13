import javax.microedition.lcdui.Alert;
import javax.microedition.lcdui.AlertType;
import javax.microedition.lcdui.Choice;
import javax.microedition.lcdui.ChoiceGroup;
import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.Form;
import javax.microedition.lcdui.List;
import javax.microedition.lcdui.TextField;
import javax.microedition.midlet.MIDlet;
import javax.microedition.rms.RecordEnumeration;
import javax.microedition.rms.RecordStore;
import javax.microedition.rms.RecordStoreException;
import javax.microedition.rms.RecordStoreFullException;
import javax.microedition.rms.RecordStoreNotFoundException;

//klasa główna
public class main extends MIDlet implements CommandListener {
  
	  //ścieżki do skryptów CGI dostępnych na serwerze
	  private static String	skrPerl="/cgi-bin/perl/q.pl";
	  private static String	skrSh="/cgi-bin/sh/q.sh";
	
  //obsluga interfejsu użytkownika
  
	//ekran z ustawieniami połżczenia
	private Form myF;
	//zmienna do której pobierany jest wskaźnik na obiekt wyświetlacza
	private Display dis;
 
	//deklaracje komend obsługiwanych przez CommandListenera
	private Command cm1 = new Command("Zakończ",Command.EXIT,0); 
 	private Command cm2 = new Command("Dalej",Command.OK,0); 
	private Command cm3 = new Command("Wstecz",Command.BACK,0); 
	private Command cm4 = new Command("Wybierz",Command.OK,0);
  
	//deklaracja pól edycyjnych ekranu połączania
	private TextField  t[] = new TextField[4];
 
	//deklaracje ChoiceGroup'ów oraz list dostępnych opcji
	private ChoiceGroup q;  
	String[] proto = { "HTTPS", "HTTP"};
  
	private ChoiceGroup w;
	String[] nietak = { "TAK", "NIE"};
  
  	//deklaracja listy funkcjonalności 
	private List lista;
	//deklaracja listy wszystkich funkcjonalności 
	private String[] list = {
		  "Ping",
		  "DNS Lookup",
		  "Trace Roure",
		  "ARP Watch (pasywny)"
		  ,"Skaner ARP (aktywny)",
		  "Skaner NetBIOS",
		  "Informacje o interfejsach",
		  "Edycja interfejsów",
		  "Wykonaj polecenie",
		  "WakeOnLan",
		  "Reset"
	};
  
  //obsluga RMS
  private RecordStore rs = null;
  private RecordEnumeration rsE = null;
  private byte bajty[] = null;
  
  //konstruktor superklasy
  public main(){
    super();
  }

  //uruchamiane przy starcie aplikacji
  public void startApp(){
	
	  //kopiuje wskaznik na obiekt wyswietlacza
	  dis = Display.getDisplay(this);
	
	
	  //tworzy 'ekran'
	  myF = new Form("Połączenie");
	
	//tworzy wceśniej zadeklarowane elementy gui
    t[0] = new TextField("Nazwa serwera:","ble.dnsalias.net", 100, TextField.ANY);    
    t[1] = new TextField("Użytkownik:","admin", 100, TextField.ANY);
    t[2] = new TextField("Hasło:","abc123", 100, TextField.PASSWORD);
    q = new ChoiceGroup("Protokół", ChoiceGroup.POPUP, proto,null);
    w = new ChoiceGroup("Autoryzacja", ChoiceGroup.POPUP, nietak,null);
    
    //dodaje do ekranu
    for (int i=0;i<3;i++){myF.append(t[i]);}
    myF.append(q);
    myF.append(w);
    
    //ustawia ekran polaczenia jako aktualnie wyswietlony
	dis.setCurrent(myF);
	
	//dodaje obsługę komend i dodaje komendy
  	myF.setCommandListener(this);
	myF.addCommand(cm1);
    myF.addCommand(cm2);

    //obsluga rms - odczytaj jesli sa zapisane, jesli nie zapisz defaultowe
    try {
		
   		rs = RecordStore.openRecordStore("LANMgrData",true);
		rs.enumerateRecords(null, null, true);
		
		if (rs.getNumRecords()==0)
		{
			for (int i=0;i<3;i++){
				bajty=t[i].getString().getBytes();
				rs.addRecord(bajty,0,bajty.length);
			} 
		}else{
			for (int i=0;i<3;i++){
			     bajty = rs.getRecord(i+1);
			     t[i].setString(new String(bajty,0,bajty.length));
				}
		}

		rs.closeRecordStore();
		
		} catch (RecordStoreFullException e) {
		dis.setCurrent(new  Alert("Błąd RMS: pemięć pełna", "Ustawienia nie zostną zpisane", null, AlertType.ERROR )); 
			e.printStackTrace();
		} catch (RecordStoreNotFoundException e) {
			dis.setCurrent(new  Alert("Błąd RMS: błąd pamięci", "Ustawienia nie zostną odczytane", null, AlertType.ERROR ));
			e.printStackTrace();
		} catch (RecordStoreException e) {
			dis.setCurrent(new  Alert("Błąd RMS: błąd pamięci", "Ustawienia nie zostną zpisane/odczytane", null, AlertType.ERROR ));
			e.printStackTrace();
		}

  }

  //wykonywane przy zakończeniu aplikacji
  public void destroyApp(boolean unconditional){
	  notifyDestroyed();
  }
  
  //wykonywane przy naciśnieciu przycisku
  public void commandAction(Command c, Displayable s){

	  //PRZYCISK przejscia DALEJ do listy
	  if (c==cm2)
	  {			
		//obsluga rms - odczytaj jesli sa zapisane, jesli nie zapisz defaultowe
			try {
				rs = RecordStore.openRecordStore("LANMgrData",false);
				for (int i=0;i<3;i++){
				bajty=t[i].getString().getBytes();
				rs.setRecord(i+1,bajty,0,bajty.length);
				}

				rs.closeRecordStore();
				
			} catch (RecordStoreFullException e) {
				dis.setCurrent(new  Alert("Błąd RMS: pemięć pełna", "Ustawienia nie zostną zpisane", null, AlertType.ERROR )); 
					e.printStackTrace();
				} catch (RecordStoreNotFoundException e) {
					dis.setCurrent(new  Alert("Błąd RMS: błąd pamięci", "Ustawienia nie zostną zpisane/odczytane", null, AlertType.ERROR ));
					e.printStackTrace();
				} catch (RecordStoreException e) {
					dis.setCurrent(new  Alert("Błąd RMS: błąd pamięci", "Ustawienia nie zostną zpisane/odczytane", null, AlertType.ERROR ));
					e.printStackTrace();
				}
			
		        lista = new List("Funkcjonalnosci", Choice.IMPLICIT, list,null);
		        lista.addCommand(cm3);
		        lista.addCommand(cm4);
		        lista.setCommandListener(this);
		        dis.setCurrent(lista);
				 					
	  }
		
	  //PRZYCISK ZAMKNIECIA aplikacji
	  if (c==cm1)
	  {
		  this.notifyDestroyed();
		  this.destroyApp(true);	
	  }
	  
	  //PRZYCISK powrotu, WSTECZ z listy funkcjonalnosci
	  if (c==cm3) {dis.setCurrent(myF);}
	  
	  
	  //PRZYCISK WYBIERZ przekazujacy ekran obiektowi dziedziczacemu po proc
	  if (c==cm4 || c == List.SELECT_COMMAND)
	  { 
		  //pobiera z listy nazwe wybranej funkcji
		  String co = lista.getString(lista.getSelectedIndex());
		  
		  //zmienna w ktorej tworze adres
		  StringBuffer	adrB = new StringBuffer();
		  
		  //w zalezności od wybranego protokołu dopisuje do adresu...
		  if (q.getString(q.getSelectedIndex())=="HTTPS")
			  adrB.append("https://");
		  
		  if (q.getString(q.getSelectedIndex())=="HTTP")
			  adrB.append("http://");
		  
		  //dopisuje do adresu podaną w polu edycyjnym nazwę hosta
		  adrB.append(t[0].getString());

		  //dodaję do adresu ścieżkę do skryptu CGI który obsługuje daną funkcjonalność
		  if (co != "wykresy")		  
			  adrB.append(skrPerl);
		  else
			  adrB.append(skrSh);
		  
		  //konwertuje adres do stringa
		  String adr = adrB.toString();
		  
		  //tworze zmienna tymczasowo przechowującom informacje do autoryzacji
		  String auth;

		  //jeżeli wybrano opcję używania autoryzacji 
		  //zapisuje do zmiennej auth dane z pól edycujnych (haslo i login)
		  //zapisywane są one w formacie akceptowanym przez skrypty CGI
		  if (w.getString(w.getSelectedIndex())=="TAK"){
		
			  adrB = new StringBuffer();
			  adrB.append("USER=");
			  adrB.append(t[1].getString());
			  adrB.append("&PASS=");
			  adrB.append(t[2].getString());
			  adrB.append("&");
			  
			  auth = adrB.toString();  
		  }
		  else
			  auth = null;
		  	
		  
		  
		  //w zależności od wybranej funkcjonalności tworze obiekt który ją udostępnia
		  //przekazując w parametrze obiekt wyswietlacza, ekran z lista funkcjonalnosc
		  //(aby umożliwić wycofanie się zpowrotem do tego ekranu)
		  //dane do autoryzacji oraz URL potrzebny do połączenia
		  if (co == "Ping"){
			new p11(dis,lista,auth,adr);
		  }
		  if (co == "DNS Lookup"){
			new p12(dis, lista, auth, adr);				
			  }
		  if (co == "Trace Roure"){
			new p13(dis, lista, auth,adr);
			  	}
		  if (co == "ARP Watch (pasywny)"){
			new p15(dis, lista, auth,adr);				
			  }
		  if (co == "Skaner ARP (aktywny)"){
			new p14(dis, lista, auth, adr);				
			  }
		  if (co == "Skaner NetBIOS"){
			 new p16(dis, lista, auth,adr);
		  	}				 	
		  if (co == "Informacje o interfejsach"){
			 new p18(dis, lista, auth,adr);
			  	}
		  if (co == "Edycja interfejsów"){
			 new p19(dis, lista, auth,adr);
			  	}
		  if (co == "WakeOnLan"){
				 new p32(dis, lista, auth,adr);
			  	}
		  if (co == "Reset"){
				 new p31(dis, lista, auth,adr);
			  	}
		  if (co == "Wykonaj polecenie"){
				 new p120(dis, lista, auth,adr);
			  	}
		  
	  }
}


protected void pauseApp() {

}

public RecordEnumeration getRsE() {
	return rsE;
}
  
  
}