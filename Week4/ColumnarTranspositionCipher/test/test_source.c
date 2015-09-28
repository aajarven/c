#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "../src/source.h"


void pr_array(char *buf, int *arr, int n)
{
    char b[40];
    sprintf(buf, "{");
    while (n--) {
        sprintf(b, "%d", *arr++);
        if (n)
            strcat(b, ", ");
        strcat(buf, b);
    }
    strcat(buf, "}");
}


START_TEST(test_encode_string)
{
    char *strarray[]     = { "one", "abcdefghijklm123",     "abcdefghijkl" };
    int colCount[]       = { 3,     5,                      4};
    char pad []          = {'a',    'X',                    'Z'};
    char *expectedstring[] = { "one", "afk3bglXchmXdi1Xej2X", "aeibfjcgkdhl" };
    int  results[]       = { 3,     20,                     12};
    char resultString[300];
    int location;
    int compRes;

    for (int i = 0; i < 3; i++) {
        location = encode_string(strarray[i],resultString,colCount[i],pad[i]);
//        printf("Test %d: returned location %d, correct location %d\n", i, location, results[i]);
        if (location == 0) {
            fail("Your function encode_string returned 0, which indicates that a) its not yet implemented, b) you did not return the length of the encoded string, c) the encoded sting has no content\n");
        }
        else if (location !=results[i]) {
            fail("Encode_string: function return value incorrect (returned %d expected %d) when calling with string %s, column count %d and pad %c created string %s, expected string %s\n. Maybe padding is not correct, or some issues with the proper indexing of the matrix.\n", location, results[i], strarray[i], colCount[i],pad[i], resultString, expectedstring[i]);
        }
        else if ( (compRes=strcmp(resultString,expectedstring[i])) != 0)  {
            fail("Encode_string: function returned string %s which was not identical with the expected %s  when calling with string %s, column count %d and pad %c\n. Check the ciphering.\n", resultString, expectedstring[i], strarray[i], colCount[i],pad[i]);
        }
    }
}
END_TEST

START_TEST(test_decode_string)
{
    char *expectedstring[]     = { "one", "abcdefghijklm123XXXX", "abcdefghijkl" };
    int colCount[]             = { 3,     5,                      4};
    char pad []                = {'a',    'X',                    'Z'};
    char *strarray[]           = { "one", "afk3bglXchmXdi1Xej2X", "aeibfjcgkdhl" };
    int  results[]             = { 3,     20,                     12};
    char resultString[300];
    int location;
    int compRes;

    for (int i = 0; i < 3; i++) {
        location = decode_string(strarray[i],resultString,colCount[i]);
//        printf("Test %d: returned location %d, correct location %d\n", i, location, results[i]);
        if (location == 0) {
            fail("Your function decode_string returned 0, which indicates that a) its not yet implemented, b) you did not return the length of the encoded string, c) the encoded sting has no content\n");
        }
        else if (location !=results[i]) {
            fail("Decode_string: function return value incorrect (returned %d expected %d) when calling with string %s, column count %d created string %s, expected string %s\n. Are you filling the matrix properly.\n", location, results[i], strarray[i], colCount[i], resultString, expectedstring[i]);
        }
        else if ( (compRes=strcmp(resultString,expectedstring[i])) != 0)  {
            fail("Decode_string: function returned string %s which was not identical with the expected %s  when calling with string %s, column count %d\n. Check the ciphering.\n", resultString, expectedstring[i], strarray[i], colCount[i]);
        }
    }
}
END_TEST

START_TEST(test_encode_string_with_key)
{
    char *strarray[]     = { "one", "abcdefghijklm123",     "abcdefghijkl" };
    char *key[]          = { "one", "abcde",                "15253"};
    char pad []          = {'a',    'X',                    'Z'};
    char *expectedstring[] = { "eno", "afk3bglXchmXdi1Xej2X", "afkchZejZbgldiZ" };
    int  results[]       = { 3,     20,                     15};
    char resultString[300];
    int location;
    int compRes;

    for (int i = 0; i < 3; i++) {
        location = encode_string_with_key(strarray[i],resultString,key[i],pad[i]);
//        printf("Test %d: returned location %d, correct location %d\n", i, location, results[i]);
        if (location == 0) {
            fail("Your function encode_string returned 0, which indicates that a) its not yet implemented, b) you did not return the length of the encoded string, c) the encoded sting has no content\n");
        }
        else if (location !=results[i]) {
            fail("Encode_string: function return value incorrect (returned %d expected %d) when calling with string %s, key %s and pad %c created string %s, expected string %s\n. Maybe padding is not correct, or some issues with the proper indexing of the matrix.\n", location, results[i], strarray[i], key[i],pad[i], resultString, expectedstring[i]);
        }
        else if ( (compRes=strcmp(resultString,expectedstring[i])) != 0)  {
            fail("Encode_string: function returned string %s which was not identical with the expected %s  when calling with string %s, key %s and pad %c\n. Check the ciphering.\n", resultString, expectedstring[i], strarray[i], key[i],pad[i]);
        }
    }
}
END_TEST

START_TEST(test_decode_string_with_key)
{
    char *expectedstring[]     = { "one", "abcdefghijklm123XXXX", "abcdefghijklZZZ" };
    char *key[]                = { "one", "abcde",                "15253"};
    char pad []                = {'a',    'X',                    'Z'};
    char *strarray[]           = { "eno", "afk3bglXchmXdi1Xej2X", "afkchZejZbgldiZ" };
    int  results[]             = { 3,     20,                     15};
    char resultString[300];
    int location;
    int compRes;

    for (int i = 0; i < 3; i++) {
        location = decode_string_with_key(strarray[i],resultString,key[i]);
//        printf("Test %d: returned location %d, correct location %d\n", i, location, results[i]);
        if (location == 0) {
            fail("Your function decode_string returned 0, which indicates that a) its not yet implemented, b) you did not return the length of the encoded string, c) the encoded sting has no content\n");
        }
        else if (location !=results[i]) {
            fail("Decode_string: function return value incorrect (returned %d expected %d) when calling with string %s, key %s created string %s, expected string %s\n. Are you filling the matrix properly.\n", location, results[i], strarray[i], key[i], resultString, expectedstring[i]);
        }
        else if ( (compRes=strcmp(resultString,expectedstring[i])) != 0)  {
            fail("Decode_string: function returned string %s which was not identical with the expected %s  when calling with string %s, key %s.\nCheck the ciphering.\n", resultString, expectedstring[i], strarray[i], key[i]);
        }
    }
}
END_TEST


int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
    Suite *s = suite_create("ColumnarCipher");

    tmc_register_test(s, test_encode_string, "EncodeString");
    tmc_register_test(s, test_decode_string, "DecodeString");
    tmc_register_test(s, test_encode_string_with_key, "EncodeWithKey");
    tmc_register_test(s, test_decode_string_with_key, "DecodeWithKey");

    return tmc_run_tests(argc, argv, s);
}
