
// sum of two number using java
/* 
package practice;
 public class Test{
        int first_number = 20;//initialization
        int second_number = 10;
       int result = first_number + second_number; // instance variable
       static int  c;  //  static variable;
    public static void main(String args[])  {
       Test t = new Test();//decleration
        
        System.out.println("The sum of two number is : " + t.result);
    }

}
*/
/* 
package practice;
 public class Test{
       
       
    public static void main(String args[])  {
       double x = 10.0;
        int y = 010;
       int z = 0x10;
        
        System.out.println("The integer value of  x : " + x +" \n "+"The integer value of  y :" + y+ "\n" +"The integer value of  z : "+ z);
    }

}
*/
/* 
package practice;
import java.util.Scanner;
 public class Test{
       
       
    public static void main(String args[])  {
       Scanner scan = new Scanner(System.in);

       System.out.println("Enter the first number: ");
       int num1 = scan.nextInt();

       System.out.println("Enter the second number: ");
       int num2 = scan.nextInt();
        
       int sum = num1 + num2;
        System.out.println("The sum of two number is : " + sum);
        scan.close();
    }

}
*/

// package practice;

//  public class Test{
       
       
//     public static void main(String args[])  {
       
//         System.out.println('a'+ 'b');
//         System.out.println('a'+1);
//         System.out.println('a'+1.2);
//     }
// }

// package practice;

//  public class Test{
       
       
//     public static void main(String args[])  {
       
//          // System.out.println(10/0);
//         //  System.out.println(10/0.0);
//        //  System.out.println(0/0);
//       //  System.out.println(0/0.0);

//       //Unary Operator
//       char ch = 'a';
//       ch++;
//       double d = 10.5;
//       d ++;
//      //boolean b = true;
//      // b++;
//       System.out.println(ch);//character type of variable print garda ascii value is changed to character
//       System.out.println(d);
//       //System.out.println(b);

//       byte a = 10;
//       byte b = 20;
//       //byte c = a+b;

//      // b = b+1;
//       b++;
//       b= (byte)(b+1);

//       // relational Operator
//       //System.out.println(true>false);
//       System.out.println('a'>'b');
//       System.out.println('a'>10);
//       //System.out.println(10>20>30);//boolean ma we cant use relational operator
//       System.out.println('a' == 97.1);
//      // System.out.println(false == false);

//     }


// package practice;

// public class Test{
       
//           public static void main(String args[])  {
//    int a = 10;
//    int b = 20;
//    if(a>10 && b>20){
//     System.out.println("Nepal");
//    }
//    else{
//     System.out.println("Hello");
//    }


//           }
//         }


// Ternary operator
// package practice;

// public class Test{
       
//           public static void main(String args[])  {
//    int a = 20;
//   int b =  a<10?10:5;
//   System.out.println(b);


//           }
//         }
// If else example


// package practice;
// public class Test{
//     public static void main(String args[])  {
//         int b = 20;
//         int c = 30;
//      if( c<b){
        
//         System.out.println("True");
//      }
     
//      else
//         System.out.println("False");
     
//     }
// }

// package practice;
// public class Test{
//     public static void main(String args[])  {
//     //    boolean b = false;
//     //  if( b = true){ // we assign the value of b 
        
//     //     System.out.println("Hello");
//     //  }
     
//     //  else
//     //     System.out.println("Hi");
     
//     // }
// //     while(true){
// //     System.out.println("Hello");//it will print infinite time
// //     }
// //     System.out.println("Hi");// unreachable statement
// // }
// int a = 10, b = 20;
//  while(a<b){
//     System.out.println("Hello");//it will print infinite time
//     }
//     System.out.println("Hi");// unreachable statement
// }
// }


// package practice;

// import java.util.Scanner;

// public class Test{
//     public static void main(String args[])  {
//         // int a[] = new int[5];
//         // for(int i = 0; i<5;i++){
//         //     a[i]=i*2;
//         // }
//         // for (int b : a  ) {
//         //     System.out.println( b);
            
//         // }
//         Scanner scan = new Scanner(System.in);
//         String name[] = new String[5];
//         System.out.println("What is your name?");
//         for( int i = 0; i<5;i++){
//            name[i] = scan.nextLine();
//         }
//         for(String b : name){
//         System.out.println("My name is "+b);
//         }
// scan.close();
//     }
// }

// WAP to input the number and find the sum of each digit

package practice;
import java.util.Scanner;
public class Test{

   public int SumOfInteger(int n){
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the number: ");
    int num = scan.nextInt();
    int sum = 0;
    int digit;
    scan.close();
   
    while (num != 0) {
       digit = num % 10; // Extract the last digit
        sum += digit;         // Add the digit to the sum
        num /= 10;            
    }
    return sum;
    
  
}         
public static void main(String args[]){
Test t1 = new Test();
int result = t1.SumOfInteger( 0 );
System.out.println("The sum of number is : "+result);
}

}