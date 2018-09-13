import java.util.*;
import java.io.*;

/*
 * Klasa główna implementuje przede wszystkim interfejs użytkownika posługując się 
 * obiektem typu 'ArrayList' do przechowywania danych oraz obiektami 'dzialka' reprezentującymi
 * przechowywane informacjie
 */
class baza
{ 
	
	public static void main(String args[]) 
	{  
	//obiekty do obsługi we/wy
	InputStreamReader input = new InputStreamReader(System.in);
	BufferedReader reader = new BufferedReader(input); 
	
	//do pobierania nazwy pliku
	String nazwa="";
	
	//do obsługi interfejsu
	int x='0',y='0';
	
	//obiekt implementujacy liste
	AbstractList<dzialka> lista = new ArrayList<dzialka>() ; 
		
	System.out.println("Witaj w bazie danych Marcina Nowaka (9364) na temat działek (5) [nietamten@gmail.com]");

	//petla "menu"
	do
	{
		System.out.println(" Menu:");
		System.out.println("1. Dodaj dane do bazy");
		System.out.println("2. Usuń dane z bazy");
		System.out.println("3. Wyświetl zawartość bazy");
		System.out.println("4. Zapisz/Odczyt z/do pliku");
		System.out.println("5. Zakończ program");

		try {x= Integer.parseInt(reader.readLine());}
		catch (IOException e) {System.out.println("Blad we/wy");}
		catch (NumberFormatException e){System.out.println("Niepoprawny numer opcji");};

		switch (x) {
		case 1 : {	
					System.out.println("Sposób wprowadzenia danych:");
					System.out.println("1. Losowanie");
					System.out.println("2. Z klawiatury");
					try {y=(char)System.in.read(); System.in.skip(99);}
					catch (IOException e){System.out.println("Blad we/wy");}
					if (y=='1')
						lista.add(new dzialka(true)); else
						lista.add(new dzialka(false));
					};break;
		case 2 : {
					System.out.println("Którą działkę usunąć?");
					try {y=Integer.parseInt(reader.readLine());}
					catch (IOException e) {System.out.println("Blad we/wy");};
					lista.remove(y-1);
					};break;
		case 3 : {
					for(int i=0; i<lista.size(); i++)
						{
						System.out.println("\n==DZIALKA NR:"+(Integer.toString(i+1))+"==");
						lista.get(i).pokaz();	
						}
					};break;
		case 4: {	
					System.out.println("Podaj nazwę pliku");
					try {nazwa = reader.readLine();}
					catch (IOException e) {System.out.println("Blad we/wy");}
					
					System.out.println("Chcesz:");
					System.out.println("1. Pisac");
					System.out.println("2. Czytac");
					System.out.println("3. Nic nie chce");
					
					try {y=Integer.parseInt(reader.readLine());}
					catch (IOException e) {}
					catch (NumberFormatException e){System.out.println("Niepoprawny numer działki");};
					
					switch (y) {
					case 1 : {
								try{BufferedWriter plik = new BufferedWriter(new FileWriter(nazwa));

								for(int i=0; i<lista.size(); i++)
									lista.get(i).w_plik(plik);

								plik.close();
								}
								catch (IOException e){System.out.println("Blad we/wy");};					
							};break;
					case 2 : {
								try{BufferedReader plik = new BufferedReader(new FileReader(nazwa));
							
								while(true)
									try {lista.add(new dzialka(plik));}
									catch (IOException e){plik.close();System.out.println("Blad we/wy"); break;};
					
								}
								catch (IOException e){System.out.println("Blad we/wy");};
							};break;
								}
					};break;
					
		};		
						
		}while ( x != 5);			
						 	
};}

/* Klasa implementuje działkę jako strukture danych z obsługującymi ją metodami
 * wszystkie pola są prywatne
 */
class dzialka
{
	//pola przechowujące informacje o działce oraz zmienne pomocnicze
	private int numer,powierzchnia,wartosc, tmp;
	private String imienaz="", rodzaj="", tmps="" ;
	private boolean altanka, studnia;
	
