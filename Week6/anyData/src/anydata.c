#include <stdio.h>
#include "anydata.h"


/* Return a new AnyData object based on the given input
 */
AnyData setDouble(double value)
{
    AnyData ad;
    ad.value.dval = value;
    ad.type = DOUBLE;
    return ad;
}

AnyData setInt(int value)
{
    AnyData ad;
    ad.value.ival = value;
    ad.type = INT;
    return ad;
}

AnyData setByte(char value)
{
    AnyData ad;
    ad.value.bval = value;
    ad.type = BYTE;
    return ad;
}


void printDouble(double val)
{
    printf("D:%lf", val);
}

void printInt(int val)
{
    printf("I:%d", val);
}

void printByte(char val)
{
    printf("B:%d", val);
}

/* Print the given AnyData value, using one of the above functions
 */
void printValue(AnyData val)
{
    if (val.type == BYTE){
        printByte(val.value.bval);
    } else if (val.type == INT){
        printInt(val.value.ival);
    } else if (val.type == DOUBLE){
        printDouble(val.value.dval);
    }

}



/* Calculate sum between array of AnyData objects.
 * first->points to the first member of the array
 * last->points to the last member of the array
 *
 * Returns the sum as AnyData object. Must be as "small" data type as possible.
 */
AnyData summaaKaksi(AnyData *first, AnyData *last)
{
    AnyData ad;
   
    if (first->type == DOUBLE){
        ad.type = DOUBLE;
        if (last->type == DOUBLE){
            ad.value.dval = (double) first->value.dval + (double) last->value.dval;
        } else if (last->type == INT){
            ad.value.dval = (double) first->value.dval + (double) last->value.ival;
        } else {
            ad.value.dval = (double) first->value.dval + (double) last->value.bval;
        }
    } else if (last->type == DOUBLE){
        ad.type = DOUBLE;
        if (first->type == INT){
            ad.value.dval = (double) first->value.ival + (double) last->value.dval;
        } else {
            ad.value.dval = (double) first->value.bval + (double) last->value.dval;
        }
    } else if (first->type == INT){
        ad.type = INT;
        if (last->type == INT){
            ad.value.dval = (int) first->value.ival + (int) last->value.ival;
        } else {
            ad.value.dval = (int) first->value.ival + (int) last->value.bval;
        }
    } else if (last->type == INT){
        ad.type = INT;
        ad.value.ival = (int) first->value.bval + (int) last->value.ival;
    } else {
        ad.type = BYTE;
        ad.value.bval = first->value.bval + last->value.bval;
    }

    return ad;
}


AnyData calcSum(AnyData *first, AnyData *last){
    AnyData palautettava;
    palautettava.type = BYTE;
    palautettava.value.bval = 0;

    AnyData *summattava = first;
    while(summattava <= last) {
        palautettava = summaaKaksi(&palautettava, summattava);
        summattava++;
    }

    return palautettava;
}
