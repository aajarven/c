#include <stdlib.h>
#include <stdio.h>
#include "source.h"
#include "node.h"

Node* reverse(Node* root){
    if (root == NULL){
        return root;
    }
    Node *edellinen = root;
    Node *nykyinen = getNext(root);
    setNext(root, NULL);
    Node *seuraava;
    while(nykyinen != NULL){
        //printf("aluksi:\n nykyinen: %i\n edellinen: %i\n", nykyinen->value, edellinen->value);
        seuraava = getNext(nykyinen);
        //printf("nykyinen->nexti\n");
        setNext(nykyinen, edellinen);
        //printf("edellineni\n");
        edellinen = nykyinen;
        //printf("nykyineni\n");
        nykyinen = seuraava;
    }
    return edellinen;
}

Node* cut(Node* root, int i){
    Node *edellinen;
    for(int j=0; j<i; j++){
        edellinen = root;
        root = getNext(root);
        free(edellinen);
    }
    
    return root;
}

