#include <stdlib.h>
#include "node.h"

struct Node{
    int value;
    Node* next;
};

Node* newNode(int value){
    Node* node;
    
    node = malloc(sizeof(Node));
    
    if (node == NULL){
        return NULL;
    }
    
    node->value = value;
    node->next = NULL;
    
    return node;
}

int getValue(Node* node){
    return node->value;
}

Node* getNext(Node* node){
    return node->next;
}

void setNext(Node* node, Node* next){
    node->next = next;
}

void nodeFree(Node* node){
    free(node);
    return;
}
