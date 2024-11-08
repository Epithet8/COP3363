/*=====================================================================================*/
/* PROGRAM monty hall ratios
   

   AUTHOR: Gabriel Clyce
   FSU MAIL NAME: Glc21g
    RECITATION SECTION NUMBER: 01
    RECITATION INSTRUCTOR NAME: Trina Dutta
    COURSE: Cop3363
    PROJECT NUMBER: 1 
    DUE DATE: Thursday 10/28/2021
    PLATFORM: UNIX OS/g++ compiler





#include <iostream>
#include <stdio.h>  
#include <cstdlib>
#include <time.h>
// Prototypes
int DrawNum();
int* Initialize();
void MontyHallStrategies(int doorSelections[3], int selectionCounter[3]);
bool StrategyOne(int doorSelections[3]);
bool StrategyTwo(int doorSelections[3]);
bool StrategyThree(int doorSelections[3]);

bool StrategyOne(int doorSelections[3]){

    // Grab a chosen number.
    int chosenNumber = DrawNum();

    // Now let's check if the chosen number is the car in the array spot (value: 1).
    if (doorSelections[chosenNumber] == 1){
        return true;
    } else {
        return false;
    }
}

bool StrategyTwo(int doorSelections[3]){

    // Grab a chosen number.
    int chosenNumber = DrawNum();

    // Should we stay or switch?
    int staySwitch = rand() % 2;

    // If staySwitch is 1, we will switch... else we will stay.
    if (staySwitch == 1){
        // Make sure that we do not get the same chosenNumber.
        while(true){
            int newChosenNumber = rand() % 3;

            // If the newChosenNumber is not equal to the chosenNumber, we've done our job.
            if (newChosenNumber != chosenNumber){

                // Set and break out of the loop.
                chosenNumber = newChosenNumber;
                break;
            }
        }

    }

    // Now let's check if the chosen number is the car in the array spot (value: 1).
    if (doorSelections[chosenNumber] == 1){
        return true;
    } else {
        return false;
    }
}

bool StrategyThree(int doorSelections[3]){

    // Grab a chosen number.
    int chosenNumber = DrawNum();

    // Make sure that we do not get the same chosenNumber.
    while(true){
        int newChosenNumber = DrawNum();

        // If the newChosenNumber is not equal to the chosenNumber, we've done our job.
        if (newChosenNumber != chosenNumber){

            // Set and break out of the loop.
            chosenNumber = newChosenNumber;
            break;
        }
    }

    // Now let's check if the chosen number is the car in the array spot (value: 1).
    if (doorSelections[chosenNumber] == 1){
        return true;
    } else {
        return false;
    }
}

int DrawNum(){

    // When rand() % 3 is called, it will choose 1, 2, 3.
    // If the number is 3, we will move to the [0]th index.

    int randomNumber = rand() % 3;
    if(randomNumber == 3){
        return 0;
    } else {
        return randomNumber;
    }

}

int* Initialize(){
    // Create a static array of the doors.
    static int selections[3];

    // Init all values to 0.
    for(int i = 0; i < 3; i++){
        selections[i] = 0;
    }

    // Allocate a one to a random spot.
    selections[DrawNum()] = 1;

    return selections;
}

void MontyHallStrategies(int doorSelections[3], int selectionCounter[3]){
    // Set all values in the 3 spots to 0;
    for(int i = 0; i < 3; i++){
        selectionCounter[i] = 0;
    }


    for (int i = 0; i < 1000; i++){
        if (i == 0){
            std::cout << "Strategy (1) - Always stay with the door initially picked.";
        }

        if (StrategyOne(doorSelections)){
            selectionCounter[0]++;
        }

        if(i == 1000 - 1){
            std::cout << "\nPlayed 1000 games, the results are:" << std::endl;
            std::cout << "Games won: " << selectionCounter[0] << std::endl;
            std::cout << "Played 1000 games, the results percentage is: " << float(selectionCounter[0])/1000 << "%" << "\n" << std::endl;
        }
    }

    for (int i = 0; i < 1000; i++){
        if (i == 0){
            std::cout << "Strategy (2) - Randomly stay or switch (for example, by flipping a coin to decide).";
        }

        if (StrategyTwo(doorSelections)){
            selectionCounter[1]++;
        }

        if(i == 1000 - 1){
            std::cout << "\nPlayed 1000 games, the results are:" << std::endl;
            std::cout << "Games won: " << selectionCounter[1] << std::endl;
            std::cout << "Played 1000 games, the results percentage is: " << float(selectionCounter[1])/1000 << "%" << "\n" << std::endl;
        }
    }

    for (int i = 0; i < 1000; i++){
        if (i == 0){
            std::cout << "Strategy (3) - Always switch to the unpicked and unopened door.";
        }

        if (StrategyThree(doorSelections)){
            selectionCounter[2]++;
        }

        if(i == 1000 - 1){
            std::cout << "\nPlayed 1000 games, the results are:" << std::endl;
            std::cout << "Games won: " << selectionCounter[2] << std::endl;
            std::cout << "Played 1000 games, the results percentage is: " << float(selectionCounter[2])/1000 << "%" << "\n" << std::endl;
        }
    }
}

int main() {
    // Seed the time.
    srand( (unsigned)time(nullptr) );

    // Door selections holds the doors.
    int *doorSelections = Initialize();

    // Simulate
    static int selectionCounter[3];
    MontyHallStrategies(doorSelections, selectionCounter);

    return 0;
}
