#ifndef _NODE_H_
#define _NODE_H_
typedef struct _node {
	int value;
	struct _node* next;
}Node;
typedef struct _list {
	Node* head;
}List;
void add(List* plist, int number);
void print(Node* p);
#endif
