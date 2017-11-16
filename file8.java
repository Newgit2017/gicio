import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;
 
public class ZgadnijLiczbe 
{
    /**
     * @param args
     * @throws IOException 
     * @throws NumberFormatException 
     */
    public static void main(String[] args) throws NumberFormatException, IOException 
    {
        // TODO Auto-generated method stub
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        boolean wynik = false;
        int ktory_raz=1;
        Random rand = new Random();
        int liczba = rand.nextInt(100);
        while (wynik==false)
        {
            System.out.print("Wprowad� liczb� z zakresu 0-100: ");
            int zgadnij = Integer.parseInt(reader.readLine());
            if(zgadnij==liczba)
            {
                System.out.println("Znalaz�e� szukan� liczb�!!!");
                wynik=true;
            }
            else if (zgadnij>liczba)
            {
                System.out.println("Poda�e� wi�ksz� liczb�.");
                wynik=false;
                ktory_raz++;
            }
            else if (zgadnij<liczba)
            {
                System.out.println("Poda�e� mniejsz� liczb�.");
                wynik=false;
                ktory_raz++;
            }
        }
        System.out.println("Zgad�e� za "+ktory_raz+" razem.");
    }
}