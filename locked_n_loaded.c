#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



#define SIZE 13
#define EMPTY 0
#define STONE 1

int random_number(int upper, int lower){ // [1,2]
    srand(time(0));
    int random_value =  (rand() % (upper - lower + 1)) + lower;
    return random_value;
}

void print_map (int map[SIZE][SIZE], int spawn_x, int spawn_y, int enemy1_x, int enemy1_y) {
    
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
            else if(i == enemy1_x && j == enemy1_y){
                printf("\033[1;31m");
                printf("E ");
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
    printf("\n");
}
/*
void shoot_laser (int map[SIZE][SIZE], int laser_y) {
    int keeplooping = 1;
    int x = 0;
    // this x variable will go through every element of the row checking 
    // for a STONE which is equal to and printed as 1. 
    // EXAMPLE: If the stone is the third element in the row, 
    // 0 0 1, it will first check the two elements behind, and then the third 
    // -converting it into a zero.

    int stone_counter = 0;

    // this stone_counter variable will check how many stones the laser has broken.
    // If it is above or equal to 4, it will break no more.
    // EXAMPLE: I give the coordinates, 6 5 1,  6 4 1 . 6 3 1, 6 2 1, 6 1 1. 
    // If i shoot the laser at this row, it will break 4 stones 
    // and one will remain which is the most furtherst out, 6 5 1.
    while (keeplooping == 1 && x < SIZE) {
                
        // we just shoot the laser and turn everything into 0 there
        if (map[laser_y][x] == STONE && stone_counter < 4) {
            map[laser_y][x] = EMPTY;
            stone_counter++;
            
           
            check_for_game_end (map, laser_y);
            // Using the blocks variable that scanned the number of blocks
            // and doing blocks= blocks - 1 does not work inside this function
            // It only works in the main function so 
            // i will use a 2d for loop to check for a game end

            
        }
        else if (map[laser_y][x] > 3 && map[laser_y][x] < 10 && stone_counter < 4) {
            stone_counter = 4;
            tnt_explosion (map[laser_y][x], map, laser_y, x);
            check_for_game_end (map, laser_y);

        }
        x++;
                
    }
    print_map(map, laser_y);
}
*/
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
void check_for_game_end (int map[SIZE][SIZE], int laser_y, int spawn_x, int spawn_y, int enemy1_x, int enemy1_y) {
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
    if (counter == 0) {
        print_map (map, spawn_x, spawn_y, enemy1_x, enemy1_y);
        printf ("Game Won!\n");
        exit (0);
    }
}


int main(void) {
    char direction;
    int spawn_x = random_number(12,0);
    int spawn_y = random_number(12,0);
    int enemy1_x = random_number(12,0);
    int enemy1_y = random_number(12,0);

    int map[SIZE][SIZE] = {EMPTY};
    print_map(map, spawn_x, spawn_y, enemy1_x, enemy1_y);
    printf("You are Butch, a member of the [redacted] military tasked taking down human hybrid bioweapons that escaped from a top-secret testing facility in [redacted].\n");
    printf("You are tasked with rescuing civilians and taking down these enemies with your long ranged sniper.\n ");
    printf("Enter Direction using numpad\n");
    printf("Press W to go up\n");
    printf("Press S to go down\n");
    printf("Press A to go left\n");
    printf("Press D to go right\n");
    int keeplooping = 1;
    while(keeplooping == 1){
        scanf("%c", &direction);
        if(direction == 's' || direction == 'S') {
            if(spawn_x == 12) {
                printf("Butch: I can't leave and let those monsters wreak havoc on the people nearby!\n");
                spawn_x--;
            }
            spawn_x++;
        }
        else if(direction == 'a' || direction == 'A') {
            if(spawn_y == 0){
                spawn_y++;
                printf("Butch: You really expect me to leave right now?\n");
            }
            spawn_y--;
        }
        else if(direction =='d' || direction == 'D') {
            if(spawn_y == 12){
                spawn_y--;
                printf("This is not the time to abandon my post!\n");
            }
            spawn_y++;
        }
        else if(direction == 'w' || direction == 'W') {
            if(spawn_x == 0){
                printf("I can't leave! I can't leave these people to die!\n");
                spawn_x++;
            }
            spawn_x--;
        }

        print_map(map, spawn_x, spawn_y, enemy1_x, enemy1_y);


    }

    
    
  
    
   

}
