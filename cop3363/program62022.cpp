/*/*=====================================================================*/
/* PROGRAM
   AUTHOR: Gabriel Clyce
   RECITATION SECTION NUMBER:1
   RECITATION INSTRUCTOR NAME:collister joshua
   COURSE: cop3363
   PROJECT NUMBER: 6
   DUE DATE:4/19/2022
   PLATFORM: UNIX OS/g++ compiler

SUMMARY
we will create a dictonary program that can be used by reading from a file
using 4 commands sort,lookup,dump and exit along with a file check

OUTPUT
our output will display the list of words with using the sort command and lookup will be 
used to actually retrive the definition of the word, the Dump function
will print the available words left and exit will simply exit the program


ASSUMPTIONS
we can assume data files are correct but must be able to be 
opened if not we will exit the function


*/

//including necassary librarie
#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;


//we are opening our file hear and are saving the amount of words from the integer 
//in the txt file

void openfile(ifstream & inFile,  int&amountofwords)
{
string filename;
cout<<"Please enter a dictionary file name: "<<endl;
cin>>filename;
inFile.open(filename.c_str());
    
    while(!inFile.is_open())
    {
        cout<<"Incorrect file."<<endl;   
        cin>>filename;
        inFile.open(filename.c_str());   
    }
    cout<<"succesful opening: "<<endl;
    inFile>>amountofwords;
}  

//createing our struct object with the word and definition
struct wordstruct {
string word;
string definition;
}
;
                        //bitstring being declared here 
typedef wordstruct wordarray[25];


      //we will begin the functionality of our commands 
      //such as sort, dump ,lookup and exit

void loaddictionary(ifstream&inFile,wordarray arrayread,int amountofwords)
{  
  
   for(int i=0;i<amountofwords;i++)
   {
       inFile>>arrayread[i].word;
       inFile.ignore(100,'\n');
       getline(inFile,arrayread[i].definition);
   }
   
   
}

//exits the program when entered
void doExit()
{
cout<<"have a great day/night"<<endl; 
exit(0);  
}

//sort function will sort all words in alphabetical order

void dosort(wordarray arrayread,int amountofwords)
{ 
wordstruct temp;
 int x=0;
bool amoungus=true;

  while(amoungus==true)
  {
    amoungus=false;
    for(int i=0;i<amountofwords-1;i++)
    {
    
    x = arrayread[i].word.compare(arrayread[i+1].word);
    
    if(x>0)
    {
    
    temp=arrayread[i];
    arrayread[i]=arrayread[i+1];
    arrayread[i+1]=temp;
    
    amoungus=true;  
    }
    } 
            
  }
  
}

void lookup(wordarray arrayread,int amountofwords)
{
string userchoice;
bool found=false;
int index;
cout<<"lookup: please enter a word"<<endl;
cin>>userchoice;

for(int i=0;i<amountofwords;i++)
{ 
  if(userchoice==arrayread[i].word)
  {  index=i;
     found=true;
     
  }
 } 

  if(found==true)
  { 
    cout<<arrayread[index].word<<endl;
    cout<<arrayread[index].definition<<endl;

  }
  else
  {
    cout<<"please enter a correct word"<<endl;
  }

  
}
void dump(wordarray arrayread,int amountofwords)
{


for(int i=0;i<amountofwords;i++)
   {
       cout<<arrayread[i].word<<endl;
       cout<<arrayread[i].definition<<endl;
   } 

}


int main()
{  
    string userchoice;
    ifstream inFile;
    int amountofwords;   
    wordarray dictionary;
    openfile(inFile,amountofwords);
    
    loaddictionary(inFile,dictionary,amountofwords);
    
    
    
    //while loop will allow for the user to choose commands as necassary
   
    while(true)
    {  
        cout<<"please enter a command"<<endl;    
        cin>>userchoice;
        if(userchoice=="exit")
          doExit();
        else if(userchoice=="lookup")
          lookup(dictionary,amountofwords);
        else if(userchoice=="dump")
          dump(dictionary,amountofwords);
        else if(userchoice=="sort")
          dosort(dictionary,amountofwords);
                


        else
          cout<<"invalid command please try again"<<endl; 


    }
       


return 0;
}



/*summary of tasks
  open
  tell what file 
  
  sort in alphabet order
  lookup finds the word
  
  2approaches
1  load data from disk
2  create small dictionary
*/
