#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "locked_n_loaded.h"


int main(void) {

    printf("\e[0;35m __         ______     ______     __  __     ______     _____        __   __        __         ______     ______     _____     ______    _____ \n");    
    printf("\e[0;35m/\\ \\       /\\  __ \\   /\\  ___\\   /\\ \\/ /    /\\  ___\\   /\\  __-.     /\\ -.\\ \\      /\\ \\       /\\  __ \\   /\\  __ \\   /\\  __-.  /\\ ___\\   /\\  __-.\n");  
    printf("\e[0;35m\\ \\ \\____  \\ \\ \\/\\ \\  \\ \\ \\____  \\ \\  _-.  \\ \\  __\\   \\ \\ \\/\\ \\    \\ \\ \\-.  \\     \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\  __ \\  \\ \\ \\/\\ \\ \\ \\  __\\   \\ \\ \\/\\ \\ \n");
    printf("\e[0;35m \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\____-     \\ \\_\\\\_\\     \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\____-  \\ \\_____\\  \\ \\____- \n");
    printf("\e[0;35m  \\/_____/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_____/   \\/____/      \\/_/ \\/_/      \\/_____/   \\/_____/   \\/_/\\/_/   \\/____/   \\/_____/   \\/____/\n"); 
    printf("\n");                                                                                                               

    char direction;
    int spawn_x = random_number(15,3);
    int spawn_y = random_number(15,3);
    int enemy1_x = 14;
    int enemy1_y = 14;
    int enemy2_x = 12;
    int enemy2_y = 9;
    int enemy3_x = 7;
    int enemy3_y = 11;
    
   
    int map[SIZE][SIZE] = {EMPTY};
    if(spawn_x == enemy1_x && spawn_y == enemy1_y) {
        while(spawn_x == enemy1_x && spawn_y == enemy1_y) {
            enemy1_x = random_number(15,0);
            enemy1_y = random_number(15,0);
        }
    }
    if(spawn_x == enemy2_x && spawn_y == enemy2_y) {
        while(spawn_x == enemy2_x && spawn_y == enemy2_y) {
            enemy2_x = random_number(15,0);
            enemy2_y = random_number(15,0);
        }
    }
    if(spawn_x == enemy3_x && spawn_y == enemy3_y) {
        while(spawn_x == enemy3_x && spawn_y == enemy3_y) {
            enemy3_x = random_number(15,0);
            enemy3_y = random_number(15,0);
        }
    }
    

    map[enemy1_x][enemy1_y] = ENEMY;
    map[enemy2_x][enemy2_y] = ENEMY;
    map[enemy3_x][enemy3_y] = ENEMY;
    map[12][4] = BOMB;
    for(int i = 0; i < SIZE; i++) {
        map[i][0] = GATE;
    }
    int wave_counter = 1;

    printf("\e[1;32mYou are Butch, a member of the [redacted] military tasked taking down human hybrid bioweapons that escaped from a top-secret testing facility in [redacted].\n");
    printf("\n");
    printf("You are tasked with rescuing civilians and taking down these enemies with your long ranged sniper.\n ");
    printf("\n");
    printf("Enter Direction using numpad\n");
    color_reset();
    printf("\n");
    printf("Press W to go up\n");
    printf("Press S to go down\n");
    printf("Press A to go left\n");
    printf("Press D to go right\n");
    printf("Press F to shoot, you your shot will shoot horizontally in two directions");
    printf("Press E to exit game\n");
    printf("Press B for a bomb\n");
    int keeplooping = 1;
    while(keeplooping == 1){
        scanf(" %c", &direction);
        map[spawn_x][spawn_y] = 0;
        if(direction == 's' || direction == 'S') {
            if(spawn_x == SIZE - 1) {
                printf("Butch: I can't leave and let those monsters wreak havoc on the people nearby!\n");
                printf("\n");
                spawn_x--;
            }
            spawn_x++;
        }
        else if(direction == 'a' || direction == 'A') {
            if(spawn_y == 0){
                spawn_y++;
                printf("Butch: You really expect me to leave right now?\n");
                printf("\n");
            }
            spawn_y--;
        }
        else if(direction =='d' || direction == 'D') {
            if(spawn_y == SIZE - 1){
                spawn_y--;
                printf("This is not the time to abandon my post!\n");
                printf("\n");
            }
            spawn_y++;
        }
        else if(direction == 'w' || direction == 'W') {
            if(spawn_x == 0){
                printf("I can't leave! I can't leave these people to die!\n");
                printf("\n");
                spawn_x++;
            }
            spawn_x--;
            map[spawn_x][spawn_y] = 15;
        } 
        else if(direction == 'f' || direction == 'F') {
            shoot_laser(map, spawn_x, spawn_y);
        }   
        else if(direction == 'e' || direction == 'E') {
            printf("\e[0;92mThank you for playing ");
            color_reset();
            printf("\e[1;95mLocked-n-loaded");
            exit(0);
        }
        else if(direction == 'b' || direction == 'B') {
            int bomb_start_x = random_number(SIZE, 0);
            int bomb_start_y = random_number(SIZE, 0);
            map[bomb_start_x][bomb_start_y] = 4;
        }
        if(map[spawn_x][spawn_y] == 2) {
            if(wave_counter == 1) {
                printf("\e[1;30m Wave 1 complete...\n");
                printf("\n");
                printf("\e[1;30m Wave 2 beginning...\n");
                color_reset();
                enemy1_x = 14;
                enemy1_y = 7;

                enemy2_x = 9;
                enemy2_y = 8;
                map[enemy1_x][enemy1_y] = ENEMY;
                map[enemy2_x][enemy2_y] = ENEMY;
                wave_counter++;

            }
            else if(wave_counter == 2) {
                printf("\e[1;30m Wave 2 complete...\n");
                printf("\n");
                printf("\e[1;30m Wave 3 beginning...\n");
                color_reset();
                enemy1_x = 14;
                enemy1_y = 7;

                enemy2_x = 9;
                enemy2_y = 8;

                enemy3_x = 12;
                enemy3_y = 11;
                map[enemy1_x][enemy1_y] = ENEMY;
                map[enemy2_x][enemy2_y] = ENEMY;
                map[enemy3_x][enemy3_y] = ENEMY;
                map[6][3] = BOMB;
                wave_counter++;
            }
        }
        else {
            map[spawn_x][spawn_y] = 15;
        
            if(map[enemy1_x][enemy1_y] == EMPTY) {
                map[enemy1_x][enemy1_y] = PORTAL;
            }
            if(map[enemy1_x][enemy1_y] == ENEMY) {
                map[enemy1_x][enemy1_y] = EMPTY;
                enemy1_y--;
                if(enemy1_x == spawn_x && enemy1_y == spawn_y) {
                    printf("GAME OVER\n");
                    exit(0);
                }
                map[enemy1_x][enemy1_y] = ENEMY;
            }
            if(map[enemy2_x][enemy2_y] == ENEMY) {
                map[enemy2_x][enemy2_y] = EMPTY;
                enemy2_y--;
                map[enemy2_x][enemy2_y] = ENEMY;
            }
            if(map[enemy3_x][enemy3_y] == ENEMY) {
                map[enemy3_x][enemy3_y] = EMPTY;
                enemy3_y--;
                map[enemy3_x][enemy3_y] = ENEMY;
            }

            print_map(map);
            for(int i = 0; i < SIZE; i++) {
                if(i == enemy1_x && enemy1_y == 0) {
                    printf("GAME OVER!\n");
                    exit(0);
                }
                else if(i == enemy2_x && enemy2_y == 0) {
                    printf("GAME OVER!\n");
                    exit(0);
                }
                else if(i == enemy3_x && enemy3_y == 0) {
                    printf("GAME OVER!\n");
                    exit(0);
                }
            }
        }
    }
    

    
   
    
  
    
    return 0;
    
   
}

