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
void print_map (int map[SIZE][SIZE], int spawn_x, int spawn_y) {
    // generate random position on (x,y)
    // plane for player to spawn in
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            if(i == spawn_x && j == spawn_y){
                printf("\033[1;33m");//Set the text to the color red
                printf("B "); //Display Butch in yellow
                printf("\033[0m");
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
void check_for_game_end (int map[SIZE][SIZE], int laser_y, int spawn_x, int spawn_y) {
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
    if (counter == 144) {
        print_map (map, spawn_x, spawn_y);
        printf ("Game Won!\n");
        exit (0);
    }
}
int main(void) {
    int direction;
    int spawn_x = random_number(12,0);
    int spawn_y = random_number(12,0);
    int map[SIZE][SIZE] = {EMPTY};
    print_map(map, spawn_x, spawn_y);
    printf("You are Butch, a member of the [redacted] military tasked taking down human hybrid bioweapons that escaped from a top-secret testing facility in [redacted].\n");
    printf("You are tasked with rescuing civilians and taking down these enemies with your long ranged sniper.\n ");
    printf("Enter Direction using numpad\n");
    printf("Press 8 to go up\n");
    printf("Press 2 to go down\n");
    printf("Press 4 to go left\n");
    printf("Press 6 to go right\n");
    int keeplooping = 1;
    while(keeplooping == 1){
        scanf("%d", &direction);
        if(direction == 2) {
            if(spawn_x == 12) {
                printf("Butch: I can't leave and let those monsters wreak havoc on the people nearby!\n");
                spawn_x--;
            }
            spawn_x++;
            
        }
        else if(direction == 4) {
            spawn_y--;
        }
        else if(direction == 6) {
            spawn_y++;
        }
        else if(direction == 8) {
            spawn_x--;
        }
        print_map(map, spawn_x, spawn_y);


    }

    
    
  
    
   

}
