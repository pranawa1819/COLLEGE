package practice;
import java.util.Scanner;
public class SI {
    // instance variable
    double principle;
    double rate;
    double time;

    public SI(){
        //default constructor
    }

    public SI(double p, double r, double t){   //parameterized constructor
      principle = p;
      rate = r;
      time = t;
    }

    public void interest(){   // to take input from user
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the principle amount: ");
        principle = scan.nextDouble();
        System.out.println("Enter the rate of interest: ");
        rate = scan.nextDouble();
        System.out.println("Enter the number of years: ");
        time = scan.nextDouble();
        scan.close();

    }
     
    public void printInterest(){     //to print the result
        double simple_interest = (principle*rate*time)/100;
        System.out.println("The total interest is : "+ simple_interest);
    }

    public static void main(String args[]){
        SI s1 = new SI();  //object
        s1.interest();
        s1.printInterest();
    }

}
