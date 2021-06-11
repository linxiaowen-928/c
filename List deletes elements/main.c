#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(int argc, char* argv[])
{
	int number;
	List list;
	list.head = NULL;
	do {
		scanf_s("%d", &number);
		if (number != -1) {
			add(&list, number);
		}

	} while (number != -1);
	Node* p = list.head;
	print(p);
	printf("请输入要删除的值：");
	scanf_s("%d", &number);
	int isFound = 0;
	for (p = list.head; p; p = p->next) {
		if (p->value == number) {
			printf("找到了%d\n", number);
				isFound = 1;
			break;
		}
	}
	if (!isFound) {
		printf("没找到%d\n", number);
	}
	Node* q;
	for (q = NULL, p = list.head; p; q = p, p = p->next) {
		if (p->value == number) {
			if (q) {									//边界条件判断保证可以删除链表第一个的值 
				q->next = p->next;
			}
			else {
				list.head = p->next;
			}
			free(p);
			printf("删除成功");
			break;
		}
	}
	p=list.head;
	print(p);
	return 0;
}
void add(List* pList, int number)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node* last = pList->head;
	if (last) {
		while (last->next) {
			last = last->next;
		}
		last->next = p;
	}
	else {
		pList->head = p;
	}
}
void print(Node* p)
{
	int count = 1;
	for (; p; p = p->next) {
		printf("p%d->value=%d\n", count, p->value);
		count++;
	}

}