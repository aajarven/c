#include <stdio.h>
#include "source.h"

/* Objective: function pointers 
 * Write a function int* bubble_sort(int* numbers, int count, compare comp) that sorts integers in the array numbers using function comp. 
 * You can use bubble sort or some other sorting function that can compare numbers with given comp function. 
 * Count is the length of the array. Function should return sorted array of integers. 
 * NOTE: The array could contain characters and the sort could be done with some funny alphabet order
 */
int main(void){
    int numbers[] = {27, 11, 3, -56, 92, 41, 9};
    int count = sizeof(numbers)/ sizeof(numbers[0]);
    
    printf("Without sorting: ");
    for(int i = 0; i < count; i++){
        printf("%d%s", numbers[i], i == count - 1 ? "\n" : " ");
    }
    
    int* sorted = bubble_sort(numbers, count, sorted_compare);
    printf("Sorted: ");
    for(int i = 0; i < count; i++){
        printf("%d%s", sorted[i], i == count - 1 ? "\n" : " ");
    }
    
    sorted = bubble_sort(numbers, count, reverse_compare);
    printf("Reverse sorted: ");
    for(int i = 0; i < count; i++){
        printf("%d%s", sorted[i], i == count - 1 ? "\n" : " ");
    }
    
    return 0;
}
