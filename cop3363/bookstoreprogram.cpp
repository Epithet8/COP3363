/* ========================================================================== */
/*  PROGRAM Bookstore

    AUTHOR: Gabriel Clyce 
    FSU MAIL NAME: glc21g
    RECITATION SECTION NUMBER: 1
    RECITATION INSTRUCTOR NAME: William davenport
    COP 3363 - Fall 2021
    PROJECT NUMBER: 2 
    DUE DATE: Thursday 9/23/2021
    PLATFORM: UNIX OS / g++ compiler
    SUMMARY: 
This program provides an algorithim that allows for the total cost or books sold for profit at a schools bookstore given the information of old or new books, required or suggested, and the class size and volumes on hand.
    INPUT: we will ask for the books id, cost per copy, enrollment for course, how many volumes the bookstore has , If it is old and new and if the books is required or suggested
    OUTPUT: This algorithim will out put the expected profit, Book ID ,number of books to order and the total cost
    ASSUMPTION: in my assumption i feel the code will work except the math portion and i was very correct in my assumption but i did not for see the many double variables i would have to use.


*/

   
#include <iostream>
#include <cmath>
using namespace std;

int main() {  
    //declare constant variable
    int bookid, currentvol, expectedenrollment;
    char reqorsug, oldornew;
    double NRpercent=0.9, NSpercent=0.4, ORpercent=0.65, OSpercent=0.2;
    double bookstoorder, totalcost, profit, costpercopy, expectedtosell;

    //output and welcome screen
    cout<<"***************************************"<<endl;
    cout<<"WELCOME TO THE BOOKSTORE ORDER PROGRAM"<<endl;
    cout<<"***************************************"<<endl;
   

    //storing variables and user input
    cout<<"Enter the books ID number: "<<endl;
    cin>>bookid;
    cout<<"Enter the books cost per copy: "<<endl;
    cin>>costpercopy;
    cout<<"Enter the expected class enrollment: "<<endl;
    cin>>expectedenrollment;
    cout<<"Enter the current volume on hand: "<<endl;
    cin>>currentvol;
    cout<<"Is the book required (R) or suggested(S)? "<<endl;
    cin>>reqorsug;
    cout<<"Is the book new (N) or old (O)? "<<endl;
    cin>>oldornew;

    //calculations and if statement
 
    
   

    // print those values taken as inoput
    //calculate ecpected books to sell using the if else atatement
   

    if (oldornew=='N' && reqorsug=='R')
           expectedtosell=expectedenrollment * NRpercent;
    
    else if (oldornew=='N' && reqorsug=='S')
	expectedtosell=expectedenrollment * NSpercent;
    else if (oldornew=='O' && reqorsug=='S')
	expectedtosell=expectedenrollment * OSpercent;
    else if (oldornew=='O' && reqorsug=='R')
        expectedtosell=expectedenrollment * ORpercent;
    	


	bookstoorder=ceil(expectedtosell)-currentvol;
	bookstoorder=static_cast<int>(bookstoorder);
	
	if(bookstoorder<0)
	   bookstoorder=0;
        if(bookstoorder>0){
           
           totalcost=bookstoorder * costpercopy;
           profit=totalcost * (1/0.8 - 1);
	   cout<<"Total cost of this order: $"<<totalcost<<endl;
           cout<<"Expected profit: $"<<profit<<endl;
        }
	//print estimation summary of books to order
	
	
    

      //output
     cout<<"Information for book ID: "<<bookid<<endl;
     cout<<"Bookstore program terminated:"<<endl;
     cout<<"Number of books to order: "<<bookstoorder<<endl;



return 0; 	
}
