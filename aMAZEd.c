// aMAZEd.c

#include <stdio.h>
#define SIZE 10

void initialize_maze(int maze[SIZE][SIZE]);
void print_maze(int maze[SIZE][SIZE]);
int is_right_breakable(int maze[SIZE][SIZE], int i, int j);
int is_left_breakable(int maze[SIZE][SIZE], int i, int j);
int is_up_breakable(int maze[SIZE][SIZE], int i, int j);
int is_down_breakable(int maze[SIZE][SIZE], int i, int j);
void initialize_v_walls(int walls[SIZE][SIZE - 1]);
void initialize_h_walls(int walls[SIZE - 1][SIZE]);
void break_right_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
void break_left_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
void break_up_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
void break_down_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
int maze_not_complete(int maze[SIZE][SIZE]);

int main(){
    int maze[SIZE][SIZE];
    int v_walls[SIZE][SIZE - 1];
    int h_walls[SIZE - 1][SIZE];
    int i, j;

    initialize_maze(maze);
    initialize_v_walls(v_walls);
    initialize_h_walls(h_walls);

    print_maze(maze);


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
void break_right_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j){
    walls[i][j] = 0;
    replace_number(maze, maze[i][j], maze[i][j + 1]);
}
void break_left_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j){
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


