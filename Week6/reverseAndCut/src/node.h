#ifndef NODE_H
#define	NODE_H

struct Node{
	int value;
	struct Node* next;
};


typedef struct Node Node;

Node* newNode(int value);
int getValue(Node* node);
Node* getNext(Node* node);
void setNext(Node* node, Node* next);
void nodeFree(Node* node);

#endif	/* NODE_H */

