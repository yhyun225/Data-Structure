#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef enum {false,true}bool;
typedef struct _Node
{
	Data item;
	struct _Node* next;
	struct _Node* prev;
}Node;
typedef struct
{
	Node* head;
	int len;
}DoubleLinkedList;

void InitList(DoubleLinkedList* plist);
bool IsEmpty(DoubleLinkedList* plist);
void Insert(DoubleLinkedList* plist, Data item,int pos);
void Remove(DoubleLinkedList* plist,int pos);
Data ReadItem(DoubleLinkedList* plist,int pos);
void PrintList(DoubleLinkedList* plist);

int main()
{
	DoubleLinkedList dlist;
	InitList(&dlist);

	Insert(&dlist, 0, 0);
	Insert(&dlist, 1, 1);
	Insert(&dlist, 2, 2);

	PrintList(&dlist);

	Remove(&dlist, 1);
	printf("%d\n", ReadItem(&dlist, 1));

	PrintList(&dlist);

	return 0;
}

void InitList(DoubleLinkedList* plist)
{
	Node* dummy1, * dummy2;
	dummy1 = (Node*)malloc(sizeof(Node));
	dummy2 = (Node*)malloc(sizeof(Node));

	dummy1->next = dummy2;
	dummy1->prev = NULL;

	dummy2->next = NULL;
	dummy2->prev = dummy1;

	plist->head = dummy1;
	plist->len = 0;
}
bool IsEmpty(DoubleLinkedList* plist)
{
	return plist->len == 0;
}
void Insert(DoubleLinkedList* plist, Data item,int pos)
{
	if (pos<0 || pos>plist->len)
		exit(1);
	Node* cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->prev = cur;
	newNode->next = cur->next;
	cur->next->prev = newNode;
	cur->next = newNode;

	plist->len++;
}
void Remove(DoubleLinkedList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);
	Node* cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;
	Node* temp = cur->next;
	cur->next = temp->next;
	temp->next->prev = cur;
	free(temp);

	plist->len--;
}
Data ReadItem(DoubleLinkedList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);

	Node* cur = plist->head->next;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	return cur->item;
}

void PrintList(DoubleLinkedList* plist)
{
	for (Node* cur = plist->head->next; cur->next != NULL; cur = cur->next)
		printf("%d\n", cur->item);
}


