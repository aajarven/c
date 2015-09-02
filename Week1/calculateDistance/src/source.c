#include <stdio.h>
#include <math.h>
#include "source.h"

double powerTwo(double value){
    //BEGIN SOLUTION
    return pow(value, 2);
    //END SOLUTION
}

double distance(double x1, double y1, double x2, double y2){
    //BEGIN SOLUTION
    return sqrt(powerTwo(x2 - x1) + powerTwo(y2 - y1));
    //END SOLUTION
}

double distanceFromOrigo(double x, double y){
    //BEGIN SOLUTION
    return distance(x, y, 0, 0);
    //END SOLUTION
}
