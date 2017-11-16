import java.applet.Applet;
import java.awt.Color;
import java.awt.Event;
import java.awt.Graphics;
 
public class Lamana extends Applet 
{
    int xpoint;
    int ypoint;
 
    public void init()
    {
        setBackground(Color.BLACK);
    }
 
    public boolean mouseDown(Event e, int x, int y) 
    {
        Graphics g = getGraphics();
        if(xpoint==0&ypoint==0)
        {
            xpoint = x;
            ypoint = y;   
        }
        else
        {
            g.setColor(Color.white);
            g.drawLine(x,y,xpoint,ypoint);
            xpoint = x;
            ypoint = y;
        }
        return true;
    }
}