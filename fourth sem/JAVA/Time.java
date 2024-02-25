// CREATE A CLASS TIME WITH INSTANCE VARIABLES HOUR AND MINUTE. OTHER 
// SPECIFICATIONS ARE: 
// b) DEFINE A PARAMTERIZED CONSTRUCTOR THAT INITIALIZES TIME OBJECT TO FIX THE 
// VALUE 
// c) DEFINE A MEMBER METHOD THAT ADDS TWO TIME OBJECTS AND RETURN THE RESULTANT 
// OBJECTS 
// d) MAIN METHOD SHOULD CREATE TWO OBJECTS t1 AND t2 INITIALIZED TO FIX VALUE 
// AND THIRD NON-INITIALIZED TIME OBJECT t3 AND PERFORM t3 = t1 + t2. 




package practice;

import java.util.Scanner;

public class Time {
    int hour;
    int minute;

    Time(){
 // default constructor
    }
    Time(int hour, int minute){     // paramateric constructor
        this.hour=hour;
        this.minute = minute;
    }

    // adding time of two object
    //  This method adds the current Time object (this) with another Time object t and returns a new Time object representing the sum
   Time addTime(Time t){
   int new_Hour = this.hour + t.hour;
   int new_Minute = this.minute + t.minute;

   if(new_Minute>=60){
    new_Hour += new_Minute/60;
    new_Minute %= 60;
   }
   if(new_Hour>=24){
    new_Hour %= 24;
   }
   return new Time(new_Hour,new_Minute);
    }

    // getter method
   // which encapsulates the internal state of an object and provides controlled access to it.
    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }

    public static void main(String[] args) {
        
    Scanner scan = new Scanner(System.in); 
    int h1, m1; 
    int h2, m2; 
    System.out.println("ENTER FIRST HOUR: "); 
    h1 = scan.nextInt(); 
    System.out.println("ENTER FIRST MINUTES: "); 
    m1= scan.nextInt(); 
 
    System.out.println("ENTER SECOND HOUR: "); 
    h2 = scan.nextInt(); 
    System.out.println("ENTER SECOND MINUTES: "); 
    m2  = scan.nextInt(); 

        Time t1 = new Time(h1,m1);    // Creating a Time object using the default constructor
        Time t2 = new Time(h2,m2);

        Time t3 = t1.addTime(t2);    // Adding t1 and t2, and storing the result in t3

        System.out.println("THE SUM OF TIME 1: "+ t3.getHour() +"\nTHE SUM OF  TIME 2 : " + t3.getMinute()); 
        scan.close(); 
    }
    
}
