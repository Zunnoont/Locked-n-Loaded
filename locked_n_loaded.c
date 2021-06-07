#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define SIZE 13
#define EMPTY 0
#define ENEMY 1
int random_number(int upper, int lower){
    srand(time(0));
    int random_value =  (rand() % (upper - lower + 1)) + lower;
    return random_value;
}
void print_map (int map[SIZE][SIZE]) {
    int spawn_x = random_number(12,0);
    int spawn_y = random_number(12,0);
   
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            if(i == spawn_x && j == spawn_y){
                printf("N ");

            }
            else{
                printf("%d ", map[i][j]);
            }
            j++;
        }
        printf("\n");
        i++;
    }
}
void spawn_player(int map[SIZE][SIZE]){

    
}
void bomb_explosion (int radius, int map[SIZE][SIZE], int startx, int starty) {
    // I am going to map out the area that an explosion from a bomb the
    // player can use that will create a circle bomb radius
    int row;
    int column;
    for (row = (startx - radius); 
    row <= (startx + radius); row++) {
        for (column = (starty - radius); column < (starty + radius); column++) {
            if ((row-startx) * (row-startx) + 
            (column-starty) * (column-starty) < (radius*radius)
            && row >= 0 && row < SIZE && column >= 0 && column < SIZE)
            {
                map[row][column] = EMPTY;
            }
        }
    }
}
void check_for_game_end (int map[SIZE][SIZE], int laser_y) {
    int x;
    int y;
    int counter = 0;
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
            if (map[x][y] == EMPTY) {
                counter++;
            }
        }
    }
    if (counter == 399) {
        print_map (map);
        printf ("Game Won!\n");
        exit (0);
    }
}
int main(void) {
    
    int map[SIZE][SIZE] = {EMPTY};
    print_map(map);
    
  
    
   

}
