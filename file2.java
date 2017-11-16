import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
 
public class AppletRuch extends Applet implements Runnable 
{
    private int m_X = 60, m_Y = 0, m_oldX, m_oldY;
    private Thread wateczek;
 
    public void init() 
    {
        setBackground(Color.black);
        m_oldX = m_X;
        m_oldY = m_Y;
    }
 
    public void start() 
    {
        if (wateczek == null)
            wateczek = new Thread(this, "Rysownik");
        wateczek.start();
    }
 
    public void stop() 
    {
        if (wateczek != null)
        {
            wateczek.stop();
            wateczek = null; 
        }
    }
 
    public void run() 
    {
        boolean gora = false;
        while (Thread.currentThread() == wateczek) 
        {
            if(m_Y < 0)
            m_Y=101;
            m_Y--;
            repaint();
            try
            {
                Thread.sleep(50);
            } 
            catch(InterruptedException ex) 
            {}
        }
    }
 
    public void paint(Graphics g) 
    {
        update(g);
    }
     
    public void update(Graphics g) 
    {
        if ((m_oldX != m_X) | (m_oldY != m_Y)) 
        {
            g.setColor(Color.black);  
            g.drawRect(40,m_oldY,180,60);
            g.fillRect(40,m_oldY,180,60);
            g.drawRect(40,m_oldY+60,180,60);
            g.fillRect(40,m_oldY+60,180,60);
            m_oldY = m_Y;
        }
        g.setColor(Color.white);
        g.drawRect(40,m_Y,180,60);
        g.fillRect(40,m_Y,180,60);
        g.setColor(Color.red);
        g.drawRect(40,m_Y+60,180,60);
        g.fillRect(40,m_Y+60,180,60);
        g.setColor(Color.white);
    }
}