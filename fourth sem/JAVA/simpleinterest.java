//WAP in java to calculate simple interest and display it when the user enters the principle, rate and time.

/* 
package practice;

public class simpleinterest {
    double principle = 50000, rate = 3.5 , time = 3  ;  //initialization
    double Simple_Interest = (principle*rate*time)/100;
    
    public static void main(String args[])  {
    simpleinterest t = new simpleinterest ();   // here the t is a reference variable and new simpleinterest() creates new instance of a classs
    System.out.println("The simple interest is calculated as: "+ t.Simple_Interest);
}
}
*/

package practice;
import java.util.Scanner; 

public class simpleinterest {
    
    public static void main(String args[])  {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
        
        System.out.println("Enter the principle amount: ");
        double principle= scanner.nextDouble(); // to read the  user input 

        System.out.println("Enter the rate of interest: ");
        double rate= scanner.nextDouble(); 
        
        System.out.println("Enter the time periods(years): ");
        double time= scanner.nextDouble(); 
        
        scanner.nextLine();// to read the other line after decimal number

        double Simple_Interest = (principle*rate*time)/100;

        System.out.println("The simple interest is calculated as: "+ Simple_Interest);
        scanner.close();
}
}