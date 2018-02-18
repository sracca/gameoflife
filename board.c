
#include <stdio.h>
#include<stdlib.h>

//using input file given, finds the dimensions of the file to create an array based on the file
//then uses the array made for the input to center it within the board
void fillBoard (char argument[], char **grid, int x, int y){

    FILE *file;
    file = fopen(argument, "r");

    if(file == NULL)
        exit(-1);

    int a =  getc(file);


    int newLine;
    newLine = 0;

    int longLine;
    longLine = 0;

    int line;
    line = 0;


    while(a != EOF){
        if(a == '\n'){
            newLine++;
            if(longLine < line){
                longLine = line;
            }
            line = 0;
        }

        if(a == 1)
           line++;
        if(a == 0)
            line++;

        a = getc(file);
    }


    int row, col;
    col = newLine;
    row = longLine;

    rewind(file);

    int created[row][col];

    for (int k = 0; k < row; k++) {
        for (int i = 0; i < col; i++) {
            created[k][i] = 0;
        }
    }


    for (int l = 0; l < row; l++) {

        if(a == EOF)
            l = row;

        a = getc(file);
        int m = 0;

        while(a != '\n' && a != EOF){
            if(a == 1)
                created[l][m] = 1;
            m++;

            if(a == 0)
                created[l][m] = 0;
            m++;

            a = getc(file);
        }
    }

    int t, q;
    t = q = 0;

    for (int j = (x/2)- (row/2); j < (x/2) + (row/2); j++) {
        for (int i = (y / 2) - (col / 2); i < (y / 2) + (col / 2); i++) {
            grid[i][j] = created[t][q];
            t++;
        }
        q++;
    }

    fclose(file);

}//fillBoard

//compareArrays evaluates an array element by element, going first
//through the row and then the column, using an if statement that if
//the elements match, return 0, and if it is different to return 1
int compareArrays(char **arrayOne, char **arrayTwo, int x , int y){

    int number = 0;

    for (int row = 0; row < x; row++) {
        for (int column = 0; column < y; column++) {

            if(arrayOne[row][column] == arrayTwo[row][column])
                number = 0;
            else
                number = 1;
        }
    }

    return number;

}//compareArrays


//Prints the current output of the board
void printBoard(char **arrayOne, int x, int y){

    for (int row = 0; row < x; row++) {

        printf("\n");

        for (int column = 0; column < y; column++) {
            if(arrayOne[row][column] == 0)
                printf("o");
            else
                printf("x");
        }
    }

    printf("\n");

}

//printBoard


