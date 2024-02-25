package practice;

import java.util.Scanner;

public class EvenOROdd {
    public void check(){
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter any number you want to check either even or odd: ");
    int num = scan.nextInt();
    
    if(num % 2 == 0){
        System.out.println( num + " is even number.");
    }
    else{
        System.out.println(+ num + " is odd number.");
    }
    scan.close();
    }
    public static void main(String[] args) {
        EvenOROdd e1 = new EvenOROdd();
        e1.check();
    }
}
