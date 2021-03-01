#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef enum{false,true}bool;
typedef struct _Node
{
	Data item;
	struct _Node* next;
}Node;
typedef struct
{
	int len;
	Node* head;
}LinkedList;

void InitList(LinkedList* plist);
bool IsEmpty(LinkedList* plist);
void Insert(LinkedList* plist,int pos,Data item);
void Remove(LinkedList* plist, int pos);
Data ReadItem(LinkedList* plist, int pos);
void PrintList(LinkedList* plist);
void ClearList(LinkedList* plist);

int main()
{
	LinkedList list;
	InitList(&list);

	Insert(&list, 0, 1);
	Insert(&list, 1, 2);
	Insert(&list, 2, 3);

	PrintList(&list);

	Remove(&list, 1);
	printf("%d\n",ReadItem(&list, 1));

	PrintList(&list);
	ClearList(&list);
}

void InitList(LinkedList* plist)
{
	Node* dummy = (Node*)malloc(sizeof(Node));
	dummy->next = NULL;

	plist->head = dummy;
	plist->len = 0;
}
bool IsEmpty(LinkedList* plist)
{
	return plist->len == 0;
}
void Insert(LinkedList* plist, int pos, Data item)
{
	if (pos<0 || pos>plist->len)
		exit(1);

	Node* newNode, * cur;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = NULL;

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	newNode->next = cur->next;
	cur->next = newNode;
	plist->len++;
}
void Remove(LinkedList* plist, int pos)
{
	if (IsEmpty(plist)||pos<0 || pos>=plist->len)
		exit(1);

	Node* cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	Node* temp = cur->next;
	cur->next = temp->next;
	free(temp);
	plist->len--;
}
Data ReadItem(LinkedList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);

	Node* cur = plist->head->next;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	return cur->item;
}
void PrintList(LinkedList* plist)
{
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next)
		printf("%d\n", cur->item);
}
void ClearList(LinkedList* plist)
{
	Node* cur, * temp;
	cur = plist->head->next;
	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	free(plist->head);
}