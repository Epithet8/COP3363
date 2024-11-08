/* ========================================================================== */
/*  PROGRAM Movie Box Office Receipts

    AUTHOR: <Gabriel Clyce>
    FSU MAIL NAME: <glc21g>
    RECITATION SECTION NUMBER: <2>
    RECITATION INSTRUCTOR NAME: <Ponciano,Andres>
    COP 3363 - Spring 2022
    PROJECT NUMBER: 1 
    DUE DATE: Thursday 1/20/2022
    PLATFORM: UNIX OS/g++ compiler

SUMMARY

This program takes as input the name of a movie and how many adult and
child tickets have been sold.  It then calculates the theater's gross
and net profit for the night.  The theater keeps a percentage of the
revenue from ticket sales, and the remainder goes to the distributor.

INPUT

All input is interactive.  The user inputs the movie title as a string,
which may contain blanks, and inputs the number of tickets sold as
whole numbers.

OUTPUT

The program prints an output title, echoprints the user's input in
a readable fashion, and the prints out the calculated results.

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user.  
The program is therefore not guaranteed to work correctly if bad data 
is entered.

*/

/* ========================================================================== */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/* ========================================================================== */

int main()
{
   // named (symbolic) constants
   const double ADULT_PRICE = 8.50;    // adult ticket price
   const double CHILD_PRICE = 4.75;    // child ticket price
   const double KEPT_PERCENT = 0.2;    // percentage kept by theater
   
   // variables
   string movieName;         // name of the movie
   double netProfit;         // theater's net profit
   double grossProfit;       // theater's gross profit
   double distributorAmt;    // amount paid to distributor
   int adultTickets;         // number of adult tickets sold
   int childTickets;         // number of child tickets sold

   // print overall program output heading
   cout << "******************************" <<endl;
   cout << "Box Office Receipts Calculator" <<endl;
   cout << "******************************" <<endl << endl;
   
   // get the name of the movie from the user
   cout << "Enter the name of the movie: ";
   getline(cin, movieName);

   // get the number of adult tickets sold.
   cout << "Enter the number of adult tickets sold: ";
   cin >> adultTickets;

   // get the number of child tickets sold
   cout << "Enter the number of child tickets sold: ";
   cin >> childTickets;
   
   // calculate gross profit
   grossProfit = (adultTickets * ADULT_PRICE) + (childTickets * CHILD_PRICE);

   // calculate the net profit               
   netProfit = KEPT_PERCENT *  grossProfit;
   
   // calculate the distributor's portion
   distributorAmt = grossProfit - netProfit;

   // display final results
   cout << "\nRevenue Report\n";
   cout << "Movie Name: " << "\"" << movieName << "\"" << endl << endl;
   cout << "Adult Tickets Sold:          " << setw(8) << adultTickets << endl;
   cout << "Child Tickets Sold:          " << setw(8)   << childTickets << endl;
   cout << fixed << showpoint << setprecision(2);
   cout << "Gross Box Office Profit:    $" << setw(8)   << grossProfit << endl;
   cout << "Net Box Office Profit:      $" << setw(8) << netProfit   << endl;
   cout << "Amount Paid to Distributor: $" << setw(8)   << distributorAmt  << endl;

   // print closing message
   cout << endl << "***************************************************" 
        << endl;
   cout << "Thanks for Using the Box Office Receipts Calculator" << endl;
   cout << "***************************************************" <<  endl;

   return 0;
}

/* ========================================================================== */
/*                           END OF PROGRAM                                   */
/* ========================================================================== */
