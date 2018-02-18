
#include "board.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int x;
int y;
int gens;



int gensPlayed;

char **A;
char **B;
char **C;


int main(int argc, char *argv[]){

    printf("%s\n", argv[1]);
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    gens = atoi(argv[3]);


    A = malloc(x * sizeof(int *));
    B = malloc(x * sizeof(int *));
    C = malloc(x * sizeof(int *));
    for (int row = 0; row < x; row++) {
        A[row] = malloc(y * sizeof(int));
        B[row] = malloc(y * sizeof(int));
        C[row] = malloc(y * sizeof(int));
    }

    fillBoard(argv[4], A, x, y);

    if(argc == 7){

        if(*argv[5] == 'y'){

            for (int cycles = 0; cycles <= gens; cycles++) {

                PlayOne(A, B, x, y);

                gensPlayed++;

                printBoard(B, x, y);

                PlayOne(B, C, x, y);

                gensPlayed++;

                printBoard(C, x, y);


                PlayOne(C, A, x, y);

                gensPlayed++;
                printBoard(A, x, y);

            }



        }


        if(*argv[5] == 'n'){

            for (int cycles = 0; cycles <= gens; cycles++) {

                PlayOne(A, B, x, y);

                gensPlayed++;



                PlayOne(B, C, x, y);

                gensPlayed++;

                PlayOne(C, A, x, y);
                gensPlayed++;


            }

        }

        if(*argv[6] == 'y'){
            getchar();
        }

        printf("Generations Played: %d\n", gensPlayed);

    }


    if(argc == 6) {

        if (*argv[5] == 'y') {

            for (int cycles = 0; cycles <= gens; cycles++) {

                PlayOne(A, B, x, y);
                gensPlayed++;
                printBoard(B, x, y);

                PlayOne(B, C, x, y);

                gensPlayed++;

                printBoard(C, x, y);


                PlayOne(C, A, x, y);

                gensPlayed++;
                printBoard(A, x, y);


            }

        }


        if (*argv[5] == 'n') {
            PlayOne(A, B, x, y);
            gensPlayed++;




            PlayOne(B, C, x, y);

            gensPlayed++;






            PlayOne(C, A, x, y);

            gensPlayed++;



            }
        }


        printf("Generations Played: %d\n", gensPlayed);



    if(argc == 5){

        for (int cycles = 0; cycles <= gens; cycles++) {
            PlayOne(A, B, x, y);


            gensPlayed++;





            PlayOne(B, C, x, y);

            gensPlayed++;





            PlayOne(C, A, x, y);

            gensPlayed++;



        }

        printf("Generations Played: %d\n", gensPlayed);

}

}
