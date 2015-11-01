// aMAZEd.c

#include <stdio.h>
#define SIZE 10

/**
 * Initializes the values in each cell of the maze
 * @param maze: 2D array containing the cell numbers
 */
void initialize_maze(int maze[SIZE][SIZE]);
void print_maze(int maze[SIZE][SIZE]);
int is_right_breakable(int maze[SIZE][SIZE], int i, int j);
int is_left_breakable(int maze[SIZE][SIZE], int i, int j);
int is_up_breakable(int maze[SIZE][SIZE], int i, int j);
int is_down_breakable(int maze[SIZE][SIZE], int i, int j);
void initialize_v_walls(int walls[SIZE][SIZE - 1]);
void initialize_h_walls(int walls[SIZE - 1][SIZE]);
/**
 * Breaks the wall on the right of a cell
 * @param maze: 2D array containing the cell numbers
 * @param walls: 2D array containing the vertical walls
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre the wall to break is valid
 * @post the corresponding wall value in walls is 0
 */
void break_right_wall(int maze[SIZE][SIZE], int walls[SIZE][SIZE - 1], int i, int j);
void break_left_wall(int maze[SIZE][SIZE], int walls[SIZE][SIZE - 1], int i, int j);
void break_up_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
void break_down_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
int maze_not_complete(int maze[SIZE][SIZE]);
void replace_number(int maze[SIZE][SIZE], int a, int b);
void assemble_maze(int maze[SIZE][SIZE], int v_walls[SIZE][SIZE - 1], int h_walls[SIZE - 1][SIZE]);
void print_walls(int h_walls[SIZE - 1][SIZE],int v_walls[SIZE][SIZE - 1]);

int main(){
    int maze[SIZE][SIZE];
    int v_walls[SIZE][SIZE - 1];
    int h_walls[SIZE - 1][SIZE];
    int i, j;

    initialize_maze(maze);
    initialize_v_walls(v_walls);
    initialize_h_walls(h_walls);

    print_maze(maze);

    assemble_maze(maze, v_walls, h_walls);

    print_walls(h_walls, v_walls);
    return 0;
}

void initialize_maze(int maze[SIZE][SIZE]){
    int i, j;
    for(i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            maze[i][j] = SIZE * i + j;
        }
    }
}


void print_maze(int maze[SIZE][SIZE]){
    int i, j;
    for(i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            printf("%3d ", maze[i][j]);
        }
        printf("\n");
    }
}

int is_right_breakable(int maze[SIZE][SIZE], int i, int j){
    int  check = 0;
    if (j == SIZE - 1){
        check = 0;
    }
    else if (maze[i][j] != maze[i][j + 1]){
        check = 1;
    }
    return check;
}

int is_left_breakable(int maze[SIZE][SIZE], int i, int j){
    int  check = 0;
    if (j == 0){
        check = 0;
    }
    else if (maze[i][j] != maze[i][j - 1]){
        check = 1;
    }
    return check;
}

int is_down_breakable(int maze[SIZE][SIZE], int i, int j){
    int  check = 0;
    if (i == SIZE - 1){
        check = 0;
    }
    else if (maze[i][j] != maze[i + 1][j]){
        check = 1;
    }
    return check;
}


int is_up_breakable(int maze[SIZE][SIZE], int i, int j){
    int  check = 0;
    if (i == 0 ){
        check = 0;
    }
    else if (maze[i][j] != maze[i - 1][j]){
        check = 1;
    }
    return check;
}

void initialize_v_walls(int walls[SIZE][SIZE - 1]){
    int i, j;
    for(i=0; i<SIZE; i++){
        for (j=0; j<SIZE - 1; j++){
            walls[i][j] = 1;
        }
    }
}

void initialize_h_walls(int walls[SIZE - 1][SIZE]){
    int i, j;
    for(i=0; i<SIZE - 1; i++){
        for (j=0; j<SIZE; j++){
            walls[i][j] = 1;
        }
    }
}

// given the room index, compute the wall index and break
void break_right_wall(int maze[SIZE][SIZE], int walls[SIZE][SIZE - 1], int i, int j){
    walls[i][j] = 0;
    replace_number(maze, maze[i][j], maze[i][j + 1]);
}
void break_left_wall(int maze[SIZE][SIZE], int walls[SIZE][SIZE - 1], int i, int j){
    walls[i][j - 1] = 0;
    replace_number(maze, maze[i][j], maze[i][j - 1]);
}
void break_up_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j){
    walls[i - 1][j] = 0;
    replace_number(maze, maze[i][j], maze[i - 1][j]);
}
void break_down_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j){
    walls[i][j] = 0;
    replace_number(maze, maze[i][j], maze[i + 1][j]);
}

void replace_number(int maze[SIZE][SIZE], int a, int b){
    int max_num, min_num, i, j;

    // predict what the max and min are
    max_num = a;
    min_num = b;
    // check if we were right :) ... but... most likely we were... cause we are the best!
    if (a < b){
        max_num = b;
        min_num = a;
    }
    // transverse through the maze and replace the maxs with the mins
    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            if (maze[i][j] == max_num){
                maze[i][j] = min_num;
            }
        }
    }
}

void assemble_maze(int maze[SIZE][SIZE], int v_walls[SIZE][SIZE - 1], int h_walls[SIZE - 1][SIZE] ){
    int num1, num2, num3, check;
    srand((time(0)));

    check = maze_not_complete(maze);
    while (check == 1){
        num1 = rand() % SIZE;
        num2 = rand() % SIZE;
        num3 = rand() % 4 + 1; // get a number 1 - 4 to pick randomly whether to test the R, L, U, or D wall...
        if (num3 == 1){ // check the L wall
            if (is_left_breakable(maze, num1, num2)){
                break_left_wall(maze, v_walls, num1, num2);
            }
        }
        if (num3 == 2){ // check the R wall
            if (is_right_breakable(maze, num1, num2)){
                break_right_wall(maze, v_walls, num1, num2);
            }

        }
        if (num3 == 3){ // check the Up wall
            if (is_up_breakable(maze, num1, num2)){
                break_up_wall(maze, h_walls, num1, num2);
            }

        }
        if (num3 == 4){ // check the Down wall
            if (is_down_breakable(maze, num1, num2)){
                break_down_wall(maze, h_walls, num1, num2);
            }
        }
        check = maze_not_complete(maze);
    }


}

int maze_not_complete(int maze[SIZE][SIZE]){
    int i, j;
    for (i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if (maze[i][j] != 0){
                return 1;
            }
        }
    }
    return 0;
}

void print_walls(int h_walls[SIZE - 1][SIZE],int v_walls[SIZE][SIZE - 1]){
    int i, j;
    for (i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if (h_walls[i][j] == 1){
                printf("_");
            }
            else{
                printf(" ");
            }
            if (v_walls[i][j] == 1){
                printf("|");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}


