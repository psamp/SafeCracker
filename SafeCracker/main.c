//
//  main.c
//  SafeCracker
//
//  Created by Princess Sampson on 8/10/16.
//  Copyright © 2016 Princess Sampson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int takeInAString(char*);
void getNewCombination(int* combination);
void guessCombination(int* guessedCombination);
void takeInCombonationGuess(int* guesses);

int main(int argc, const char * argv[]) {
    
    char user[30] = {'\0'};
    int scannedUsersNameSuccesfully = -1;
    
    printf("Welcome to SafeCracker! If you guess the code to an evil billionaire's safe, all the riches within are yours\nYou have 3 chances to guess correctly.\nSo we know who to make the check out to in the event you guess correctly, please tell us your name.\n\n");
    printf("Enter name:\n\n");
    
    while (scannedUsersNameSuccesfully != 1) {
        scannedUsersNameSuccesfully = takeInAString(user);
    }
    
    printf("Nice to meet you, %s.\n\n", user);
    
    int combination[4] = {0};
    getNewCombination(combination);
    
    int timesGuessed = 0;
    int guessedCombination[4] = {0};
    int correctGuesses[4] = {[0 ... 3] = -1};
    
    while (timesGuessed <= 2) {
        guessCombination(guessedCombination);
        
        /*if (guessedCombination[0] == p) {
            <#statements#>
        }*/
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if(guessedCombination[i] == combination[j]) {
                    correctGuesses[i] = guessedCombination[i];
                }
            }
        }
        
        timesGuessed++;
        
        printf("TIMESGUESSED: %d", timesGuessed);
    }
    
    return 0;
}


int takeInAString(char* destinationVariable) {
    fpurge(stdin);
    int itemsScanned = scanf("%[^\n]s", destinationVariable);
    
    return itemsScanned;
}

void getNewCombination(int* combination){
    
    for (int i = 0; i < 5; i++) {
        combination[i] = arc4random_uniform(4);
    }
    
}

void guessCombination(int* guessedCombination) {
    int tookInGuessesSuccessfully = -1;
    
    while (tookInGuessesSuccessfully != 4) {
        fpurge(stdin);
        printf("Enter 4 numbers between 0 and 3, seperated by hyphens.\nExample: 0-1-2-3\nEnter:\n\n");
        
        tookInGuessesSuccessfully = scanf("%d-%d-%d-%d",&guessedCombination[0], &guessedCombination[1], &guessedCombination[2], &guessedCombination[3]);
    }
    
}
