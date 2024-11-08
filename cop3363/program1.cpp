/* ========================================================================== */
/*  PROGRAM Weighted Grade Calculator

    AUTHOR: Gabriel Clyce
    FSU MAIL NAME: Glc21g
    RECITATION SECTION NUMBER: 01
    RECITATION INSTRUCTOR NAME: Trina Dutta
    COURSE: Cop3363
    PROJECT NUMBER: 1 
    DUE DATE: Thursday 9/9/2021
    PLATFORM: UNIX OS/g++ compiler

SUMMARY

This program takes as input the user's scores on 6 programs and 2 exams.
It then calculates the weighted total grade for the user.  Note the item
weights are exactly as given in this term's course syllabus.  You will
be able to use this program to calculate your own final weighted total.

INPUT

All input is interactive.  The user inputs the scores as integer values.

OUTPUT

The program prints an output title, echoprints the user's input in
a readable fashion, and then prints out the calculated final result.

ASSUMPTIONS

We assume that all input data is valid and correctly entered by the user.  
The program is therefore not guaranteed to work correctly if bad data 
is entered.
*/

#include <iostream>                // include standard I/O libraries
#include <iomanip>
using namespace std;

int main ()
{    
    // the constant weights for all scoring items
    const double P1_WEIGHT = 0.02;
    const double P2_WEIGHT = 0.10;
    const double P3_TO_P6_WEIGHT = 0.12;
    const double EXAM_WEIGHT = 0.20;

    int p1score;                   // scores on the 6 programs
    int p2score;
    int p3score;
    int p4score;
    int p5score;
    int p6score;
    int exam1score;                // scores on the 2 exams
    int exam2score;
    double wtdTotalGrd;            // the weighted total grade as calculated

    // write the main output heading
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Welcome to the Weighted Grade Calculator Program" << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;

    // ask the user to type in the program grades first
    cout << "Please enter your score on program 1 -> ";
    cin >> p1score;
    cout << "                           program 2 -> ";
    cin >> p2score;
    cout << "                           program 3 -> ";
    cin >> p3score;
    cout << "                           program 4 -> ";
    cin >> p4score;
    cout << "                           program 5 -> ";
    cin >> p5score;
    cout << "                           program 6 -> ";
    cin >> p6score;

    // now ask the user to type in the exam scores
    cout << endl << "Please enter your score on exam 1 -> ";
    cin >> exam1score;
    cout << "                           exam 2 -> ";
    cin >> exam2score;

    // echoprint all of the user's scores to verify accuracy
    cout << endl << "You have entered the following scores:" << endl
        << "\tProgram 1: " << p1score << endl
        << "\tProgram 2: " << p2score << endl
        << "\tProgram 3: " << p3score << endl
        << "\tProgram 4: " << p4score << endl
        << "\tProgram 5: " << p5score << endl
        << "\tProgram 6: " << p6score << endl
        << "\tExam 1: " << exam1score << endl
        << "\tExam 2: " << exam2score << endl << endl;

    // calculate the weighted total grade as a real number
    wtdTotalGrd = (p1score * P1_WEIGHT) + (p2score * P2_WEIGHT)
                  + ((p3score + p4score + p5score + p6score) * P3_TO_P6_WEIGHT)
                  + ((exam1score +  exam2score) * EXAM_WEIGHT);

    // now print the weighted total with 2 digits past the decimal point
    cout << fixed << showpoint << setprecision(2);
    cout << "Your weighted total is: " << wtdTotalGrd << endl;

    // print a closing message and signal normal termination
    cout << endl <<  "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << endl << "Program Run Completed." << endl;
    cout <<  "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;

    return (0);
}
