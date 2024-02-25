package practice;

public class Methodoverloading {
    
     void add(){
     System.out.println("No argument type!!");
    }
     void add(int a,int b){
        int sum = a+b;
        System.out.println("The sum of tyo integer number is: "+sum);

    }
     void add(float c,float d){
        float sum = c+d;
        System.out.println("The sum of two floating number is: "+sum);
   
       }
       void add(char a, char e){
        int sum = a+e;
        System.out.println("The sum of two character type is: "+sum);
   
       }
       public static void main(String[] args) {
        Methodoverloading M1 = new Methodoverloading();
        M1.add();
        M1.add('a','b');
        M1.add(12,45);
        M1.add(1.2f,14.3f);

       }
}
