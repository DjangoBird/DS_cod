// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>   // For memset
// #include <limits.h>   // For INT_MAX

// // --- Configuration ---
// #define N 8 // Board size (e.g., 8 for a standard chessboard)

// // Chessboard
// int board[N][N];

// // Knight's possible moves (relative to current position)
// int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// // Function to check if (x, y) is a valid and unvisited square
// bool isSafe(int x, int y, int board[N][N]) {
//     return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
// }

// // Function to print the solution board
// void printSolution(int board[N][N]) {
//     printf("Knight's Tour Path (Warnsdorff's Rule):\n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%3d ", board[i][j]);
//         }
//         printf("\n");
//     }
// }

// // Function to count the number of unvisited accessible squares from (x, y)
// // This is used by Warnsdorff's rule to determine the "degree" of a square
// int countValidMoves(int x, int y, int board[N][N]) {
//     int count = 0;
//     for (int i = 0; i < 8; i++) {
//         if (isSafe(x + xMove[i], y + yMove[i], board)) {
//             count++;
//         }
//     }
//     return count;
// }

// // Function to solve the Knight's Tour problem using Warnsdorff's Rule
// void solveKT_Warnsdorff(int start_x, int start_y) {
//     // Initialize the board with -1 (unvisited)
//     memset(board, -1, sizeof(board));

//     int current_x = start_x;
//     int current_y = start_y;
//     board[current_x][current_y] = 1; // Mark the starting position as move 1

//     // Loop for N*N - 1 more moves
//     for (int moveCount = 2; moveCount <= N * N; moveCount++) {
//         int min_degree_idx = -1;    // Index of the move in xMove/yMove with min degree
//         int min_degree = INT_MAX; // Minimum degree found so far (or 9 as max possible degree is 8)
//         int next_best_x = -1;
//         int next_best_y = -1;

//         // Try all 8 possible next moves
//         for (int k = 0; k < 8; k++) {
//             int next_x = current_x + xMove[k];
//             int next_y = current_y + yMove[k];

//             if (isSafe(next_x, next_y, board)) {
//                 int degree = countValidMoves(next_x, next_y, board);
//                 if (degree < min_degree) {
//                     min_degree = degree;
//                     next_best_x = next_x;
//                     next_best_y = next_y;
//                 }
//                 // Tie-breaking: if degrees are equal, can choose any.
//                 // Some more advanced tie-breaking might exist, but usually not critical.
//                 // Here, we just take the first one found with the minimum degree.
//                 // If you want to be more deterministic or explore ties, you could:
//                 // else if (degree == min_degree) { /* handle tie-breaking strategy */ }
//             }
//         }

//         // If no valid move is found (min_degree remains INT_MAX or next_best_x is -1)
//         if (next_best_x == -1) {
//             printf("Warnsdorff's Rule got stuck after %d moves.\n", moveCount - 1);
//             printf("Partial tour:\n");
//             printSolution(board);
//             return;
//         }

//         // Make the move
//         current_x = next_best_x;
//         current_y = next_best_y;
//         board[current_x][current_y] = moveCount;
//     }

//     // If we reach here, a full tour was found
//     printf("Successfully completed Knight's Tour using Warnsdorff's Rule!\n");
//     printSolution(board);
// }


// int main() {
//     int start_row, start_col;

//     printf("Knight's Tour Problem (Warnsdorff's Rule) for a %dx%d board.\n", N, N);

//     if (N < 5 && N > 0) {
//         printf("Warnsdorff's Rule is generally not guaranteed for N < 5. May get stuck.\n");
//         // For N < 5, solutions often don't exist anyway.
//     }
    
//     while (1) {
//         printf("Enter starting row (0 to %d): ", N - 1);
//         if (scanf("%d", &start_row) != 1 || start_row < 0 || start_row >= N) {
//             printf("Invalid input. Please enter a number between 0 and %d.\n", N - 1);
//             while (getchar() != '\n'); // Clear input buffer
//             continue;
//         }
//         break;
//     }

