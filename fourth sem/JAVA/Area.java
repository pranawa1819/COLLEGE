package practice;
import java.util.Scanner;
public class Area {

    final double pie = 3.14;
    int radius;
    double area;
    public void getData(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the radius of a circle: ");
        radius = scan.nextInt();
        scan.close();
    }
    public double calArea(){
    area = pie*radius*radius;
    return area;
    }
    public void Display(){
    System.out.printf("The area of circle is: %.2f",area);
    }
    
    public static void main(String args[]){
    Area a1 = new Area();
    a1.getData();
    a1.calArea();
    a1.Display();
    
    }

}