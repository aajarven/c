#include <stdio.h>

void multiply_matrix(int size){
    for(int i=1; i<=size; i++){
     for(int j=1; j<=size; j++){
      printf("%i", i*j);
      /*if(j==size){
        printf("\n");
      } else {*/
       printf("\t");
      /*}*/
     }
     printf("\n");
    }
}
