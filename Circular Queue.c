#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100

typedef int Data;
typedef enum{false, true}bool;
typedef struct
{
	int front, rear;
	Data items[MAX_LEN];
}Queue;

void InitQueue(Queue* pqueue);
bool IsEmpty(Queue* pqueue);
bool IsFull(Queue* pqueue);
void EnQueue(Queue* pqueue);
void DeQueue(Queue* pqueue);
Data Peek(Queue* pqueue);

int main()
{
	Queue queue;
	InitQueue(&queue);

	EnQueue(&queue, 1);
	EnQueue(&queue, 2);

	printf("%d\n", Peek(&queue));
	DeQueue(&queue);

	printf("%d\n", Peek(&queue));
}

void InitQueue(Queue* pqueue)
{
	pqueue->rear = pqueue->front = 0;
}
bool IsEmpty(Queue* pqueue)
{
	return pqueue->rear == pqueue->front;
}
bool IsFull(Queue* pqueue)
{
	return (pqueue->rear + 1) % MAX_LEN == pqueue->front;
}
void EnQueue(Queue* pqueue, Data item)
{
	if (IsFull(pqueue))
		exit(1);
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_LEN;
}
void DeQueue(Queue* pqueue)
{
	if (IsEmpty(pqueue))
		exit(1);
	pqueue->front = (pqueue->front + 1) % MAX_LEN;
}
Data Peek(Queue* pqueue)
{
	if (IsEmpty(pqueue))
		exit(1);
	return pqueue->items[pqueue->front];
}