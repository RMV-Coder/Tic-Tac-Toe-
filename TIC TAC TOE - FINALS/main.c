#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 9
#define TRUE 1
#define FALSE 0
// Global Variables
char currentTable[SIZE][SIZE]={" ", " ", " ", " ", " ", " ", " ", " ", " "};
int win = FALSE;
int player, modeAI;
void mainMenu() //Function for the main menu screen
{
    printf("\n\n\n\n\n\n\t\t\t\t\t\t     TIC TAC TOE\n\n");
    printf("\t\t\t\t\t      Use 1 to 9 to select a cell.\n");
    printf("\t\t\t\t\t      Press any key to start...");
}
int playWith() //Function for the game mode
{
    system("cls");//clear screen. Used to refresh console.
    int mode;
    printf("\n\n\n\n\n\n\t\t\t\t\t\tChoose a game mode.\n\t\t\t\t\t\tEnter:\n\t\t\t\t\t\t1 to play with a friend.\n\t\t\t\t\t\t2 to play with a computer.");//Prompt
    scanf("%i", &mode);// We'll expect a 1 or 2 from the user.
    return mode;
}
int computerMatch(int *play) //Function for the player versus computer mode
{
    *play = 1;
    int playerScore=0;
    int computerScore=0;
    int tieCount=0;
    int score=0;
    int entPlaying = *play;
    modeAI = TRUE;
    int winner;
    while(score != 10)// without this while loop, the game will end after 1 win or tie.
    {
        win=FALSE;
        for(int i = 0; i<9; i++)// This for loop will reset the array everytime we get a winner or a tie. In other words, remove the X's and O's from the grid.
        {
            strncpy(currentTable[i], " ", 2);
        }
        do
        {
            frame();// call this function to refresh and display the grid and current strings within our array(X or O).
            logConsole(&entPlaying, &playerScore, &computerScore, &tieCount, &modeAI);
            selectCellComputer(&entPlaying);// player input function for either player or computer.
            frame();// call this function again before checking for a winner.
            checkForWinner(&playerScore, &computerScore, &tieCount);// Call this function to check for a winner.
            frame();
            if(playerScore < computerScore)
            {
                score = computerScore;
            }
            else if(playerScore > computerScore)
            {
                score = playerScore;
            }
        } while(win==FALSE);
        if (win == TRUE)
        {
            entPlaying = TRUE;
        }
    }
    if(playerScore  == 10)
    {
        winner = 1;
    }
    else if(computerScore  == 10)
    {
        winner = 2;
    }
    return winner;
}
int friendlyMatch(int *player) //Function for the player versus player mode
{
    *player = 1;
    int p1Score=0;
    int p2Score=0;
    int score=0;
    int tieCounter=0;
    int p = *player;
    int winner;
    while(score != 10)// without this while loop, the game will end after 1 win or tie.
    {
        win=FALSE;
        for(int i = 0; i<9; i++)// This for loop will reset the array everytime we get a winner or a tie. In other words, remove the X's and O's from the grid.
        {
            strncpy(currentTable[i], " ", 2);
        }
        do
        {
            frame();// call this function to refresh and display the grid and current strings within our array(X or O).
            logConsole(&p, &p1Score, &p2Score, &tieCounter, &modeAI);
            selectCellPlayer(&p);// player input function for either player 1 or player 2.
            frame();// call this function again before checking for a winner.
            checkForWinner(&p1Score, &p2Score, &tieCounter);// Call this function to check for a winner.
            if(p1Score < p2Score)
            {
                score = p2Score;
            }
            else if(p1Score > p2Score)
            {
                score = p1Score;
            }
        } while(win==FALSE);
    }
    if(p1Score  == 10)
    {
        winner = 1;
    }
    else if(p2Score  == 10)
    {
        winner = 2;
    }
    return winner;
}
int checkForWinner(int *p1, int *p2, int *tie) //Function that will check for a winner
{
    // FOR X
    // Horizontal
    if((strcmp(currentTable[0],"X")== 0) && (strcmp(currentTable[1],"X")== 0) && (strcmp(currentTable[2],"X")== 0))//check first row
    {
        win=TRUE;
        *p1+=1;

    }
    else if((strcmp(currentTable[3],"X")== 0) && (strcmp(currentTable[4],"X")== 0) && (strcmp(currentTable[5],"X")== 0))//check second row
    {
        win=TRUE;
        *p1+=1;
    }
    else if((strcmp(currentTable[6],"X")== 0) && (strcmp(currentTable[7],"X")== 0) && (strcmp(currentTable[8],"X")== 0))//check third row
    {
        win=TRUE;
        *p1+=1;
    }
    // Vertical
    else if((strcmp(currentTable[0],"X")== 0) && (strcmp(currentTable[3],"X")== 0) && (strcmp(currentTable[6],"X")== 0))//check first column
    {
        win=TRUE;
        *p1+=1;
    }
    else if((strcmp(currentTable[1],"X")== 0) && (strcmp(currentTable[4],"X")== 0) && (strcmp(currentTable[7],"X")== 0))//check second column
    {
        win=TRUE;
        *p1+=1;
    }
    else if((strcmp(currentTable[2],"X")== 0) && (strcmp(currentTable[5],"X")== 0) && (strcmp(currentTable[8],"X")== 0))//check third column
    {
        win=TRUE;
        *p1+=1;
    }
    // Diagonals
    else if((strcmp(currentTable[0],"X")== 0) && (strcmp(currentTable[4],"X")== 0) && (strcmp(currentTable[8],"X")== 0))//check diagonal (backward slash)
    {
        win=TRUE;
        *p1+=1;
    }
    else if((strcmp(currentTable[2],"X")== 0) && (strcmp(currentTable[4],"X")== 0) && (strcmp(currentTable[6],"X")== 0))//check diagonal (forward slash)
    {
        win=TRUE;
        *p1+=1;
    }

    // FOR O
    // Horizontal
    else if((strcmp(currentTable[0],"O")== 0) && (strcmp(currentTable[1],"O")== 0) && (strcmp(currentTable[2],"O")== 0))//check first row
    {
        win=TRUE;
        *p2+=1;
    }
    else if((strcmp(currentTable[3],"O")== 0) && (strcmp(currentTable[4],"O")== 0) && (strcmp(currentTable[5],"O")== 0))//check second row
    {
        win=TRUE;
        *p2+=1;
    }
    else if((strcmp(currentTable[6],"O")== 0) && (strcmp(currentTable[7],"O")== 0) && (strcmp(currentTable[8],"O")== 0))//check third row
    {
        win=TRUE;
        *p2+=1;
    }
    // Vertical
    else if((strcmp(currentTable[0],"O")== 0) && (strcmp(currentTable[3],"O")== 0) && (strcmp(currentTable[6],"O")== 0))//check first column
    {
        win=TRUE;
        *p2+=1;
    }
    else if((strcmp(currentTable[1],"O")== 0) && (strcmp(currentTable[4],"O")== 0) && (strcmp(currentTable[7],"O")== 0))//check second column
    {
        win=TRUE;
        *p2+=1;
    }
    else if((strcmp(currentTable[2],"O")== 0) && (strcmp(currentTable[5],"O")== 0) && (strcmp(currentTable[8],"O")== 0))//check third column
    {
        win=TRUE;
        *p2+=1;
    }
    // Diagonals
    else if((strcmp(currentTable[0],"O")== 0) && (strcmp(currentTable[4],"O")== 0) && (strcmp(currentTable[8],"O")== 0))//check diagonal (backward slash)
    {
        win=TRUE;
        *p2+=1;
    }
    else if((strcmp(currentTable[2],"O")== 0) && (strcmp(currentTable[4],"O")== 0) && (strcmp(currentTable[6],"O")== 0))//check diagonal (forward slash)
    {
        win=TRUE;
        *p2+=1;
    }

        //For tie
    if((win == FALSE)&&!(strcmp(currentTable[0], " ") == 0) && !(strcmp(currentTable[1], " ") == 0) && !(strcmp(currentTable[2], " ") == 0) && !(strcmp(currentTable[3], " ") == 0) && !(strcmp(currentTable[4], " ") == 0) && !(strcmp(currentTable[5], " ") == 0) && !(strcmp(currentTable[6], " ") == 0) && !(strcmp(currentTable[7], " ") == 0) && !(strcmp(currentTable[8], " ") == 0))
    {
        win=TRUE;
        *tie+=1;
    }
    return win;
}
int calculationsAI(int *done) //Function that will analyze what move the computer will do
{
    *done = FALSE;
    int d = *done;
    do
    {
        //IF COMPUTER CAN SCORE, THEN SCORE

        //CHECKING FROM TOP-LEFT
        // posible 0 1 2 combinations - horizontal
        if(strcmp(currentTable[0], "O") == 0)
        {
            if(strcmp(currentTable[1], "O") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[2], "O") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
        }
        // Possible 0 3 6 combinations - vertical
        if(strcmp(currentTable[0], "O") == 0)
        {
            if(strcmp(currentTable[3], "O") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[6], "O") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
        }
        // Possible 0 4 8 combinations - Diagonal
        if(strcmp(currentTable[0], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM TOP
        // posible 0 1 2 combinations - horizontal
        if(strcmp(currentTable[1], "O") == 0)
        {
            if(strcmp(currentTable[0], "O") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[2], "O") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
        }
        // Possible 1 4 7 combinations - vertical
        if(strcmp(currentTable[1], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[7], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM TOP-RIGHT
        // posible 0 1 2 combinations - horizontal
        if(strcmp(currentTable[2], "O") == 0)
        {
            if(strcmp(currentTable[1], "O") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[0], "O") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
        }
        // Possible 2 5 8 combinations - vertical
        if(strcmp(currentTable[2], "O") == 0)
        {
            if(strcmp(currentTable[5], "O") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "O") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
        }
        // Possible 2 4 6 combinations - Diagonal
        if(strcmp(currentTable[2], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[6], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM LEFT
        // posible 3 4 5 combinations - horizontal
        if(strcmp(currentTable[3], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[5], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }
        // Possible 0 3 6 combinations - vertical
        if(strcmp(currentTable[3], "O") == 0)
        {
            if(strcmp(currentTable[0], "O") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[6], "O") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM CENTER
        // posible 3 4 5 combinations - horizontal
        if(strcmp(currentTable[4], "O") == 0)
        {
            if(strcmp(currentTable[3], "O") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[5], "O") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
        }
        // Possible 1 4 7 combinations - vertical
        if(strcmp(currentTable[4], "O") == 0)
        {
            if(strcmp(currentTable[1], "O") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[7], "O") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
        }
        // Possible 0 4 8 combinations - Diagonal
        if(strcmp(currentTable[4], "O") == 0)
        {
            if(strcmp(currentTable[0], "O") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "O") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
        }
        // Possible 2 4 6 combinations - Diagonal
        if(strcmp(currentTable[4], "O") == 0)
        {
            if(strcmp(currentTable[2], "O") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[6], "O") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM RIGHT
        // posible 3 4 5 combinations - horizontal
        if(strcmp(currentTable[5], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[3], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }
        // Possible 2 5 8 combinations - vertical
        if(strcmp(currentTable[5], "O") == 0)
        {
            if(strcmp(currentTable[2], "O") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "O") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM BOTTOM-LEFT
        // posible 6 7 8 combinations - horizontal
        if(strcmp(currentTable[6], "O") == 0)
        {
            if(strcmp(currentTable[7], "O") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "O") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
        }
        // Possible 0 3 6 combinations - vertical
        if(strcmp(currentTable[6], "O") == 0)
        {
            if(strcmp(currentTable[3], "O") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[0], "O") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
        }
        // Possible 6 4 2 combinations - Diagonal
        if(strcmp(currentTable[6], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[2], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM BOTTOM
        // posible 6 7 8 combinations - horizontal
        if(strcmp(currentTable[7], "O") == 0)
        {
            if(strcmp(currentTable[6], "O") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "O") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
        }
        // Possible 1 4 7 combinations - vertical
        if(strcmp(currentTable[7], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[1], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM BOTTOM-RIGHT
        // posible 6 7 8 combinations - horizontal
        if(strcmp(currentTable[8], "O") == 0)
        {
            if(strcmp(currentTable[6], "O") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[7], "O") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
        }
        // Possible 2 5 8 combinations - vertical
        if(strcmp(currentTable[8], "O") == 0)
        {
            if(strcmp(currentTable[5], "O") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[2], "O") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
        }
        // Possible 0 4 8 combinations - Diagonal
        if(strcmp(currentTable[8], "O") == 0)
        {
            if(strcmp(currentTable[4], "O") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[0], "O") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }


        //IF COMPUTER CAN'T SCORE, THEN BLOCK

        //CHECKING FROM TOP-LEFT
        // posible 0 1 2 combinations - horizontal
        if(strcmp(currentTable[0], "X") == 0)
        {
            if(strcmp(currentTable[1], "X") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
        }
        // Possible 0 3 6 combinations - vertical
        if(strcmp(currentTable[0], "X") == 0)
        {
            if(strcmp(currentTable[3], "X") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
        }
        // Possible 0 4 8 combinations - Diagonal
        if(strcmp(currentTable[0], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            // Possible 2 4 6 or 0 4 8 combination
            if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM TOP
        // posible 0 1 2 combinations - horizontal
        if(strcmp(currentTable[1], "X") == 0)
        {
            if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
        }
        // Possible 1 4 7 combinations - vertical
        if(strcmp(currentTable[1], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[7], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM TOP-RIGHT
        // posible 0 1 2 combinations - horizontal
        if(strcmp(currentTable[2], "X") == 0)
        {
            if(strcmp(currentTable[1], "X") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
        }
        // Possible 2 5 8 combinations - vertical
        if(strcmp(currentTable[2], "X") == 0)
        {
            if(strcmp(currentTable[5], "X") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
        }
        // Possible 2 4 6 combinations - Diagonal
        if(strcmp(currentTable[2], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            // Possible 2 4 6 or 0 4 8 combination
            if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM LEFT
        // posible 3 4 5 combinations - horizontal
        if(strcmp(currentTable[3], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[5], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }
        // Possible 0 3 6 combinations - vertical
        if(strcmp(currentTable[3], "X") == 0)
        {
            if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"X",2);
                    break;
                }
            }
            else if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM CENTER
        // posible 3 4 5 combinations - horizontal
        if(strcmp(currentTable[4], "X") == 0)
        {
            if(strcmp(currentTable[3], "X") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[5], "X") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
        }
        // Possible 1 4 7 combinations - vertical
        if(strcmp(currentTable[4], "X") == 0)
        {
            if(strcmp(currentTable[1], "X") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[7], "X") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
        }
        // Possible 0 4 8 combinations - Diagonal
        if(strcmp(currentTable[4], "X") == 0)
        {
            if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
        }
        // Possible 2 4 6 combinations - Diagonal
        if(strcmp(currentTable[4], "X") == 0)
        {
            if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM RIGHT
        // posible 3 4 5 combinations - horizontal
        if(strcmp(currentTable[5], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[3], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }
        // Possible 2 5 8 combinations - vertical
        if(strcmp(currentTable[5], "X") == 0)
        {
            if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM BOTTOM-LEFT
        // posible 6 7 8 combinations - horizontal
        if(strcmp(currentTable[6], "X") == 0)
        {
            if(strcmp(currentTable[7], "X") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
        }
        // Possible 0 3 6 combinations - vertical
        if(strcmp(currentTable[6], "X") == 0)
        {
            if(strcmp(currentTable[3], "X") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[3], " ") == 0)
                {
                    strncpy(currentTable[3],"O",2);
                    break;
                }
            }
        }
        // Possible 6 4 2 combinations - Diagonal
        if(strcmp(currentTable[6], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            // Possible 2 4 6 or 0 4 8 combination
            if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM BOTTOM
        // posible 6 7 8 combinations - horizontal
        if(strcmp(currentTable[7], "X") == 0)
        {
            if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[8], " ") == 0)
                {
                    strncpy(currentTable[8],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[8], "X") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
        }
        // Possible 1 4 7 combinations - vertical
        if(strcmp(currentTable[7], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[1], " ") == 0)
                {
                    strncpy(currentTable[1],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[1], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //CHECKING FROM BOTTOM-RIGHT
        // posible 6 7 8 combinations - horizontal
        if(strcmp(currentTable[8], "X") == 0)
        {
            if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[7], " ") == 0)
                {
                    strncpy(currentTable[7],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[7], "X") == 0)
            {
                if(strcmp(currentTable[6], " ") == 0)
                {
                    strncpy(currentTable[6],"O",2);
                    break;
                }
            }
        }
        // Possible 2 5 8 combinations - vertical
        if(strcmp(currentTable[8], "X") == 0)
        {
            if(strcmp(currentTable[5], "X") == 0)
            {
                if(strcmp(currentTable[2], " ") == 0)
                {
                    strncpy(currentTable[2],"O",2);
                    break;
                }
            }
            else if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[5], " ") == 0)
                {
                    strncpy(currentTable[5],"O",2);
                    break;
                }
            }
        }
        // Possible 0 4 8 combinations - Diagonal
        if(strcmp(currentTable[8], "X") == 0)
        {
            if(strcmp(currentTable[4], "X") == 0)
            {
                if(strcmp(currentTable[0], " ") == 0)
                {
                    strncpy(currentTable[0],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[0], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            // Possible 2 4 6 or 0 4 8 combination
            if(strcmp(currentTable[2], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
            if(strcmp(currentTable[6], "X") == 0)
            {
                if(strcmp(currentTable[4], " ") == 0)
                {
                    strncpy(currentTable[4],"O",2);
                    break;
                }
            }
        }

        //IF GAME JUST STARTED
        //CHECKING FROM TOP-LEFT
        if(strcmp(currentTable[0], "X") == 0)
        {
            // posible 0 1 2 combinations - horizontal
            if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }

            // posible 0 3 6 combinations - vertical
            else if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }

            // posible 0 4 8 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }
        }

        //CHECKING FROM TOP
        if(strcmp(currentTable[1], "X") == 0)
        {
            // posible 0 1 2 combinations - horizontal
            if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }

            // posible 1 4 7 combinations - vertical
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }
        }

        //CHECKING FROM TOP-RIGHT
        if(strcmp(currentTable[2], "X") == 0)
        {
            // posible 0 1 2 combinations - horizontal
            if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }

            // posible 2 5 8 combinations - vertical
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }

            // posible 2 4 6 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
        }

        //CHECKING FROM LEFT
        if(strcmp(currentTable[3], "X") == 0)
        {
            // posible 3 4 5 combinations - horizontal
            if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }

            // posible 0 3 6 combinations - vertical
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
        }

        //CHECKING FROM MID
        if(strcmp(currentTable[4], "X") == 0)
        {
            // posible 3 4 5 combinations - horizontal
            if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }

            // posible 1 4 7 combinations - vertical
            else if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
            else if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }

            // posible 0 4 8 combinations - diagonal
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }

            // posible 2 4 6 combinations - diagonal
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }
        }

        //CHECKING FROM RIGHT
        if(strcmp(currentTable[5], "X") == 0)
        {
            // posible 3 4 5 combinations - horizontal
            if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }

            // posible 2 5 8 combinations - vertical
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }
        }

        //CHECKING FROM BOTTOM-LEFT
        if(strcmp(currentTable[6], "X") == 0)
        {
            // posible 6 7 8 combinations - horizontal
            if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }

            // posible 0 3 6 combinations - vertical
            else if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }

            // posible 6 4 2 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }
        }

        //CHECKING FROM BOTTOM
        if(strcmp(currentTable[7], "X") == 0)
        {
            // posible 6 7 8 combinations - horizontal
            if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }

            // posible 1 4 7 combinations - vertical
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
        }

        //CHECKING FROM TOP-RIGHT
        if(strcmp(currentTable[8], "X") == 0)
        {
            // posible 6 7 8 combinations - horizontal
            if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }

            // posible 2 5 8 combinations - vertical
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }

            // posible 0 4 8 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }
        }

        //IF COMPUTER CAN'T SCORE AND BLOCK, FORM A POSSIBLE FIGURE TO SCORE
        //CHECKING FROM TOP-LEFT
        if(strcmp(currentTable[0], "O") == 0)
        {
            // posible 0 1 2 combinations - horizontal
            if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }

            // posible 0 3 6 combinations - vertical
            else if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }

            // posible 0 4 8 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }
        }

        //CHECKING FROM TOP
        if(strcmp(currentTable[1], "O") == 0)
        {
            // posible 0 1 2 combinations - horizontal
            if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }

            // posible 1 4 7 combinations - vertical
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }
        }

        //CHECKING FROM TOP-RIGHT
        if(strcmp(currentTable[2], "O") == 0)
        {
            // posible 0 1 2 combinations - horizontal
            if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }

            // posible 2 5 8 combinations - vertical
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }

            // posible 2 4 6 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
        }

        //CHECKING FROM LEFT
        if(strcmp(currentTable[3], "O") == 0)
        {
            // posible 3 4 5 combinations - horizontal
            if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }

            // posible 0 3 6 combinations - vertical
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
        }

        //CHECKING FROM MID
        if(strcmp(currentTable[4], "O") == 0)
        {
            // posible 3 4 5 combinations - horizontal
            if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }

            // posible 1 4 7 combinations - vertical
            else if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
            else if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }

            // posible 0 4 8 combinations - diagonal
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }

            // posible 2 4 6 combinations - diagonal
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }
        }

        //CHECKING FROM RIGHT
        if(strcmp(currentTable[5], "O") == 0)
        {
            // posible 3 4 5 combinations - horizontal
            if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }

            // posible 2 5 8 combinations - vertical
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }
        }

        //CHECKING FROM BOTTOM-LEFT
        if(strcmp(currentTable[6], "O") == 0)
        {
            // posible 6 7 8 combinations - horizontal
            if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }

            // posible 0 3 6 combinations - vertical
            else if(strcmp(currentTable[3], " ") == 0)
            {
                strncpy(currentTable[3],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }

            // posible 6 4 2 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }
        }

        //CHECKING FROM BOTTOM
        if(strcmp(currentTable[7], "O") == 0)
        {
            // posible 6 7 8 combinations - horizontal
            if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }
            else if(strcmp(currentTable[8], " ") == 0)
            {
                strncpy(currentTable[8],"O",2);
                break;
            }

            // posible 1 4 7 combinations - vertical
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[1], " ") == 0)
            {
                strncpy(currentTable[1],"O",2);
                break;
            }
        }

        //CHECKING FROM TOP-RIGHT
        if(strcmp(currentTable[8], "O") == 0)
        {
            // posible 6 7 8 combinations - horizontal
            if(strcmp(currentTable[7], " ") == 0)
            {
                strncpy(currentTable[7],"O",2);
                break;
            }
            else if(strcmp(currentTable[6], " ") == 0)
            {
                strncpy(currentTable[6],"O",2);
                break;
            }

            // posible 2 5 8 combinations - vertical
            else if(strcmp(currentTable[5], " ") == 0)
            {
                strncpy(currentTable[5],"O",2);
                break;
            }
            else if(strcmp(currentTable[2], " ") == 0)
            {
                strncpy(currentTable[2],"O",2);
                break;
            }

            // posible 0 4 8 combinations - diagonal
            else if(strcmp(currentTable[4], " ") == 0)
            {
                strncpy(currentTable[4],"O",2);
                break;
            }
            else if(strcmp(currentTable[0], " ") == 0)
            {
                strncpy(currentTable[0],"O",2);
                break;
            }
        }
    }while(*done = FALSE);
    d = TRUE;
    return d;
}
int selectCellPlayer(int *player) //Function that will process moves of both players
{
    int turn = TRUE;
    int cell = 0;
    int opt= 0;
    while(turn == TRUE)
    {
        scanf("%i", &opt);// We'll expect a number from the current player. (1 to 9) are the expected values.
        if(opt >= 1 && opt <= 9)
        {
            for(int i = 1; i<=9; i++)// We'll use for loop to compress the code.
            {
                if(opt == i)
                {
                    cell = opt-1;// We'll subtract 1 since we only accept 1-9 as our input from the user while indexes of arrays will start at 0. The indexes we'll work on are 0-8...
                    if(strcmp(currentTable[cell]," ") == 0)
                    {
                        //printf("turn ends.\n");
                        if(*player==1)// if player 1's turn.
                        {
                            strncpy(currentTable[cell],"X",2);// we will use strncpy(arrayName[index],"String to be stored on the chosen index", numberOfCharacters plus 1 for /0(must be within the allocated space to avoid overflow)]) to alter or change the string stored inside our array.
                            *player+=1;// increment. Since the current player is player 1, it will become player 2's turn next.
                        }
                        else if(*player==2)//if player 2's turn.
                        {
                            strncpy(currentTable[cell],"O",2);// we will use strncpy(arrayName[index],"String to be stored on the chosen index", numberOfCharacters plus 1 for /0(must be within the allocated space to avoid overflow)]) to alter or change the string stored inside our array.
                            *player-=1;// decrement. Since the current player is player 2, it will become player 1's turn next.
                        }
                        turn = FALSE;
                    }
                    else if((strcmp(currentTable[cell],"X") == 0)||(strcmp(currentTable[cell],"O") == 0))
                    {
                        printf("\t\t\t\tSelected cell is already occupied, choose another one.");
                        turn = TRUE;
                    }
                }
                else if(opt < 1 && opt > 9)
                {
                    printf("\t\tIncorrect input!\n");
                }
            }
        }
    }
    return turn;
}
int selectCellComputer(int *player) //Function that will process moves of both computer and player
{
    int turn = TRUE;
    int cell = 0;
    int opt= 0;
    int done;
    while(turn == TRUE)
    {
        if(*player == 1)
        {
            scanf("%i", &opt);// We'll expect a number from the current player. (1 to 9) are the expected values.
            if(opt >= 1 && opt <= 9)
            {
                for(int i = 1; i<=9; i++)// We'll use for loop to compress the code.
                {
                    if(opt == i)
                    {
                        cell = opt-1;// We'll subtract 1 since we only accept 1-9 as our input from the user while indexes of arrays will start at 0. The indexes we'll work on are 0-8...
                        if(strcmp(currentTable[cell]," ") == 0)
                        {
                            //printf("turn ends.\n");
                            if(*player==1)// if player 1's turn.
                            {
                                strncpy(currentTable[cell],"X",2);// we will use strncpy(arrayName[index],"String to be stored on the chosen index", numberOfCharacters plus 1 for /0(must be within the allocated space to avoid overflow)]) to alter or change the string stored inside our array.
                                *player+=1;// increment. Since the current player is player 1, it will become player 2's turn next.
                            }

                        }
                        else if((strcmp(currentTable[cell],"X") == 0)||(strcmp(currentTable[cell],"O") == 0))
                        {
                            printf("\t\t\t\tSelected cell is already occupied, choose another one.");
                            turn = TRUE;
                        }
                    }
                    else if(opt < 1 && opt > 9)
                    {
                        printf("\t\tIncorrect input!\n");
                    }
                }
            }
        }
        else if(*player==2)//if computer's turn.
        {
            int g = calculationsAI(&done);
            *player-= g;
            turn = FALSE;
        }

    }
    return turn;
}
void logConsole(int *playing, int *p1, int *p2, int *t, int *humanAI) //Function that will display the scoreboard and guide on how to play the game
{
    int cpu = *humanAI;
    if(cpu == TRUE)//Console log for Computer vs Human
    {
        printf("\n\t\t\t\tSCOREBOARD:\n\t\t\t\tPlayer(X): %i\tComputer(O): %i\tTie: %i", *p1, *p2, *t);// Console log for scoreboard.
        if(*playing == 1)
        {
            printf("\n\n\t\t\t\tHOW TO PLAY:");
            printf("\n\t\t\t\tEnter");
            printf("\n\t\t\t\t1 for top-left\t\t2 for top-mid\t\t3 for top-right");
            printf("\n\t\t\t\t4 for left\t\t5 for mid\t\t6 for right");
            printf("\n\t\t\t\t7 for bottom-left\t8 for bottom-mid\t9 for bottom-right");
            printf("\n\n\t\t\t\tYour turn...");// To know who's turn it is.
        }

    }
    else //Console log for Player 1 vs Player 2
    {

        printf("\n\t\t\t\tSCOREBOARD:\n\t\t\t\tPlayer 1(X): %i\tPlayer 2(O): %i\tTie: %i", *p1, *p2, *t);// Console log for scoreboard.
        printf("\n\n\t\t\t\tHOW TO PLAY:");
        printf("\n\t\t\t\tEnter");
        printf("\n\t\t\t\t1 for top-left\t\t2 for top-mid\t\t3 for top-right");
        printf("\n\t\t\t\t4 for left\t\t5 for mid\t\t6 for right");
        printf("\n\t\t\t\t7 for bottom-left\t8 for bottom-mid\t9 for bottom-right");
        printf("\n\n\t\t\t\tPlayer %i's turn...", *playing);// To know who's turn it is.
    }

}
int frame() //Function that will process the grid and its contents
{
    system("cls");// clear screen. We will use this to refresh the console.
    printf("\n\n");

    //Top - indexes 0 1 2
    printf("\t\t\t\t\t\t\t%c       %c\n",179,179);// 179 printed through a %c will give an output of an ASCII character, vertical line/s in this case.
    printf("\t\t\t\t\t\t    %s   %c   %s   %c   %s\n",currentTable[0], 179, currentTable[1], 179, currentTable[2]);// We will put the string(X or O) stored from our two-dimensional array named currentTable through the use of %s.
    printf("\t\t\t\t\t\t\t%c       %c\n",179,179);// 179 printed through a %c will give an output of an ASCII character, vertical line/s in this case.

    //horizontal line
    printf("\t\t\t\t\t\t ");
    for(int i = 0; i < 7; i++)
    {
        printf("%c",196);// 196 printed through a %c will give an output of an ASCII character, horizontal line/s in this case.
    }
    printf("%c",197);// 197 printed through a %c will give an output of an ASCII character, intersecting perpendicular lines in this case.
    for(int i = 0; i < 7; i++)
    {
        printf("%c",196);// 196 printed through a %c will give an output of an ASCII character, horizontal line/s in this case.
    }
    printf("%c",197);// 197 printed through a %c will give an output of an ASCII character, intersecting perpendicular lines in this case.
    for(int i = 0; i < 7; i++)
    {
        printf("%c",196);// 196 printed through a %c will give an output of an ASCII character, horizontal line/s in this case.
    }
    printf("\n");

    //Middle - indexes 3 4 5
    printf("\t\t\t\t\t\t\t%c       %c\n",179,179);// 179 printed through a %c will give an output of an ASCII character, vertical line/s in this case.
    printf("\t\t\t\t\t\t    %s   %c   %s   %c   %s\n",currentTable[3], 179, currentTable[4], 179, currentTable[5]);// We will put the string(X or O) stored from our two-dimensional array named currentTable through the use of %s.
    printf("\t\t\t\t\t\t\t%c       %c\n",179,179);// 179 printed through a %c will give an output of an ASCII character, vertical line/s in this case.

    //horizontal line
    printf("\t\t\t\t\t\t ");
    for(int i = 0; i < 7; i++)
    {
        printf("%c",196);// 196 printed through a %c will give an output of an ASCII character, horizontal line/s in this case.
    }
    printf("%c",197);// 197 printed through a %c will give an output of an ASCII character, intersecting perpendicular lines in this case.
    for(int i = 0; i < 7; i++)
    {
        printf("%c",196);// 196 printed through a %c will give an output of an ASCII character, horizontal line/s in this case.
    }
    printf("%c",197);// 197 printed through a %c will give an output of an ASCII character, intersecting perpendicular lines in this case.
    for(int i = 0; i < 7; i++)
    {
        printf("%c",196);// 196 printed through a %c will give an output of an ASCII character, horizontal line/s in this case.
    }
    printf("\n");

    //Bottom - indexes 6 7 8
    printf("\t\t\t\t\t\t\t%c       %c\n",179,179);// 179 printed through a %c will give an output of an ASCII character, vertical line/s in this case.
    printf("\t\t\t\t\t\t    %s   %c   %s   %c   %s\n",currentTable[6], 179, currentTable[7], 179, currentTable[8]); // We will put the string(X or O) stored from our two-dimensional array named currentTable through the use of %s.
    printf("\t\t\t\t\t\t\t%c       %c\n",179,179);// 179 printed through a %c will give an output to an ASCII character, vertical line/s in this case.
    return 0;
}
int main()
{
    int gameMode, gm = FALSE, a;
    system("color 70");//Change background color to white, and text to black --- 7 for white, 0 for black
    mainMenu();
    getch();
    while(gm == FALSE)// we'll have a loop until the condition becomes gm!=FALSE
    {
        gameMode = playWith();// the int gameMode will have the returned value of the function playWith().
        if(gameMode == 1)
        {
            a = friendlyMatch(&player);
            printf("\n\t\tPlayer %i won!", a);
            gm = TRUE;// set int gm to TRUE which is defined with the value of 1, which means gm = 1. We do this to break out from the while loop.
        }
        else if(gameMode == 2)
        {
            a = computerMatch(&player);
            if(a == 1)
            {
                printf("\n\t\t\t\tYou won!");
            }
            else if(a == 2)
            {
                printf("\n\t\t\t\tComputer won!");
            }
            gm = TRUE;// set int gm to TRUE which is defined with the value of 1, which means gm = 1. We do this to break out from the while loop.
        }
        else
        {
            printf("\n\tIncorrect input.");
            gm = FALSE;// we will stay inside the while loop until the user provides a valid input.
        }
    }
    getch();
    return 0;
}
