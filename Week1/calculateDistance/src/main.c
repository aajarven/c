#include <stdio.h>
#include "source.h"

/* Task modified from Aalto C Programming Basics course
 * Objective: Use some functions
 * Complete a function powerTwo that gets a value as argument and calculates value^2 and returns it. 
 * After that complete a function distance that gets coordinates of two points (x1, y1) and (x2, y2) and calculates distance 
 * between these points and returns it. 
 * Then complete a function distanceFromOrigo that calculates distance of given coordinates (x, y) from origo (0, 0).*/

int main(void) {
    printf("powerTwo(2.3) = %.2f\n", powerTwo(2.3));
    printf("distance(2.3, 4.5, 1.2, 6.3) = %.2f\n", distance(2.3, 4.5, 1.2, 6.3));
    printf("distanceFromOrigo(2.3, 4.5) = %.2f\n", distanceFromOrigo(2.3, 4.5));
    return 0;
}
