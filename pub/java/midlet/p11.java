import javax.microedition.lcdui.Alert;
import javax.microedition.lcdui.AlertType;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.StringItem;
import javax.microedition.lcdui.TextField;

//funkcjonalność PING
public class p11 extends proc {

	private StringItem item;
	private TextField t;
	
	public p11(Display d, Displayable f, String tyt, String adres) {
		super(d, f, tyt, adres);	
	
		t = new TextField("adres: ","127.0.0.1", 100, TextField.ANY);
				
		F.setTitle("Ping");
		item = new StringItem("Stan:","...");
		F.append(t);
		F.append(item);
	}
	
			public void run() {
				m=wez("&CODE=11&URL="+t.getString());
				if (m == null){
					d.setCurrent(new  Alert("Błąd połączenia: ", "połączenie nie zostanie zrealizowane", null, AlertType.ERROR ));
					return;
				}
				if (m != null && m.toString() != "")
				item.setText(m.toString());
				else
					item.setText("BŁĄD");	
			}
	
}
