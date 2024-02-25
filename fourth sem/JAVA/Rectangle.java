package practice;
import java.util.Scanner;

    public class Rectangle{
        //instance variable
        int length;
        int breadth;
       
        public Rectangle(){
            //default construction
         } 

     public Rectangle(int l , int b){ // argument construction
     length = l;
     breadth = b;
     } 
    

      public void getArea(){                // Method to get user input
     Scanner scan = new Scanner(System.in);

     System.out.println("Enter the length of rectangle: ");
     length = scan.nextInt();
     System.out.println("Enter the breadth of a rectangle: ");
     breadth= scan.nextInt();
  
     scan.close();
       }
       
       public void printArea(){    //method to print area
       int Area = length*breadth;
       System.out.println("The area of a rectangle is :  "+ Area);
       }

        public static void main(String args[]) {
        Rectangle R = new Rectangle(); 
        // creating a new object of a class and returns the reference to that object . 
       //R is the reference variable which holds the memory address of the new object
        R.getArea(); // it calls the getarea function
        R.printArea();
    }
    } 


