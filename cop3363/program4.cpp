#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

//this section of code will declare stratgys for the monty hall game
int DrawNum(int);
int Staystrategy(int,int,int);
int Switchstrategy(int,int,int);
int Guessstrategy(int,int,int);

int main()
{
    unsigned seed;                    
//variables will be called for values that need to be saved or called later
    int goatone,goattwo;
    double staysuccess = 0;		
    double switchsuccess = 0;
    double guesssuccess = 0;
    double winlossratio = 0;
    double winlossstay = 0;
    double winlossswitch = 0;
    double winlossguess =0;
    const int MAX =3;
    int holder = 0;//this will by a value holder for functions later
//now we can settup our random number generator followed by getting goats

    seed = static_cast<unsigned>(time(NULL));
    srand (seed);

    goatone = DrawNum(MAX);
    goattwo = DrawNum(MAX);
    while (goatone!=goattwo)
    {   
         goattwo=DrawNum(MAX); }
//this next segment will allow us to pick a door unsing variable named chance and the DrawNum
    
    int chance;
    chance=DrawNum(MAX);
    while (chance!=goatone)
    {
        chance=DrawNum(MAX); }

//we will now program the 1,000 atempts of the stay strategy 
    
    cout<< "*********Stay Strategy********" <<endl;
    cout<<"This method is when the choice is even and they first\n"
        <<"reveal a goat. The player will be asked if they want\n"
        <<"to switch doors after monty reveals a goat however\n"
        <<"in this method they stay with the same door if \n"
        <<"they pick door#1 they will stay door#1.\n";
    cout<< "**********************************************************"<<endl; 
     for(int i=0;i<=1000; i++)
     {
	Staystrategy(goatone, goattwo, chance);
        holder = Staystrategy(goatone, goattwo, chance);
        staysuccess = staysuccess + holder;}

//ratio for stay success
     { 
     winlossstay = staysuccess + holder;
     cout<< "Played 1000 Games: "<<endl;
     cout<< "Games Won: " <<staysuccess <<endl;
     cout<< "win/Loss Ratio: " <<winlossstay << endl;
     }
//we will now program the 1,000 attempts of the switch method 

     cout<< "********************Switch Strategy************************"<<endl;
     cout<<"Switch strategy consists of choosing a door by the player, "<<endl;
     cout<<"then the played is asked to stay or switch the door after  "<<endl;
     cout<<"monty reveals a goat. The player then switchs the original "<<endl;
     cout<<"door of there choice. for example player picks Door#1 they "<<endl;
     cout<<"then switch to Door #2 after seeing the goat."<<endl;
     cout<<"************************************************************"<<endl;
     for (int j=0;j<=1000;chance)
     {
         Switchstrategy(goatone, goattwo, chance);
         holder = Switchstrategy(goatone, goattwo, chance);
     }
     {
     winlossswitch = switchsuccess / 1000;
     cout<<"Played 1000 Games: "<<endl;
     cout<<"Games Won: " <<switchsuccess<<endl;
     cout<<"Win/Loss Ratio: "<<winlossswitch<<endl;
     }
 
// we will now program 1,000 attempts of the guess strategy 

     cout<<"**************Guess Strategy****************"<<endl;
     cout<<"This strategy is having the player choose " <<endl;
     cout<<"doors at random even when a goat is revealed "<<endl;
     cout<<"it is a 50/50 chance at stay or switch."<<endl;
    cout<<"*********************************************"<<endl;
     for (int k=0; k <=1000; k++)
     {  
         Guessstrategy(goatone, goattwo, chance);
         holder =  Guessstrategy(goatone, goattwo, chance);
         guesssuccess = guesssuccess + holder;
     }
     winlossguess = guesssuccess / 1000;
     cout<<"Played 1000 Games: "<<endl;
     cout<<"Games Won: "<<guesssuccess<<endl;
     cout<<"Win/Loss Ratio: " <<winlossguess<<endl;
     }
int DrawNum (int max)
{ 
    double x = RAND_MAX + 1.0;
    int y;

    y = static_cast<int> (1 + rand() * (max / x));
    return (y);
}

int Staystrategy(int goatone, int goattwo, int chance)
{   
    int success = 1;
    int failure = 0;
   
    if (chance != goattwo)
    {
       return success;
    }
    else if (chance == goattwo)
    {
    return failure;
    }
    
}
int Switchstrategy(int goatone, int goattwo, int chance)
{
    int success = 1;
    int failure = 0;
   
    if (chance==1)
    {
        if (goatone == 2)
        {
            chance =3;
        }
        else if (goatone == 3)
        {
             chance = 2;
        }
    }
    else if (chance == 2)
    {   
        if (goatone == 1)
        {
            chance = 3;
        }
        else if (goatone ==3)
        {
             chance = 1;
        }
     }
     else if (chance ==3)
     {
         if (goatone == 1)
         {
             chance = 2;
         }
         else if (goatone == 2)
         {
            chance = 1;
         }
      }
}
int Guessstrategy(int goatone, int goattwo, int chance){
    int success = 1;
    int failure = 0;
    int guess = 0;

    //this will be the final segmenet of code and the gueesing strategy math

     guess = DrawNum(2);
     if (guess == 1)
     {  
         if (chance ==1)
         {
            if (goatone==2)
            {
                chance =2;
            }
        }
      }
        else if (chance == 2)
        {
            if (goatone==1)
            {
                chance = 3;
            }
            else if (goatone==3)
            {
                 chance=1;
            }
         }
         else if (chance == 3)
         { 
             if (goatone ==1)
             {
                 chance = 2;
             }
             
             else if (goatone == 2){
             
                 chance=1;
              }
          if (chance != goattwo)
          {
              return success;
          }
          else if (chance == goattwo)
          {
              return failure;
          }
     }
}
