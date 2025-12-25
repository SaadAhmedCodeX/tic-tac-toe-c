// Tic Tac Toe game using C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define X 'X'
#define O 'O'

typedef struct
{
    int player;
    int computer;
    int draw;
} Score;

int difficulty;
Score score = {.player = 0, .computer = 0, .draw = 0};

void input_difficulty();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE]);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

int main()
{
    srand(time(NULL));
    int choice;

    input_difficulty();

    do
    {
        play_game();

        printf("\nPlay again? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("Thanks for playing.\n");
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

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    clear_screen();

    printf("Score - Player X: %d, Computer O: %d, Draws: %d", score.player, score.computer, score.draw);
    printf("\nTic Tac Toe\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }
        if (i < BOARD_SIZE - 1)
        {
            printf("\n---+---+---");
        }
    }
    printf("\n\n");
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) // Checks each coloumn
        {
            return 1;
        }

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player) // Checks each row
        {
            return 1;
        }
    }

    if ((board[0][0] == player &&
         board[1][1] == player &&
         board[2][2] == player) || // Checks for primary diagonal
        (board[0][2] == player &&
         board[1][1] == player &&
         board[2][0] == player)) // Checks for secondary diagonal
    {
        return 1;
    }
    return 0; // Returns false if there is no winnder
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ') // Checks if there is any empty spot
            {
                return 0; // Returns false if there is an empty slot i.e Not a draw
            }
        }
    }
    return 1; // Returns true if all the spots are filled i.e Draw
}

void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };
    char current_player = rand() % 2 == 0 ? X : O;

    print_board(board);
    while (1)
    {
        if (current_player == X)
        {
            player_move(board);
            print_board(board);
            if (check_win(board, X))
            {
                score.player++;
                print_board(board);
                printf("Congratulations You have won.!!\n");
                break;
            }
            current_player = O;
        }
        else
        {
            computer_move(board);
            print_board(board);
            if (check_win(board, O))
            {
                score.computer++;
                print_board(board);
                printf("Computer Won! Better luck next time.\n");
                break;
            }
            current_player = X;
        }

        if (check_draw(board))
        {
            score.draw++;
            print_board(board);
            printf("It's a Draw!\n");
            break;
        }
    }
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    return !(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
}

void player_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;
    do
    {
        printf("\nPlayer X's turn.");
        printf("\nEnter row and column (1-3) for X");
        scanf("%d", &row);
        scanf("%d", &col);

        row--;
        col--; // Converting to zero based

    } while (!is_valid_move(board, row, col));

    board[row][col] = X;
}

void computer_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    // 1. Play for Immediate win
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = O;
                if (check_win(board, O))
                {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    
 // 1. Play for Immediate win
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = O;
                if (check_win(board, O))
                {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

}