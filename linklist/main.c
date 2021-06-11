#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(int argc, char *argv[]) 
{
	int number;
	List list;
	list.head = NULL;
	do{
		scanf("%d",&number); 
		if(number!=-1){
			add(&list,number);
		}
		
	}while(number!=-1);
	Node* p= list.head;
	print(p);
	return 0;
}
void add(List *pList,int number)
{
	Node *p=(Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node* last = pList->head;
	if(last){
		while(last->next){
			last=last->next;
		}
		last->next=p;
	}else{
		pList->head = p;
	}
}
void print(Node *p)
{
	int count = 1;
	for (; p;p=p->next) {
		printf("p%d->value=%d\t",count,p->value);
		count++;
	}
	
}
