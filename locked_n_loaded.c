#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIZE 20
#define EMPTY 0
#define STONE 1

void print_map (int map[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
void tnt_explosion (int radius, int map[SIZE][SIZE], int startx, int starty) {
    // I am going to map out the area that an explosion from tnt will create in a circle
    int row;
    int column;
    for (row = (startx - radius); 
    row <= (startx + radius); row++) {
        // I am using the mathematical formula (x-a)^2 +(y-k)^2 =  r^2     
        // Since the position isnt always in the center, using this formula is essential 
        //to consider the range of the tnt
        // Using inequailities (and abit of desmos), 
        // it becomes aparrent that if you create an inequality with this equation, 
        // you can shade the inside
        // So essentially, as long as the sum is less than r^2, 
        // it should be inside the circle
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
    if (counter == 625) {
        print_map (map);
        printf ("Game Won!\n");
        exit (0);
    }
}
int main(void){
    int map[SIZE][SIZE] = {EMPTY};
    print_map(map);

}