	//generator losowy
	private Random x;
	
	//obsługa we/wy
	private InputStreamReader input = new InputStreamReader(System.in);
	private BufferedReader reader = new BufferedReader(input); 
	
	//zapisuje wszystkie pola do pliku
	public void w_plik (BufferedWriter wpl)
	{
	try{	
		wpl.write(imienaz+"\n");
		wpl.write(rodzaj+"\n");
		wpl.write(Integer.toString(numer)+"\n");
		wpl.write(Integer.toString(powierzchnia)+"\n");
		wpl.write(Integer.toString(wartosc)+"\n");
		if (altanka == true ) wpl.write("1"+"\n"); else  wpl.write("0"+"\n");
		if (studnia == true ) wpl.write("1"+"\n"); else  wpl.write("0"+"\n");
		}
	catch (IOException e){System.out.println("Blad we/wy");};
	}

	//wyswietla wszystkie pola
	public void pokaz ()
	{
		System.out.println("Imie i nazwisko:"+imienaz);
		System.out.println("Rodzaj:"+rodzaj);
		System.out.println("Numer:"+ Integer.toString(numer));
		System.out.println("Powierzchnia:"+ Integer.toString(powierzchnia));
		System.out.println("Wartość:"+Integer.toString(wartosc));
		if (altanka == true) System.out.println("Ma altanke");
		if (studnia == true) System.out.println("Ma studnie");
	}
	
	//konstruktor czytający wartości pól z pliku, z założenia wyjątek kończy działanie
	public dzialka (BufferedReader wpl) throws IOException 
	{ 
	try{	
		imienaz=wpl.readLine();
		if (imienaz==null){throw new IOException("Blad we/wy"); }
		rodzaj=wpl.readLine();
		numer=Integer.parseInt(wpl.readLine());
		powierzchnia=Integer.parseInt(wpl.readLine());
		wartosc=Integer.parseInt(wpl.readLine());
		tmps=wpl.readLine();
		if (Integer.parseInt(tmps) == 1 ) altanka=true; else  altanka=false;
		tmps=wpl.readLine();
		if (Integer.parseInt(tmps) == 1  ) studnia=true; else  studnia=false;
		}
	catch (IOException e){throw new IOException("Blad we/wy");};
	}

	//konstruktor który dla parametru true wypelnia pola losowymi danymi 
	//a dla parametru false pobiera dane od użytkownika
	public dzialka (boolean what)
	{
 	if (what)
	{	
		x = new Random();
		imienaz = Long.toString(Math.abs(x.nextLong()), 36);
		rodzaj = Long.toString(Math.abs(x.nextLong()), 36);
		numer = x.nextInt(999);
		powierzchnia = x.nextInt(9999);
		wartosc = x.nextInt(999999);
		altanka = x.nextBoolean();
		studnia = x.nextBoolean();
	} else 
	try {
			System.out.println("Pobieranie z klawiatury");
			System.out.println("Imie i nazwisko:");
			imienaz = reader.readLine();
			System.out.println("Rodzaj:");
			rodzaj = reader.readLine();
			System.out.println("Numer:");
			tmps = reader.readLine();
			numer=Integer.parseInt(tmps);
			System.out.println("Wartość:");
			tmps = reader.readLine();
			wartosc=Integer.parseInt(tmps);
			System.out.println("Powierzchnia:");
			tmps = reader.readLine();
			powierzchnia=Integer.parseInt(tmps);
			System.out.println("Czy ma altanke t/n");
			tmp =System.in.read(); System.in.skip(99);
			if (tmp == 't') altanka = true; else altanka = false;
			System.out.println("Czy ma studnie t/n");
			tmp =System.in.read(); System.in.skip(99);
			if (tmp == 't') studnia = true; else studnia = false;
			}catch (IOException e) {System.out.println("Blad we/wy");}
			catch (NumberFormatException e) {System.out.println("Niepoprawne dane");}
		};			
}