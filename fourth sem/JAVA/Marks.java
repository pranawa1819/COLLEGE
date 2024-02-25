package practice;
import java.util.Scanner;
public class Marks {
    
     void Student(){
        double  total_marks = 0;
        double percentage;
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the name of student: ");
        String name = scan.nextLine();
        System.out.println("Enter the marks of five subject: ");

        for(int i = 1 ; i<= 5;i++){
            System.out.println("Enter the marks of " + i + " subject: ");
            double marks = scan.nextDouble();
             total_marks += marks;
        }

        percentage = (total_marks/500)*100;
        System.out.println("Your Name : "+ name);
        if(percentage >= 40.00){
        System.out.println("Well Done!! \nYou secured "+ percentage +" percent in your mid-term exam.");
        }
        else {
        System.out.println("Sorry ): \nYour percentage is  ."+ percentage );
        }
        scan.close();
    }

    public static void main(String[] args) {
       Marks m1 = new Marks();
        m1.Student();
    }
}

