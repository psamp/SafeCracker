//
//  main.c
//  SafeCracker
//
//  Created by Princess Sampson on 8/10/16.
//  Copyright © 2016 Princess Sampson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int takeInAString(char*);
void getNewCombination(int* combination);
void takeInCombinationGuess(int* guessedCombination);
bool compareIntArrays(int* a, int* b, int lengthOfArrays);
void gameplay(void);

int main(int argc, const char * argv[]) {
    
    char user[30] = {'\0'};
    int scannedUsersNameSuccesfully = -1;
    
    printf("Welcome to SafeCracker! If you guess the code to an evil billionaire's safe, all the riches within are yours.\nYou have 3 chances.\nSo we know who to make the check out to in the event you guess correctly, please tell us your name.\n\n");
    printf("Enter name:\n\n");
    
    while (scannedUsersNameSuccesfully != 1) {
        scannedUsersNameSuccesfully = takeInAString(user);
    }
    
    printf("Nice to meet you, %s.\n\n", user);
    
    gameplay();
    
    return 0;
}

void gameplay() {
    int combination[4] = {[0 ... 3] = -1};
    
    int timesUserHasGuessed = 0;
    
    int guessedCombination[4] = {[0 ... 3] = -1};
    int digitsGuessedThatAreInCombination[4] = {[0 ... 3] = -1};
    
    bool guessing = true;
    
    getNewCombination(combination);
    
    printf("Combination: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", combination[i]);
    }
    printf("\n\n");
    
    while (guessing) {
        
        takeInCombinationGuess(guessedCombination);
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (guessedCombination[i] == combination[j]) {
                    digitsGuessedThatAreInCombination[i] = guessedCombination[i];
                }
            }
        }
        
        if (compareIntArrays(guessedCombination, combination, 4) == true) {
            
            printf("You won! You're rich!\n\n");
            guessing = false;
            
        } else {
            
            printf("You tried! These are the digits you guessed correctly, and they feature somewhere in the safe combo. But not nessasarily the same amount of times, or in the same order.\n\n");
            
            for (int i = 0; i < 4; i++) {
                if (digitsGuessedThatAreInCombination[i] != -1) {
                    printf("%d\n", digitsGuessedThatAreInCombination[i]);
                }
            }
            
            char input = '\0';
            printf("To guess again, type \"y\". To quit, type anything else.\nEnter:\n\n");
            fpurge(stdin);
            int itemsScanned = takeInAString(&input);
            
            if (itemsScanned == 1 && input == 'y') {
                timesUserHasGuessed = -1;
            } else {
                guessing = false;
            }
        }
        
        timesUserHasGuessed++;
    }
}

bool compareIntArrays(int* a, int* b, int lengthOfArrays) {
    bool rtn = false;
    int mactchingValuesAtEachIndex = 0;
    
    for (int i = 0; i < lengthOfArrays; i++) {
        if (a[i] == b[i]) {
            mactchingValuesAtEachIndex++;
        }
    }
    
    if(lengthOfArrays == mactchingValuesAtEachIndex) {
        rtn = true;
    }
    
    return rtn;
}


int takeInAString(char* destinationVariable) {
    fpurge(stdin);
    int itemsScanned = scanf("%[^\n]s", destinationVariable);
    
    return itemsScanned;
}

void getNewCombination(int* combination){
    
    for (int i = 0; i < 4; i++) {
        combination[i] = arc4random_uniform(4);
    }
    
}

void takeInCombinationGuess(int* guessedCombination) {
    int tookInGuessesSuccessfully = -1;
    
    while (tookInGuessesSuccessfully != 4) {
        fpurge(stdin);
        printf("Enter 4 numbers between 0 and 3, seperated by hyphens.\nExample: 0-1-2-3\nEnter:\n\n");
        
        tookInGuessesSuccessfully = scanf("%d-%d-%d-%d",&guessedCombination[0], &guessedCombination[1], &guessedCombination[2], &guessedCombination[3]);
    }
    
}