void print_map (int map[SIZE][SIZE]) {
    
    // generate random position on (x,y)
    // plane for player to spawn in
    int i = 0;

    while(i < SIZE) {
        int j = 0;
        while(j < SIZE) {
            if(map[i][j] == 15) {
                printf("\033[1;33m");//Set the text to the color yellow
                printf("P "); //Display Butch in yellow
                printf("\033[0m");
            }
            else if(map[i][j] == ENEMY){
                printf("\033[1;31m");
                printf("E ");
                printf("\033[0m");
            }
            else if(map[i][j] == PORTAL) {
                printf("\e[1;32m");
                printf("T ");
                color_reset();
            }
            else if(map[i][j] == EMPTY) {
                printf("%d ", map[i][j]);
            }
            else if(map[i][j] == BOMB) {
                printf("\e[1;35m");
                printf("B ");
                color_reset();
            }
            else if(map[i][j] == GATE) {
                printf("\e[1;35m");
                printf("} ");
                color_reset();
            }
            else if(map[i][j] == SHOOT) {
                printf("\e[1;34m");
                printf("0 ");
                color_reset();
                map[i][j] = EMPTY;
            }
            else if(map[i][j] == EXPLOSION) {
                printf("\e[1;36m");
                printf("0 ");
                color_reset();
        
                map[i][j] = EMPTY;
                
                
            }
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}
void check_for_game_end (int map[SIZE][SIZE]) {
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
        print_map (map);
        printf ("Game Won!\n");
        exit (0);
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

                map[row][column] = EXPLOSION;
                
                
            }
        }
    }
}
void shoot_laser (int map[SIZE][SIZE], int laser_y, int laser_x) {
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
        if(x != 0 && map[laser_y][x] != 4 && map[laser_y][x] != EXPLOSION) {
            map[laser_y][x] = SHOOT;
        }
        
        if (map[laser_y][x] > 3 && map[laser_y][x] < 10 && stone_counter < 4) {
            stone_counter = 4;
            bomb_explosion (map[laser_y][x], map, laser_y, x);
            //check_for_game_end (map, laser_y);
        }
        x++; 
    }
    int y = 0;
    stone_counter = 0;
    while(keeplooping == 1 && y < SIZE && map[y][laser_x] != EXPLOSION) {
        if(laser_x != 0 && map[y][laser_x] != 4 && map[y][laser_x] != EXPLOSION) {
            map[y][laser_x] = SHOOT;
        }
        if(map[y][laser_x] > 3 && map[y][laser_x] < 10) {
            stone_counter = 4;
            bomb_explosion(map[y][laser_x], map, y, laser_x);
        }
        y++;
    }
}
int random_number(int upper, int lower){ // [1,2]
    srand(time(0));
    int random_value =  (rand() % (upper - lower + 1)) + lower;
    return random_value;
}
void color_reset() {
    printf("\e[0m");
}
void red() {
    printf("\e[0;31m");
}
