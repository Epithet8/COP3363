/*==============================================================================================*/
/* PROGRAM Golf Par Program
   AUTHOR: Gabriel Clyce
   RECITATION SECTION NUMBER:1
   RECITATION INSTRUCTOR NAME:collister joshua
   COURSE: cop3363
   PROJECT NUMBER: 3
   DUE DATE: Thursday 2/18/2022
   PLATFORM: UNIX OS/g++ compiler

SUMMARY
 
This program will ask the user for a given golfdata file and then it will display the scores of the golf game along with the number of players, the lowest and highest scores, the standard deviation and the average. the program will also print these values to the user
The program will also not allow negative numbers to be entered and will result in invalid data.
INPUT 

all of the imput will be in the form of the inital check to see if the file is correct and the rest is in the file already

OUTPUT

The program will display a golf score card and the numbers that are on it will vary depending on the information in the file. after this has printed a series of number will print for
average,standard deviation, highest and lowest values and the winning player.

ASSUMPTIONS

We assume that all input data is correctly modified in the text file golfdata*///






//including librarys


#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

//opening our main function and declaring appropiate variables and names.

int main()
{

    const int HOLES=9;
    const int PAR=30;
    ifstream fileIn;
    string filename;
    double average=0;
    int players;
    int handicap;
    int score;
    int total;
    int result;    
    int square=0; 
    double standard;
    int invalid;
    int invalidplayer;
    int low=100;
    int high=0;
    int winning;
    int allresults=0;

//we will now code for the proper file name and make sure we acn check our data

    cout<<"please enter the file name"<<endl;
    cin>>filename;

    fileIn.open(filename.c_str());
//this loop will let the program reiterate everytime a user dosent enter a correct file
//we are also opening the file and checking the name

    while(!fileIn)
    {
         cout<<"please enter a valid file"<<endl;
         cin>>filename;
         fileIn.clear();
         fileIn.open(filename.c_str());
    }

//this is the display of the outgoing tournamnent results

    cout<<"                 -------------------------------------"<<endl;
    cout<<"                  SEMINOLE-9 GOLF TOURNAMENT RESULTS"<<endl;
    cout<<"                  ----------------------------------"<<endl;
    cout<<"Player  Handicap            Scores             Total  Result  Under Par?"<<endl;



   
   //this will print the correcr collem for player and handicaps
   
    fileIn>>players>>handicap;
   
//this loop will check for bad data and will call the line invalid if it is incorrect
    while(fileIn)
    {
       invalid=0;
       total=0;
       if(handicap<0)
          invalid++;
          if(players<10)
          cout<<" ";
          cout<<players<<"      "<<handicap<<"      ";
          for(int i=0; i<9; i++)                                   //this is a for loop that will check the core for bad data and correct it to invalid
          {
              fileIn>>score;
              if(score<1)
                invalid++;
              cout<<score<<"  ";
              total=total+score;

          }
          if(invalid<1)                                           //checks to see if invalid is less than one and if it is then the program proceds as normal
          {
             cout<<"      "<<total;
             result=total-handicap;
             allresults=allresults+result;
             cout<<"     "<<result;
              if(result<PAR)                                      //sets par to either yes or no if they are below a certain amount
             cout<<"      yes";
          else
             cout<<"      no";
          if(result<low)
          {
            
            low=result;                                           //setting values for winning players and highest results
            winning=players;
          }
          if(result>high)
            high=result;
          }

          else
          {
             invalidplayer++;                                    //this is the print for invalid data
             cout<<"***     invalid data    ****";
          }        
          cout<<endl;
          fileIn>>players>>handicap;

//arithmetic for the square
          square=(result*result)+square;
          


    }
//clearing and closing the file
    fileIn.clear();
    fileIn.close();
  
//the rest is simple math and displaying outcomes and numbers
    players=players-invalidplayer;

    average=allresults/players;

    standard=sqrt(square-(result*result/players)/players);   
    

    

//print display of what we need
    cout<<"Nummber of Players Counted in Results: "<<players<<endl;
    cout<<"Lowest Score: "<<low<<endl;
    cout<<"Highest Score: "<<high<<endl;
    cout<<"Average Score: "<<average<<endl;
    cout<<"Standard Deviation: "<<standard<<endl;
    cout<<"Winning Player Number: "<<winning<<endl;

    return 0;

}

//end of program==============================================================================================================================================================
