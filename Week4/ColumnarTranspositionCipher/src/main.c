#include <stdio.h>
#include <string.h>
#include "source.h"

int main()
{
    /* Write function void locate_string, that find the string from the stringarray. The string, array 
     * and the array size are given as parameters.
     * If the string is found from the array, function returns the first found position of the string 
     *in the array. 
     * If the string is not found, function returns -1.
     */


   char *plainstrings [] = {"1234567890abcdefghijklmno", "The tomato is a plant in the nightshade family", "sho"};
   char *keys[] ={"abcd","tomato","321"};
   char pads[]  ={'Z','X','A'};

   char ciphertext[300];
   char plaintext[300];

   int i;


   printf("First without the key\n");

   for (i=0; i<3;i++) {
      printf("Plaintext: %s\n", plainstrings[i]);
      encode_string(plainstrings[i],ciphertext,strlen(keys[i]), pads[i]);
      printf("Cipherstr: %s\n",ciphertext);
      decode_string(ciphertext, plaintext, strlen(keys[i]));
      printf("Plaintext: %s\n",plaintext);
   }


/*   printf("\nThen the ciphering with key.\n");

   for (i=0; i<3; i++) {
      printf("Plaintext: %s\n", plainstrings[i]);
      encode_string_with_key(plainstrings[i],ciphertext,keys[i], pads[i]);
      printf("Cipherstr: %s\n",ciphertext);
      decode_string_with_key(ciphertext, plaintext, keys[i]);
      printf("Plaintext: %s\n", plaintext);
   }
*/
   return 0;
}



