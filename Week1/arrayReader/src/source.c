#include "source.h"
#include <stdio.h>

int array_reader(int* array, int maxSize) {
   for(int i=0; i<maxSize; i++){
       int luettu;
       if(!scanf("%i", &luettu)){
           return i;
       } else {
           array[i]=luettu;
       }
   }
   return maxSize;

}
