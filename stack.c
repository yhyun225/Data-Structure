#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100
typedef int Data;
typedef enum{false, true}bool;
typedef struct
{
	int top;
	Data items[MAX_LEN];
}Stack;

void InitStack(Stack* pstack);
bool IsEmpty(Stack* pstack);
bool IsFull(Stack* pstack);
void Push(Stack* pstack, Data item);
void Pop(Stack* pstack);
Data Peek(Stack* pstack);

int main()
{
	Stack stack;
	InitStack(&stack);

	Push(&stack, 1);
	Push(&stack, 2);
	printf("%d\n", Peek(&stack));

	Pop(&stack);
	printf("%d\n", Peek(&stack));
}

void InitStack(Stack* pstack)
{
	pstack->top= - 1;
	return;
}
bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}
bool IsFull(Stack* pstack)
{
	return pstack->top == MAX_LEN-1;
}
void Push(Stack* pstack, Data item)
{
	if (IsFull(pstack))
		exit(1);
	pstack->items[++pstack->top] = item;
}
void Pop(Stack* pstack)
{
	if (IsEmpty(pstack))
		exit(1);
	--(pstack->top);
}
Data Peek(Stack* pstack)
{
	if (IsEmpty(pstack))
		exit(1);
	return pstack->items[pstack->top];
}

