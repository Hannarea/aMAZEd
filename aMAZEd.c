// aMAZEd.c

#include <stdio.h>
#define SIZE 25

/**
 * Initializes the values in each cell of the maze
 * @param maze: 2D array containing the cell numbers
 */
void initialize_maze(int maze[SIZE][SIZE]);
/**
 * Prints the initialized maze
 * @param maze: 2D initilized array
 */
void print_maze(int maze[SIZE][SIZE]);
/**
 * Checks if the right wall of a cell is breakable
 * @param maze: 2D array containing cell numbers
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre
 * @post checks if the wall is valid to break
 * @return 1 if the wall is breakable, 0 if the wall is not breakable
 */
int is_right_breakable(int maze[SIZE][SIZE], int i, int j);
/**
 * Checks if the left wall of a cell is breakable
 * @param maze: 2D array containing cell numbers
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre
 * @post checks if the wall is valid to break
 * @return 1 if the wall is breakable, 0 if the wall is not breakable
 */
int is_left_breakable(int maze[SIZE][SIZE], int i, int j);
/**
 * Checks if the top wall of a cell is breakable
 * @param maze: 2D array containing cell numbers
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre
 * @post checks if the wall is valid to break
 * @return 1 if the wall is breakable, 0 if the wall is not breakable
 */
int is_up_breakable(int maze[SIZE][SIZE], int i, int j);
/**
 * Checks if the bottom wall of a cell is breakable
 * @param maze: 2D array containing cell numbers
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre
 * @post checks if the wall is valid to break
 * @return 1 if the wall is breakable, 0 if the wall is not breakable
*/
int is_down_breakable(int maze[SIZE][SIZE], int i, int j);
/**
 * Initializes the values of the vertical walls to 1
 * @param v_walls: 2D array containing a 1 or 0 depending on if a wall exists or not
 */
void initialize_v_walls(int walls[SIZE][SIZE - 1]);
/**
 * Initializes the values of the horizontal walls to 1
 * @param h_walls: 2D array containing a 1 or 0 depending on if a wall exists or not
 */
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
/**
 * Breaks the wall on the left of a cell
 * @param maze: 2D array containing the cell numbers
 * @param walls: 2D array containing the vertical walls
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre the wall to break is valid
 * @post the corresponding wall value in walls is 0
 */
void break_left_wall(int maze[SIZE][SIZE], int walls[SIZE][SIZE - 1], int i, int j);
/**
 * Breaks the wall on the top of a cell
 * @param maze: 2D array containing the cell numbers
 * @param walls: 2D array containing the vertical walls
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre the wall to break is valid
 * @post the corresponding wall value in walls is 0
 */
void break_up_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
/**
 * Breaks the wall on the top of a cell
 * @param maze: 2D array containing the cell numbers
 * @param walls: 2D array containing the vertical walls
 * @param i: row of the cell
 * @param j: column of the cell
 * @pre the wall to break is valid
 * @post the corresponding wall value in walls is 0
 */
void break_down_wall(int maze[SIZE][SIZE], int walls[SIZE - 1][SIZE], int i, int j);
/**
 * checks if the maze is complete or not
 * transverses through the maze array to check if all values are 0
 * @return returns a 1 if the maze is not complete, returns a 0 if the maze is complete
 */
int maze_not_complete(int maze[SIZE][SIZE]);
/**
 * replaces the number indicating a section of a maze with the other (creating one section) when a wall is broken
 * @param maze: a 2D array containing cell numbers
 * @param a: the value of the cell corresponding to maze[i][j]
 * @param b: the value of the cell adjacent to maze[i][j]
 * @pre a and b must bevalues of adjacent cells (either R, L, Up or Down)
 */
void replace_number(int maze[SIZE][SIZE], int a, int b);
/**
 *
 */
void assemble_maze(int maze[SIZE][SIZE], int v_walls[SIZE][SIZE - 1], int h_walls[SIZE - 1][SIZE]);
void print_walls(int h_walls[SIZE - 1][SIZE],int v_walls[SIZE][SIZE - 1]);

int main(){
    int maze[SIZE][SIZE];
    int v_walls[SIZE][SIZE - 1];
    int h_walls[SIZE - 1][SIZE];

    // setting all values of maze to 0 through (SIZE - 1)
    initialize_maze(maze);
    // setting all the values of v_walls to 1, indicating that there are vertical walls
    initialize_v_walls(v_walls);
    // setting all the values of h_walls to 1, indicating that there are horizontal walls
    initialize_h_walls(h_walls);

    // printing the initialized maze
    print_maze(maze);

    // assembling the maze by checking if walls can be broken and breaking them
    assemble_maze(maze, v_walls, h_walls);

    // printing out the maze in perspective of walls
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


