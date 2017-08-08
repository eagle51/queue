#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>

using namespace std;
typedef struct node {
	int data;
	struct node *next;
}Node, *PNode;

typedef struct linkqueue {
	PNode first;
	PNode rear;
}Queue, *PQueue;

PQueue insert(PQueue link, int x)
{
	PNode s;
	s = (PNode)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;

	if (link == NULL) {
		link = (PQueue)malloc(sizeof(Queue));
		link->first = s;
		link->rear = s;
		link->rear->next = NULL;
	}
	else {
		link->rear->next = s;
		link->rear = s;
		link->rear->next = NULL;
	}

	return link;
}

PQueue del(PQueue link)
{
	PNode p;
	if (link == NULL) {
		printf("队列为空\n");
		return NULL;
	}

	p = link->first;
	if (link->first != link->rear) {
		link->first = link->first->next;
	}
	else {
		printf("删除完毕\n");
	}
	free(p);
	p = NULL;
	return link;
}

void print(PQueue link)
{
	PNode p = link->first;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main(void)
{
	PQueue linkqueue = NULL;

	linkqueue = insert(linkqueue, 5);
	print(linkqueue);
	linkqueue = insert(linkqueue, 4);
	print(linkqueue);
	linkqueue = insert(linkqueue, 3);
	print(linkqueue);
	linkqueue = insert(linkqueue, 2);
	print(linkqueue);
	linkqueue = insert(linkqueue, 1);
	print(linkqueue);
	linkqueue = del(linkqueue);
	print(linkqueue);
	linkqueue = del(linkqueue);
	print(linkqueue);
	linkqueue = del(linkqueue);
	print(linkqueue);
	linkqueue = del(linkqueue);
	print(linkqueue);
	linkqueue = del(linkqueue);
	system("pause");
	return 0;
}