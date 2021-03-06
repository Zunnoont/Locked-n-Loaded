#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define EMPTY 0
#define ENEMY 1
#define SIZE 15
#define SIZE2 20
#define BOMB 4
#define PORTAL 2
#define GATE 17
#define CHARACTER 15
#define SHOOT 21
#define EXPLOSION 19
#define BOMB 4

void print_map (int map[SIZE][SIZE]);

void check_for_game_end (int map[SIZE][SIZE]);

int random_number(int upper, int lower);

void shoot_laser (int map[SIZE][SIZE], int laser_y, int laser_x);

void bomb_explosion (int radius, int map[SIZE][SIZE], int startx, int starty);

void red();

void color_reset();