//     while (1) {
//         printf("Enter starting column (0 to %d): ", N - 1);
//         if (scanf("%d", &start_col) != 1 || start_col < 0 || start_col >= N) {
//             printf("Invalid input. Please enter a number between 0 and %d.\n", N - 1);
//             while (getchar() != '\n'); // Clear input buffer
//             continue;
//         }
//         break;
//     }
    
//     printf("Starting Knight's Tour from (%d, %d) using Warnsdorff's Rule...\n", start_row, start_col);

//     solveKT_Warnsdorff(start_row, start_col);

//     return 0;
// }

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#ifdef _WIN32
#include <windows.h> // For Sleep() and system("cls")
#else
#include <unistd.h> // For usleep() and system("clear")
#endif

// --- Configuration ---
#define N 8
#define DELAY_MICROSECONDS 150000 // 150 milliseconds, adjust as needed

// Chessboard
int board[N][N];

// Knight's possible moves
int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to clear the console screen
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function for delay
void wait_microseconds(unsigned int us) {
#ifdef _WIN32
    Sleep(us / 1000); // Sleep takes milliseconds
#else
    usleep(us);     // usleep takes microseconds
#endif
}

// Function to check if (x, y) is a valid and unvisited square
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Function to print the solution board
void print_board_state() {
    printf("Knight's Tour Path (Warnsdorff's Rule - Console Animation):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == -1) {
                printf("  . "); // Unvisited
            } else {
                printf("%3d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of unvisited accessible squares from (x, y)
int countValidMoves(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (isSafe(x + xMove[i], y + yMove[i])) {
            count++;
        }
    }
    return count;
}

// Function to solve the Knight's Tour problem using Warnsdorff's Rule
void solveKT_Warnsdorff_console_anim(int start_x, int start_y) {
    memset(board, -1, sizeof(board));

    int current_x = start_x;
    int current_y = start_y;
    board[current_x][current_y] = 1;

    clear_screen();
    print_board_state();
    wait_microseconds(DELAY_MICROSECONDS * 2); // Initial longer pause

    for (int moveCount = 2; moveCount <= N * N; moveCount++) {
        int min_degree = INT_MAX;
        int next_best_x = -1;
        int next_best_y = -1;

        for (int k = 0; k < 8; k++) {
            int next_x = current_x + xMove[k];
            int next_y = current_y + yMove[k];

            if (isSafe(next_x, next_y)) {
                int degree = countValidMoves(next_x, next_y);
                if (degree < min_degree) {
                    min_degree = degree;
                    next_best_x = next_x;
                    next_best_y = next_y;
                }
            }
        }

        if (next_best_x == -1) {
            clear_screen();
            print_board_state();
            printf("Warnsdorff's Rule got stuck after %d moves.\n", moveCount - 1);
            return;
        }

        current_x = next_best_x;
        current_y = next_best_y;
        board[current_x][current_y] = moveCount;

        clear_screen();
        print_board_state();
        wait_microseconds(DELAY_MICROSECONDS);
    }

    clear_screen();
    print_board_state();
    printf("Successfully completed Knight's Tour using Warnsdorff's Rule!\n");
}

int main() {
    int start_row, start_col;

    printf("Knight's Tour Problem (Warnsdorff's Rule - Console Animation) for a %dx%d board.\n", N, N);

    if (N < 5 && N > 0) {
        printf("Warnsdorff's Rule is generally not guaranteed for N < 5. May get stuck.\n");
    }

    do {
        printf("Enter starting row (0 to %d): ", N - 1);
        if (scanf("%d", &start_row) != 1 || start_row < 0 || start_row >= N) {
            printf("Invalid input. Please enter a number between 0 and %d.\n", N - 1);
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    } while (1);

    do {
        printf("Enter starting column (0 to %d): ", N - 1);
        if (scanf("%d", &start_col) != 1 || start_col < 0 || start_col >= N) {
            printf("Invalid input. Please enter a number between 0 and %d.\n", N - 1);
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break;
        }
    } while (1);

    printf("Starting Knight's Tour from (%d, %d) with console animation...\n", start_row, start_col);
    printf("Press Enter to start...");
    getchar(); // Consume the newline from previous scanf
    getchar(); // Wait for Enter key

    solveKT_Warnsdorff_console_anim(start_row, start_col);

    return 0;
}
