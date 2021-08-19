#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void print_map (int map[SIZE][SIZE]);

void check_for_game_end (int map[SIZE][SIZE]);

int random_number(int upper, int lower);

void shoot_laser (int map[SIZE][SIZE], int laser_y);

void bomb_explosion (int radius, int map[SIZE][SIZE], int startx, int starty);
