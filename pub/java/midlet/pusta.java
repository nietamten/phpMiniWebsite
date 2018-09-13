import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.Form;

//klasa napisana w celu zredukowania powtarzającego się kodu
//dziedziczy po ekranie i implementuje obsluge klawiatury
//w taki sposób aby możliwe było po stworzeniu obiektu
//i przelaczeniu go jako aktualny ekran za pomocą przycisku
//wstecz wrocic do poprzedniego ekranu
//klasa bardzo ułatwia pisanie wieloekranowego gui
public class pusta extends Form implements CommandListener {

	private Command cm1 = new Command("Wstecz",Command.BACK,0);
	private Command cm2 = new Command("Ukryj",Command.BACK,0);
	private Displayable pop;
	private Display wys;
	
	//konstruktor potrzebuje jako parametrów:
	//tytułu nowego ekranu, wyswietlacza, poprzedniego ekranu oraz
	//zmiennej typu boolean ktora zmienia etykiete przycisku
	//gry true - ukryj gdy false - wstecz
	public pusta(String title,Display wys, Displayable pop,boolean ukryj) {
		super(title);
		this.pop=pop;
		this.wys=wys;
		if (ukryj)
			addCommand(cm2);
		else
			addCommand(cm1);
		this.setCommandListener(this);
	}

	//obsługa klawiatury zakłada tylko przycisk wstecz/ukryj
	public void commandAction(Command arg0, Displayable arg1) {
		if (arg0 == cm1 || arg0 == cm2)
		wys.setCurrent(pop);
	}

}
