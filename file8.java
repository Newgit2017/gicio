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
            System.out.print("WprowadŸ liczbê z zakresu 0-100: ");
            int zgadnij = Integer.parseInt(reader.readLine());
            if(zgadnij==liczba)
            {
                System.out.println("Znalaz³eœ szukan¹ liczbê!!!");
                wynik=true;
            }
            else if (zgadnij>liczba)
            {
                System.out.println("Poda³eœ wiêksz¹ liczbê.");
                wynik=false;
                ktory_raz++;
            }
            else if (zgadnij<liczba)
            {
                System.out.println("Poda³eœ mniejsz¹ liczbê.");
                wynik=false;
                ktory_raz++;
            }
        }
        System.out.println("Zgad³eœ za "+ktory_raz+" razem.");
    }
}