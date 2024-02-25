package practice;
import java.util.Scanner;
public class sumOfOddandEven {

    public static void main(String args[]){
        
            Scanner scan = new Scanner(System.in);
           
            int SumofOddnumber = 0;
            int sumOFevennumber = 0;
           
            for(int i = 1; i<100;i++){
           
            if(i %2 == 0){
                sumOFevennumber += i;
            }
            else{
                SumofOddnumber +=i;
            }
            }
            System.out.println("The sum of even number is : "+sumOFevennumber);
            System.out.println("The sum of odd number is : "+SumofOddnumber);
            scan.close();
    }
}
