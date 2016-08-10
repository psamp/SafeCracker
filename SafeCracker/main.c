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
void gameplay(void);

int main(int argc, const char * argv[]) {
    
    char user[30] = {'\0'};
    int scannedUsersNameSuccesfully = -1;
    
    printf("Welcome to SafeCracker! If you guess the code to an evil billionaire's safe, everything inside is yours\nYou have 3 chances to guess correctly.\nSo we know who to make the check out to in the event you guess correctly, please tell us your name.\n");
    printf("Enter name:\n");
    
    while (scannedUsersNameSuccesfully != 1) {
        scannedUsersNameSuccesfully = takeInAString(user);
    }
    
    printf("Nice to meet you, %s\n.", user);
    
    gameplay();
    
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

void gameplay() {
    
    int combination[4] = {0};
    getNewCombination(combination);

}
