#include <check.h>
#include "tmc-check.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../src/source.h"
#include "../src/node.h"

Node* createList(int numbers[], int size){
    Node* root = newNode(numbers[0]);
    Node* prev = root;
    for (int i = 1; i < size; i++){
        Node* new = newNode(numbers[i]);
        setNext(prev, new);
        prev = new;
    }
    return root;
}

Node* createReversedList(int numbers[], int size){
    Node* root = newNode(numbers[size-1]);
    Node* prev = root;
    for (int i = size-2; i >= 0; i--){
        Node* new = newNode(numbers[i]);
        setNext(prev, new);
        prev = new;
    }
    return root;
}

void print_list(char* buf, Node* node) {
    char buf2[10];
    sprintf(buf, "{ ");
    while (node) {
        sprintf(buf2, "%d ", getValue(node));
        strcat(buf, buf2);
        node = getNext(node);
    }
    strcat(buf, "}");
}

void delete_list(Node *node) {
    Node *ptr = NULL;
    while (node) {
        ptr = getNext(node);
        setNext(node, NULL);
        nodeFree(node);
        node = ptr;
    }
}


START_TEST(test_reverse){
    int simple[] = {1, 2, 3, 4, 5};
    
    Node* simpleBefore = createList(simple, 5);
    Node* simpleAfter = createReversedList(simple, 5);
    Node* simpleUser = reverse(simpleBefore);

    Node* rootAfter = simpleAfter;
    Node* rootUser = simpleUser;

    
    char buf1[1000];
    char buf2[1000];
    
    print_list(buf1, simpleAfter);
    print_list(buf2, simpleUser);
    
    while (getNext(simpleAfter) != NULL){
        fail_unless(getValue(simpleUser) == getValue(simpleAfter), "Reverse doesn't work right. Your list was %s and the correct answer is %s", buf2, buf1);
        simpleUser = getNext(simpleUser);
        simpleAfter = getNext(simpleAfter);
    }
    
    int size = (rand() % 10) + 5;
    int numbers[size];
    
    for (int i = 0; i < size; i++){
        int num = rand() % 50;
        numbers[i] = num;
    }
    
    Node* before = createList(numbers, size);
    Node* after = createReversedList(numbers, size);
    Node* userReversed = reverse(before);
    
    Node* user = userReversed;
    Node* right = after;
    
    print_list(buf1, after);
    print_list(buf2, userReversed);
    
    while (getNext(right) != NULL){
        fail_unless(getValue(user) == getValue(right), "Reverse doesn't work right. Your list was %s and the correct answer is %s", buf2, buf1);
        user = getNext(user);
        right = getNext(right);
    }

    delete_list(rootAfter);
    delete_list(rootUser);
    delete_list(after);
    delete_list(userReversed);
}
END_TEST


START_TEST(test_cut){
    int simple[] = {1, 2, 3, 4, 5};
    int afterList[] = {3, 4, 5};
    
    Node* simpleBefore = createList(simple, 5);
    Node* simpleAfter = createList(afterList, 3);
    Node* simpleUser = cut(simpleBefore, 2);
    
    Node* rootAfter = simpleAfter;
    Node* rootUser = simpleUser;
    
    char buf1[100];
    char buf2[100];
    
    print_list(buf1, simpleAfter);
    print_list(buf2, simpleUser);
    
    while (getNext(simpleAfter) != NULL){
        fail_unless(getValue(simpleUser) == getValue(simpleAfter), "Cut doesn't work right. Your list was %s and the correct answer is %s", buf2, buf1);
        simpleUser = getNext(simpleUser);
        simpleAfter = getNext(simpleAfter);
    }
    
    int size = (rand() % 10) + 5;
    int numbers[size];
    
    for (int i = 0; i < size; i++){
        int num = rand() % 50;
        numbers[i] = num;
    }
    Node* before = createList(numbers, size);
    Node* after = createList(numbers + 3, size-3);
    Node* userReversed = cut(before, 3);
    
    Node* user = userReversed;
    Node* right = after;
    
    print_list(buf1, after);
    print_list(buf2, userReversed);
    
    while (getNext(right) != NULL){
        fail_unless(getValue(user) == getValue(right), "Cut doesn't work right. Your list was %s and the correct answer is %s", buf2, buf1);
        user = getNext(user);
        right = getNext(right);
    }
    
    delete_list(rootAfter);
    delete_list(rootUser);
    delete_list(after);
    delete_list(userReversed);
}
END_TEST



int main(int argc, const char *argv[])
{
    srand((unsigned)time(NULL));
	Suite *s = suite_create("ReverseAndCut");
	tmc_register_test(s, test_reverse, "Reverse");
        tmc_register_test(s, test_cut, "Cut");
	return tmc_run_tests(argc, argv, s);
}
