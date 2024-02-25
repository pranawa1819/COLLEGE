package practice;
import java.util.Scanner;
public class Square {
   
    
    void SquareOfNumber(int num){
     int result= (int) Math.pow(num,2);
     System.out.println("The square of "+num +" is "+result); 
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the number you want to find a square: ");
        int  num = scan.nextInt();
        scan.close();
        Square S1 = new Square();
        S1.SquareOfNumber(num);
    }
}
