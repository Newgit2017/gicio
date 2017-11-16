import java.applet.Applet;
import java.awt.Color;
import java.awt.Event;
import java.awt.Graphics;
 
public class Trojkat extends Applet 
{
    int xpoint;
    int ypoint;
    int xstart;
    int ystart;
    int i=0;
     
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
            xstart = x;
            ystart = y;
        }
        else if(i==1)
        {
            g.setColor(Color.white);
            g.drawLine(x,y,xpoint,ypoint);
            xpoint = x;
            ypoint = y;    
            g.setColor(Color.white);
            g.drawLine(xstart,ystart,xpoint,ypoint);
        }
        else
        {
            g.setColor(Color.white);
            g.drawLine(x,y,xpoint,ypoint);
            xpoint = x;
            ypoint = y;
            i++;
        }
        return true;
    }
}