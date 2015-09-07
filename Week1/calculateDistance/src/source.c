#include <stdio.h>
#include <math.h>
#include "source.h"

double powerTwo(double value){
    return pow(value, 2);
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(powerTwo(x2-x1)+powerTwo(y2-y1));
}

double distanceFromOrigo(double x, double y){
    return sqrt(powerTwo(x)+powerTwo(y));
}
