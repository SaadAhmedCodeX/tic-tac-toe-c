// Tic Tac Toe game using C
#include <stdio.h>
#include <stdlib.h>

int difficulty;

void input_difficulty();
void clear_screen();

int main()
{
    input_difficulty();
    clear_screen();

    return 0;
}

void input_difficulty()
{
    while (1)
    {
        printf("\nSelect difficulty level:");
        printf("\n1. Human (Standard)");
        printf("\n2. God (Impossible to win)");

        printf("\nEnter your choice: ");
        scanf("%d", &difficulty);

        if (difficulty != 1 && difficulty != 2)
        {
            printf("\nIncorrect choice, Enter (1/2)!");
        }
        else
        {
            break;
        }
    }
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}
