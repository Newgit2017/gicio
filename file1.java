import java.applet.Applet;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Event;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
 
public class Gwiazda extends Applet 
{
    int bok;
    Label Bok = new Label("Bok: ");
    TextField Bokt = new TextField(5);
    Button wykonaj = new Button("Wykonaj");
     
    public void init(){
        setBackground(new Color(100,200,100));
        Panel panel = new Panel();
        panel.setLayout(new GridLayout(3, 1));
        panel.add(Bok);
        panel.add(Bokt);
        panel.add(wykonaj);
        setLayout(new BorderLayout());
        add(BorderLayout.NORTH, panel);
    }
    public boolean action(Event evt, Object arg) 
    {
        if (evt.target == wykonaj) 
        {
            bok=Integer.parseInt(Bokt.getText().substring(0,Bokt.getText().length()));
            Graphics g = getGraphics();
            int temp = 300+(bok/3);
            g.drawLine(100,300,100+bok,300);
            g.drawLine(100,300,100+(bok/2),300+(bok/2));
            g.drawLine(100+bok,300,(100+bok)-(bok/2),300+(bok/2));
            g.drawLine(100,temp,100+bok,temp);
            g.drawLine(100,temp,100+(bok/2),temp-(bok/2));
            g.drawLine(100+bok,temp,(100+bok)-(bok/2),temp-(bok/2));
        }
        return true;
    }
}