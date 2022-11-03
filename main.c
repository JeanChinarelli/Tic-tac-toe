#include <stdio.h> 
#include <stdlib.h>

int main(){
    int victory, line, column, repeat, x, error;
    char game[3][3] = {}; // Initializing the "game" array to empty, to print the board for the players more simply

    do{
        // Initializing variables to prevent possible bugs
        victory = 0;
        x=0;

        printf("----------------------- HASH GAME -----------------------");
        printf("\n HOW TO PLAY: \n 1 - You only can use numbers");
        printf("\n 3 - X plays first");
        printf("\n 2 - Choose your position: line and column\n");

        printf("\n Exemple: X choose: line = 2 / column = 3");
        printf("\n O choose: line = 3 / column = 1\n");
        printf("\n    1   2    3 ");
        printf("\n 1    |    |   ");
        printf("\n  --------------");
        printf("\n 2    |    | X ");
        printf("\n  --------------");
        printf("\n 3  O |    |   \n\n");
        system("pause");

        do{
            x++; // adding the value of x, to make the shifts between X and O
            system("CLS"); // Cleaning the screen to prevent it from getting polluted

            printf("----------------------- HASH GAME -----------------------");
            /// SHOWING THE BOARD TO PLAYERS
            printf("\n     1    2    3 ");
            printf("\n 1  %2c | %2c | %2c  ", game[0][0], game[0][1], game[0][2]);
            printf("\n  ----------------");
            printf("\n 2  %2c | %2c | %2c  ", game[1][0], game[1][1], game[1][2]);
            printf("\n  ----------------");
            printf("\n 3  %2c | %2c | %2c  ", game[2][0], game[2][1], game[2][2]);
            printf("\n\n");

            do{
                printf("\nChoose a line:");
                scanf("%d", &line);
                line--; // correcting the inserted position
                printf("\nChoose a column:");
                scanf("%d", &column);
                column--; // correcting the inserted position

                /* checking the positions, if it is already filled, 
                *   the loop will continue until a valid position is entered
                */
                if(game[line][column]=='X' || game[line][column]=='O'){
                    printf("\nERROR!!! INVALID POSITION!!!\nThe position: line=%d / column=%d is invalid", line++, column++);
                    printf("\nChoose a empty position!\n");
                    error=1;
                }
                else{
                    error=0;
                }
            }while(error==1);
            
            // checking if the player is X or O 
            if(x%2!=0){
                game[line][column] = 'X';
            } else{
                game[line][column] = 'O';
            }

            /// -------------------------- CHEKING X's WIN -------------------------------

            // IF X WON BY FIRST LINE, COLUMN AND DIAGONAL
            if(game[0][0] == 'X'){
                if(game[0][1] == 'X' && game[0][2] == 'X')
                    victory =1;
                if(game[1][1] == 'X' && game[2][2] == 'X')
                    victory = 1;
                if(game[1][0] == 'X' && game[2][0] == 'X')
                    victory = 1;
            }

            // IF X WON BY THE SECOND LINE
            if(game[1][0] == 'X'){
                if(game[1][1] == 'X' && game[1][2] == 'X')
                    victory = 1;
            }

            // IF X WON BY THE THIRD LINE
            if(game[2][0]=='X'){
                if(game[2][1] == 'X' && game[2][2] == 'X')
                    victory = 1;
            }

            // IF X WON BY THE SECOND COLUMN
            if(game[0][1] == 'X'){
                if(game[1][1] == 'X' && game[2][1] == 'X')
                    victory = 1;
            }

            // IF X WON BY THE THIRD COLUMN AND SECONDARY DIAGONAL
            if(game[0][2] == 'X'){
                if(game[1][2] == 'X' && game[2][2] == 'X')
                    victory = 1;
                if(game[1][1] == 'X' && game[2][0] == 'X')
                    victory = 1;
            }

            /// -------------------------- CHECKING VICTORY OF THE O (circle) -------------------------------
            
            // IF "O" WON IT BY FIRST LINE, COLUMN AND DIAGONAL
            if(game[0][0] == 'O'){
                if(game[0][1] == 'O' && game[0][2] == 'O')
                    victory =2;
                if(game[1][0] == 'O' && game[2][0] == 'O')
                    victory = 2;
                if(game[1][1] == 'O' && game[2][2] == 'O')
                    victory = 2;
            }

            /// IF "O" WON IT BY THE SECOND LINE
            if(game[1][0] == 'O'){
                if(game[1][1] == 'O' && game[1][2] == 'O')
                    victory = 2;
            }

            /// IF "O" WON IT BY THE THIRD LINE
            if(game[2][0] == 'O'){
                if(game[2][1] == 'O' && game[2][2] == 'O')
                    victory = 2;
            }

            /// IF "O" WON IT BY THE SECOND COLUMN
            if(game[0][1] == 'O'){
                if(game[1][1] == 'O' && game[2][1] == 'O')
                    victory = 2;
            }

            /// IF "O" WON IT BY THE THIRD COLUMN AND SECONDARY DIAGONAL
            if(game[0][2] == 'O'){
                if(game[1][2] == 'O' && game[2][2] == 'O')
                    victory = 2;
                if(game[1][1] == 'O' && game[2][0] == 'O')
                    victory = 2;
            }

            // checking if any player won
            if(victory!=1 && victory!=2){ 
                /* If no player won and the maximum number of moves (9 moves) has already been reached,
                *    then the "victory" variable will receive the value 3
                */
                if(x==9)
                    victory=3;
            }

        }while(victory == 0);

        // SHOWING THE BOARD TO PLAYERS, TO SEE WHO WON
        printf("\n     1    2    3 ");
        printf("\n 1|  %c | %c | %c  ", game[0][0], game[0][1], game[0][2]);
        printf("\n   ---------------");
        printf("\n 2|  %c | %c | %c  ", game[1][0], game[1][1], game[1][2]);
        printf("\n   ---------------");
        printf("\n 3|  %c | %c | %c  ", game[2][0], game[2][1], game[2][2]);
        printf("\n\n");

        // Checking whose victory was (1=X / 2=O) 
        if(victory == 1)
            printf("\n VICTORY OF THE X!!!\n\n");
        else if(victory==2)
            printf("\n VICTORY OF THE CIRCLE!!!\n\n");
        else // if it is neither of the two values, then it will be a tie
            printf("\n DRAW!!!\n\n");
        
        system("pause");
        system("CLS");
        printf("\n\n\tPlay again? 1 - yes // 2 - no: ");
        scanf("%d", &repeat);
    }while(repeat==1);
    return 0;
}