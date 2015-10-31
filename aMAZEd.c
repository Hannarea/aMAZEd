// aMAZEd.c

#include <stdio.h>

void initialize_maze(int maze[5][5]);
void print_maze(int maze[5][5]);

int main(){
    int maze[5][5];
    int i, j;

    initialize_maze(maze);

    print_maze(maze);


    return 0;
}

void initialize_maze(int maze[5][5]){
    int i, j;
    for(i=0; i<5; i++){
        for (j=0; j<5; j++){
            maze[i][j] = 5 * i + j;
        }
    }
}


void print_maze(int maze[5][5]){
    int i, j;
    for(i=0; i<5; i++){
        for (j=0; j<5; j++){
            printf("%3d ", maze[i][j]);
        }
        printf("\n");
    }
}

