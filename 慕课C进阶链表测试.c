#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	int value;
	struct _node* next;
}Node;
typedef struct _list{
	Node* head;
	Node* tail;
}List;
void add(List *list,int number);
void print(Node *p);
int main(int argc, char* argv[])
{
	int number;
	List list;
	list.head = NULL;
	do{
	
		scanf("%d",&number);
		if(number != -1)
		{
			add(&list,number); 
		}
	
	}while(number != -1);
	print(list.head);
	Node *p;
	Node *q;
	for(p=list.head;p;p=q){
		q=p->next;
		free(p);
	}
	return 0;
} 
void add(List *list,int number)
{
	Node* p=(Node*)malloc(sizeof(Node));
			p->value = number;
			p->next = NULL;
			Node* last = list->head;
			if(last){
				last = list->tail;
				last->next = p;
				list->tail = p;
			}else{
				list->head = list->tail = p;
			}
}
void print(Node *p)
{
	Node *q;
	if(p->next){
		q=p->next;
		print(q);
	}else{
	}
	printf("%d ",p->value);
	
}