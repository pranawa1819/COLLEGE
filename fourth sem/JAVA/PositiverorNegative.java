package practice;

import java.util.Scanner;

public class PositiverorNegative {
    public void Scan(){
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter any number you want to check either Positiver or Negative: ");
    int num = scan.nextInt();
    if(num >= 0){
        System.out.println( num + " is positive number.");
    }
    else{
        System.out.println(+ num + " is negative number.");
    }
    scan.close();
    }
    public static void main(String[] args) {
        PositiverorNegative e1 = new PositiverorNegative();
        e1.Scan();
    }
}
