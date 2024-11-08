/*==============================================================================================*/
/* PROGRAM medical expert system
   AUTHOR: Gabriel Clyce
   RECITATION SECTION NUMBER:
   RECITATION INSTRUCTOR NAME:
   COURSE: cop3363
   PROJECT NUMBER: 2
   DUE DATE: Thursday 2/3/2022
   PLATFORM: UNIX OS/g++ compiler

SUMMARY
 
This program will ask a series of questions to accuratly describe if you habe an illness.
the qualifing illnesses are a cold, flu ,sinitis and the final one is for patients who cannot be
diagnosed with any of the following conditions. we will then as the customer for payment depending on 
there condition. after the diagnoses we will display the price of the examination.

INPUT 

all of the imput will be interactive the user will supply values

OUTPUT

The program prints the questions and then displays the diagnoses.
after it will display the price and ask for payment to be produced from the user.

ASSUMPTIONS

We assume that all input data is valid and correctly entered when it is for the appropriate value.*/






//including librarys
#include<iostream>
using namespace std;

//here we are opening our main and declaring variables first

int main()
{   float temperature;
    string nosechoice;
    string achychoice;
    string headachechoice;
    string nasalcongestion;
//inital title screen

cout<<"================================"<<endl;
cout<<"Welcome to DR. PC'S Office!"<<endl;
cout<<"================================"<<endl;





// after variables have been declared we ask the necassary questions

    cout<< "Do you have a runny nose?(enter 'y' or 'n')"<<endl;
    cin>>nosechoice;
    cout<<"Are you experiencing nasal congestion?(enter 'y' or 'n')"<<endl;
    cin>>nasalcongestion;
    cout<<"Are you feeling achy all over?(enter 'y' or 'n')"<<endl;
    cin>>achychoice;
    cout<<"do you have a severe headache behind or below one eye?(enter 'y' or 'n')"<<endl;
    cin>>headachechoice;
    cout<<"what is your tempurature?(enter a number) "<<endl;
    cin>>temperature;

// after the conditional questions we make use of if function to set condiotions for our response which we interpret correctly.

 


    if((nosechoice=="y") && (nasalcongestion=="y") && (achychoice=="n") && (headachechoice=="n") && (temperature < 99.0)){
       cout<<"COLD:      You have a cold. make sure to rest and drink plenty of fluids your bill is $40.00"<<endl;}
    if((nosechoice=="y") && (nasalcongestion=="y") && (achychoice=="y") && (headachechoice=="n") && (temperature <101)){
       cout<<"Sinusitis; You have sinusitis.Rest, drink plenty of fluids, take tylenol or asprin and take 250mg of penicillin 4 times a day. Your bill is $55.00"<<endl;}
    if((nosechoice=="y") && (nasalcongestion=="y") && (achychoice=="y") && (headachechoice=="n") && (temperature<99)){
       cout<<"FLU:      You have respiratory influenza.Rest, and drink plenty of fluids take asprin or tylenol. your bill is $40.00"<<endl;}
    else{
       cout<<"sorry you have to see a specialist your bill is $40"<<endl;}
    
// end of program



}
