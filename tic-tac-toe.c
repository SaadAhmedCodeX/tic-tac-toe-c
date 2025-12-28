// Tic Tac Toe game using C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define X 'X'
#define O 'O'
#define EMPTY ' '

#define PVP 1
#define PVC 2

#define EASY 1
#define MEDIUM 2
#define HARD 3

typedef struct
{
    int playerX;
    int playerO;
    int draw;
} Score;

int game_mode;
int difficulty;
Score score = {.playerX = 0, .playerO = 0, .draw = 0};

void input_game_mode();
void input_difficulty();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);
void player_move(char board[BOARD_SIZE][BOARD_SIZE], char symbol);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();

int main()
{
    srand(time(NULL));
    int choice;

    input_game_mode();
    input_difficulty();

    do
    {
        play_game();

        do
        {
            printf("\nPlay again? (1 for yes, 0 for no): ");
            scanf("%d", &choice);
        } while (choice != 0 && choice != 1);

    } while (choice == 1);

    printf("Thanks for playing.\n");
    return 0;
}

void input_game_mode()
{
    while (1)
    {
        printf("\nSelect Mode:");
        printf("\n1. Player vs Player");
        printf("\n2. Player vs Computer");
        printf("\nEnter your choice: ");
        scanf("%d", &game_mode);

        if (game_mode == PVP || game_mode == PVC)
            return;

        printf("Invalid Choice!\n");
    }
}

void input_difficulty()
{
    if (game_mode == PVP)
        return;

    while (1)
    {
        printf("\nSelect difficulty:");
        printf("\n1. Easy");
        printf("\n2. Medium");
        printf("\n3. Hard");

        printf("\nEnter your choice: ");
        scanf("%d", &difficulty);

        if (difficulty >= EASY && difficulty <= HARD)
            return;

        printf("Invalid choice!\n");
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

    printf("Tic Tac Toe\n");

    if (game_mode == PVC)
    {
        printf("Score - Player (X): %d | Computer (O): %d | Draws: %d\n", score.playerX, score.playerO, score.draw);

        printf("Difficulty: ");

        if (difficulty == EASY)
            printf("Easy\n");
        else if (difficulty == MEDIUM)
            printf("Medium\n");
        else if (difficulty == HARD)
            printf("Hard\n");
    }
    else
    {
        printf("Score - Player 1 (X): %d | Player 2 (O): %d | Draws: %d\n", score.playerX, score.playerO, score.draw);
    }

    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("\n");
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                printf("[%d]", i * 3 + j + 1);
            }
            else
            {
                printf(" %c ", board[i][j]);
            }

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
            board[i][2] == player) // Checks each row
        {
            return 1;
        }

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player) // Checks each column
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
    return 0; // Returns false if there is no winner
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY) // Checks if there is any empty spot
            {
                return 0; // Returns false if there is an empty slot i.e Not a draw
            }
        }
    }
    return 1; // Returns true if all the spots are filled i.e Draw
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    return !(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY);
}

void player_move(char board[BOARD_SIZE][BOARD_SIZE], char symbol)
{
    int cell;
    int row, col;

    while (1)
    {
        printf("\nPlayer %c's turn.\n", symbol);
        printf("\nEnter cell number (1-9): ");
        scanf("%d", &cell);

        // Check valid range
        if (cell < 1 || cell > 9)
        {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            continue;
        }

        row = (cell - 1) / 3;
        col = (cell - 1) % 3;

        // Check if cell is empty
        if (!is_valid_move(board, row, col))
        {
            printf("Cell already occupied! Choose another cell.\n");
            continue;
        }

        board[row][col] = symbol;
        break;
    }
}

void computer_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;
    // Easy mode
    if (difficulty == EASY)
    {
        do
        {
            row = rand() % 3;
            col = rand() % 3;
        } while (!is_valid_move(board, row, col));

        board[row][col] = O;
        return;
    }

    // Medium mode
    if (difficulty == MEDIUM || difficulty == HARD)
    {
        // Play for Immediate win
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = O;
                    if (check_win(board, O))
                    {
                        return;
                    }
                    board[i][j] = EMPTY;
                }
            }
        }

        // Play for Immediate block
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = X;
                    if (check_win(board, X))
                    {
                        board[i][j] = O;
                        return;
                    }
                    board[i][j] = EMPTY;
                }
            }
        }
    }

    // Hard mode
    if (difficulty == HARD)
    {
        // Play Center if available
        if (board[1][1] == EMPTY)
        {
            board[1][1] = O;
            return;
        }

        // Play Corner if available
        int corner[4][2] = {
            {0, 0},
            {0, 2},
            {2, 0},
            {2, 2}};

        for (int i = 0; i < 4; i++)
        {
            if (board[corner[i][0]][corner[i][1]] == EMPTY)
            {
                board[corner[i][0]][corner[i][1]] = O;
                return;
            }
        }
    }

    // Play first available move
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = O;
                return;
            }
        }
    }
}

void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
    };

    char current_player = rand() % 2 == 0 ? X : O; // Randomly decides who starts first

    print_board(board);

    if (game_mode == PVC)
    {
        if (current_player == X)
            printf("Player (X) starts first!\n");
        else
            printf("Computer (O) starts first!\n");
    }
    else // game_mode == PVP
    {
        if (current_player == X)
            printf("Player 1 (X) starts first!\n");
        else
            printf("Player 2 (O) starts first!\n");
    }

    printf("Press Enter to continue...");
    getchar(); // Eats newline
    getchar(); // Waits

    while (1)
    {
        print_board(board);

        if (current_player == X)
        {
            player_move(board, X);
        }
        else
        {
            if (game_mode == PVP)
                player_move(board, O);
            else
                computer_move(board);
        }

        if (check_win(board, current_player))
        {
            print_board(board);

            if (game_mode == PVC)
            {
                if (current_player == X)
                {
                    score.playerX++;
                    print_board(board);
                    printf("Congratulations! Player (X) wins!\n");
                    break;
                }
                else
                {
                    score.playerO++;
                    print_board(board);
                    printf("Computer (O) wins! Better luck next time.\n");
                    break;
                }
            }
            else
            { // game_mode == PVP
                if (current_player == X)
                {
                    score.playerX++;
                    print_board(board);
                    printf("Player 1 (X) wins!\n");
                }
                else
                {
                    score.playerO++;
                    print_board(board);
                    printf("Player 2 (O) wins!\n");
                }
                break;
            }
        }

        if (check_draw(board))
        {
            score.draw++;
            print_board(board);
            printf("It's a Draw!\n");
            break;
        }

        current_player = (current_player == X) ? O : X;
    }
}