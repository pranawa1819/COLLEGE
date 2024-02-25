package practice;

import java.util.Scanner;

public class Sumofnthnumber {
    
    public static void main(String args[]){
        
            Scanner scan = new Scanner(System.in);
            System.out.println("Enter the size of an array: ");
            int n = scan.nextInt();
            System.out.println("Enter the nth number: ");
            int sum = 0;
            double average;
           
            for(int i = 1; i<=n;i++){
                System.out.println("Enter the  "+ i+"th number: ");
                int num = scan.nextInt();
                sum = num+sum;
            }

            average = (double)(sum/n);
            System.out.println("The sum of nth number  : "+sum);
            System.out.println("The average of nth number : "+average);
            scan.close();
    }

}
