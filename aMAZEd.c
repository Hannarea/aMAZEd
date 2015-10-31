// aMAZEd.c

#include <stdio.h>
#define SIZE 5

void initialize_maze(int maze[SIZE][SIZE]);
void print_maze(int maze[SIZE][SIZE]);

int main(){
    int maze[SIZE][SIZE];
    int i, j;

    initialize_maze(maze);

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

