package practice;
import java.util.Scanner;
public class Booth {
    int num_of_People_Visited ;
    double total_money_collected;
    final double ticket_price = 2.50;
    int NoOfPeople;
    int ticket_sold;
    String purchase ; 
  
    int  num_of_People_Visited_But_not_buytheTicket;
    Booth(){
        // default constructor
       this.num_of_People_Visited=0;
       this.total_money_collected = 0;
       this.ticket_sold=0;
       
    }
    void Ticket_Selling(int NoOfPeople ) { 
        
        Scanner scan = new Scanner(System.in); 
        
        for (int i = 1; i <=NoOfPeople; i++) { 
            System.out.println("For the "+i + " people: ");
            System.out.println("Do you want to buy the ticket?"); 
            purchase = scan.nextLine().toLowerCase(); 
            if (purchase.equals("yes")) { 
                num_of_People_Visited++;
                total_money_collected += ticket_price; 
                ticket_sold++;
            }
             else { 
                num_of_People_Visited_But_not_buytheTicket++; 
               
            } 
        } 
        scan.close(); 
    } 
 
    void Display() { 
        System.out.println("THE TOTAL AMOUNT OF MONEY COLLECTED IS: " + total_money_collected); 
        System.out.println("THE NUMBER OF PEOPLE WHO  VISITED AND BOUGHT THE TICKET IS: " + num_of_People_Visited); 
        System.out.println("THE NUMBER OF PEOPLE WHO JUST VISITED BUT NEVER BOUGHT THE TICKET IS: "+ num_of_People_Visited_But_not_buytheTicket); 
        System.out.println("THE NUMBER OF TICKET SOLD IS:"+ticket_sold);
    } 
 
    public static void main(String[] args) { 
        int NoOfPeople ; 
        Scanner scan = new Scanner(System.in); 
        System.out.println("ENTER THE TOTAL NUMBER OF PERSON : "); 
        NoOfPeople = scan.nextInt(); 
       Booth T = new Booth(); 
        T.Ticket_Selling(NoOfPeople ); 
        T.Display(); 
        scan.close(); 
 
    } 
}
