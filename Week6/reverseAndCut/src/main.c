#include <stdio.h>
#include "node.h"
#include "source.h"

/* Singly linked list consists of nodes that have an integer value and pointer to the next node.
 * You can get next node using function getNext(Node* node) and set next node using function setNext(Node* node, Node* nextNode).
 * Implement function Node* reverse(Node* root) in source.c. 
 * Function gets a pointer to the first node in linked list. 
 * Function should reverse that linked list and return a pointer to the new first node of the list.
 * Implement function Node* cut(Node* root, int i) in source.c.
 * Function gets a pointer to the first node in a linked list and the cutting length.
 * Function should cut first i nodes away from a linked list and return pointer to the first node of the rest of the list.*/

int main() {
    
    Node* root = newNode(1);
    Node* prev = root;
    for(int i = 2; i < 10; i++){
        Node* node = newNode(i);
        setNext(prev, node);
        prev = node;
    }
    Node* next = getNext(root);
    printf("List:\n%d\n", getValue(root));
    
    while(next != NULL){
        Node* node = next;
        printf("%d\n", getValue(node));
        next = getNext(node);
    }
    
    root = reverse(root);
    next = getNext(root);
    printf("Reverse list:\n%d\n", getValue(root));
    
    while(next != NULL){
        Node* node = next;
        printf("%d\n", getValue(node));
        next = getNext(node);
    }
    
    Node* second_root = cut(root, 3);
    
    next = getNext(second_root);
    printf("Cut list:\n%d\n", getValue(second_root));
    
    while(next != NULL){
        Node* node = next;
        printf("%d\n", getValue(node));
        next = getNext(node);
    }
    
    return 0;
}
