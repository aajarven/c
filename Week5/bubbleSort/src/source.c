#include "source.h"


int* bubble_sort(int* numbers, int count, compare comp){
    int *tutkittava = numbers;
    int *viimeinen = &(numbers[count-1]);

    while(viimeinen > numbers){
        while(tutkittava < viimeinen){
            if(comp(*tutkittava, tutkittava[1]) > 0){
                int tmp = *tutkittava;
                *tutkittava = tutkittava[1];
                tutkittava[1] = tmp;
            }
            tutkittava++;
        }
        viimeinen--;
        tutkittava = numbers;
    }

    return numbers;
}

int sorted_compare(int first, int second){
    return first - second;
}

int reverse_compare(int first, int second){
    return second - first;
}
