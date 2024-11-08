/*==============================================================================================*/
/* PROGRAM 
   AUTHOR: Gabriel Clyce
   RECITATION SECTION NUMBER:1
   RECITATION INSTRUCTOR NAME:collister joshua
   COURSE: cop3363
   PROJECT NUMBER: 4
   DUE DATE: 
   PLATFORM: UNIX OS/g++ compiler

SUMMARY
 

OUTPUT


ASSUMPTIONS

*/

//including necessary libraries
#include<iostream>
#include<cmath>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

/* =======================================================================================*/

//prints opening screen for program and the first prompted question for the file name

void Printintro() 
{
cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
cout<<"Welcome to Tallahassee Idol! Where stars are born!!!"<<endl;
cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl; 

}
//==========================================================================


//this function will open the file 
//it will also allow the user to keep entering a file if
//the file cannot be found
void OpenFile(ifstream & inFile )
{

string filename;
cout<<"Enter the name of the data file (no blanks!) ->"<<endl;
cin>>filename;
inFile.open(filename.c_str());
while(!inFile.is_open())
{
   cout<<"No File Found. Try Again"<<endl;
   cin>>filename;
   inFile.open (filename.c_str());
}
}

//i will create a function that will parse my data char into a into via a base 10 counting
/*==========================================================================*/
int stoi(string num) 
{ 
    int number = 0; 
    int numLength = num.length(); 

    for (int i = 0; i < numLength; i++)
  
{
      number = number * 10 + (int(num[i]) - '0'); 
 } 
  return number;


}



/*=============================================================================================*/
//this function will allow us to retrive the first line of data 
//and using a delimiter we will be able to use our data as integers

void GetJudgeScore(ifstream & inFile, int &  JudgeScore)
{
   int max;
   int min;
   
   
  
   string line;
 
   

   getline(inFile, line);
 
   if(isdigit(line[0]))
{
   max = int(line[0])-'0';
   min =int(line[0])-'0';
}
  else 
{
   cout << "Error";
   return;
}
   for (int i = 0; i < line.length(); i++) 
{
    if(isdigit(line[i])) 

{

      if(max != line[i] && max < line[i])
         max =int(line[i])-'0';
      
      else if(min != line[i] && min > line[i])
         min =int(line[i])-'0';

      JudgeScore =JudgeScore + int(line[i])-'0';
 }
}
   JudgeScore = (JudgeScore - (max + min))/3;   


   cout<<"====================================="<<endl;
   cout<<"Judge Scores are: "<<line<<endl;
   cout<<"average judge score: "<<JudgeScore<<endl;
   cout<<endl;
}
/*=================================================================================================*/
//this function reads in the phone call data for our contestants.
//then we will display the calls perregion and finally add them
//to see who the winner for phone calls is 


void GetPhoneData(ifstream& inFile, int& totalPhone)
{
   
   
   
   
 
   int linecount = 0;
   string line;
   
   while(getline(inFile, line) && linecount < 4){
       cout<<"Phone calls from region "<<linecount+1<<": " << line << endl;
       
       linecount++;
      
       totalPhone += stoi(line);
         
       if(linecount==4)
{
          break;
}

}
 
   cout<<"total of phone calls for all regions: "<<totalPhone<<endl;
  
}



/*======================================================================*/
//calls rand() and generates a pseudo-random number between 1 and 
//MAX_COIN_VALUE by scaling for a number and adding it back thus 
//leaving us with a somewhat random number
int FlipCoin()
   {
    const int MAX_COIN_VALUE = 2;
    return rand() % MAX_COIN_VALUE + 1;
}

/*=====================================================================================================*/
//this will take the judge data and phone data coming in and 
//calculates the winner via judge score and the winner by phone calls, 
//the final overall winner wil be displayed at the end 
//ties will be taken into account and our flip coin function will take care of it
//we will use a series of conditional statements


void FindWinner(int JudgeScore1,int totalPhone1,int JudgeScore2,int totalPhone2)
{
   int tie;  
   cout<<"                         "<<endl;
   cout<<"Final Results Summary"<<endl;
   cout<<"---------------------"<<endl;
   if(JudgeScore1>JudgeScore2)
{
      cout<<"Judge winner is: Contestant 1"<<endl;      
}
   else if(JudgeScore2>JudgeScore1)
{ 
      cout<<"Judge winner is: Contestant 2"<<endl;
}
   else if (JudgeScore1==JudgeScore2)
{
      tie = FlipCoin();
      if(tie==1)
         cout<<"Judge winner is: Contestant 1"<<endl;
      else if(tie==2)
         cout<<"Judge winner is: Contestant 2"<<endl;
         

}
   cout<<endl;
   if(totalPhone1>totalPhone2)
{
      cout<<"Phone call winner is: Contestant 1"<<endl;
}
   else if(totalPhone2>totalPhone1)
{
      cout<<"The call winner is: contestant 2"<<endl;

}
   else if (JudgeScore1==JudgeScore2)
{
      tie = FlipCoin();
      if(tie==1)     
         cout<<"Judge winner is: Contestant 1"<<endl;
      else if(tie==2)
         cout<<"Judge winner is: Contestant 2"<<endl;
         

}
   if(JudgeScore1>JudgeScore2 && totalPhone1>totalPhone2)
      cout<<"The overall winner is: Contestant 1!!!"<<endl;
   else if(JudgeScore2>JudgeScore1 && totalPhone2>totalPhone1)
      cout<<"The overall winner is: Contestant 1!!!"<<endl;
   else
{
      tie = FlipCoin();
      if(tie==1)
         cout<<"The overall winner is: Contestant 1"<<endl;
      else if(tie==2)
         cout<<"The overall winner is: Contestant 2"<<endl;




}
}




//sets mac coin value to 2 the rand() % give us a value and we just add a number to account then we return the function
// simply prints out closing messages at end of run 
 
/* ========================================================================== */ 
void PrintClosing()
{
   cout<<" "<<endl;
   cout<<" "<<endl;
   cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
   cout<<"Thanks for visiting our show!!!"<<endl;
   cout<<"Execution Terminated Normally."<<endl;
   cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
}

/*=======================================================================================*/


//main will be able to display and print the appropriate values 
//we will be calling our functions here in the proper order
// along with the parameters.
//we will also be formating alot of the output we want and need.
int main() 
{
    ifstream inFile;
    int JudgeScore1=0,JudgeScore2=0;
    int totalPhone1=0,totalPhone2=0;
    srand (time(NULL));   
    

    
    Printintro();
    OpenFile(inFile);
    

    cout<<"Judges Scores for Contestant 1 "<<endl;
    GetJudgeScore(inFile, JudgeScore1);
    cout<<"Processing Phone Data for Contestant 1 "<<endl;
    GetPhoneData(inFile, totalPhone1);
    

    cout<<"Judges Scores for Contestant 2 "<<endl;
    GetJudgeScore(inFile, JudgeScore2);
    cout<<"Processing Phone Data for Contestant 2 "<<endl;
    GetPhoneData(inFile, totalPhone2);
    
    FindWinner(JudgeScore1,totalPhone1,JudgeScore2,totalPhone2);

    PrintClosing();
}

                                                                                                                       
