
#include <stdio.h>
#include <stdlib.h>
#include "board.h"

//Ends the game, giving the final configuration
void terminateGame (char **A, int x, int y){

    printf("Game over!\n");
    printf("Final configuration:\n");
    printBoard(A, x, y);

}//terminateGame

//PlayOne loops through the new Array setting the element to 0 or 1 depending
//on the names, also gives the termination conditions needed
void PlayOne(char **old, char **new, int x, int y){

    int occupied = 0;

    old = malloc(x * sizeof(int *));
    for (int row = 0; row < x; row++) {
        old[row] = malloc(y * sizeof(int));
    }

    new = malloc(x * sizeof(int));
    for (int row = 0; row < x; row++) {
        new[row] =  malloc(y * sizeof(int));
    }



    for (int row = 0; row < x; row++) {
        for (int column = 0; column < y; column++) {
            old[row][column] = 'o';
        }
    }

    for (int row = 0; row < x; row++) {
        for (int column = 0; column < y; column++) {
            new[row][column] = 'o';
        }
    }

    for (int row = 0; row < x; row++) {
        for (int column = 0; column < y; column++) {

            occupied = 0;

            for (int j = -1; j < 2; j++) {
                for (int i = -1; i < 2; i++) {
                    if((row + j) < 0 || (row + j) >= x)
                        continue;
                    if((column + j) < 0 || (row + j) >= x)
                        continue;
                    if ((i != 0) && (j != 0) && (old[(row + j) % y][(column + i) % x]))
                        occupied++;
                }
            }
        }
    }


    for (int row = 0; row < x; row++) {
        for (int column = 0; column < y; column++) {

            if(old[row][column] == 1){
                if((occupied < 2) || (occupied > 3))
                    new[row][column] = 'o';
                else
                    new[row][column] = 'x';
            }
        }
    }

    //to terminate

    int sum = 0;
    for (int row = 0; row < x; row++) {
        for (int column = 0; column < y; column++) {
            sum = sum + new[row][column];
        }
    }

    if(sum == 0){
        terminateGame(new, x, y);
        printf("All organisms died\n");
    }


    if(compareArrays(old, new, x, y) == 0){
        terminateGame(new, x, y);
        printf("Pattern repeated\n");
    }


}//PlayOne



