//WAP in java to calculate the area and perimeter of a circle, when the user enters the radius.

package practice;
import java.util.Scanner; 

public class Pmeter {
static  double pie = 3.14; 

    
    public static void main(String args[])  {
        
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
        
        System.out.println("Enter the radius of a circle: ");
        double radius = scanner.nextDouble(); // to read the  user input 
        
        scanner.nextLine();// to read the other line after decimal number
         
        double AreaOfCircle = pie*radius*radius;
        double PerimeterOfCircle = 2*pie*radius;
        
        System.out.println("The area of a circle is: "+ AreaOfCircle);
        System.out.println("The perimeter of a circle is: "+ PerimeterOfCircle);
        scanner.close();// Close the scanner to prevent resource leaks
}
}