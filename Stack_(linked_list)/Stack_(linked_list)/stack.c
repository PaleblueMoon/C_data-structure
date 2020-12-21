#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 9999

typedef struct { 	             
	int data;
	struct Node* next;
}Node;
// Node�� int�� �����͸� ���� �� ������ �ٸ� ��带 ����ų �� �ֵ��� next �����͸� �־���.

typedef struct {
	Node* top;
}Stack;
// ���⼭�� Stack�� �ڷᱸ���� top�� ����Ű�� ���� �ǹ���.
// Stack a�� 1�� ������ ž�� ����Ű�� ������, Stack b�� 2�� ������ ž�� ����Ű�� ������ stack ����

void push(Stack *stack, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));// ��带 �����Ҵ��Ѵ�. �����Ҵ��̹Ƿ� �ּҸ� ����Ű�� �����̴� ������!
	node->data = data; // �ְ����ϴ� �����͸� �����Ҵ��� ��忡 ������.
	node->next = stack->top; // ���� ���� ��尡 top�� ����Ű���� ��.
	stack->top = node; // ��带 ���� �����Ѵ�.
}
/* ������ ����� next�� ������ top�� �� �� �ֵ��� ������ָ�, top�� ����ų ��带 ������ ��带 
����Ű���� �����ν� top�� ������ �� �ִ�. */

int pop(Stack* stack) {
	if (stack->top == NULL)
	{
		printf("Stack ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = stack->top; //��������͸� �����Ͽ� ���� top�� ����Ű���� ����
	int data = node->data; // ���� top�� �����͸� ����!
	stack->top = node->next; // top ��带 ������ �����̹Ƿ� ����Ű�� �ִ� ���� ��带 top���� ��ȯ
	free(node); // data �ӽ����� �� �ٸ� ��帣 ����Ű���� top�� �����Ͽ����Ƿ� �����Ҵ� ���� ����.
	return data;
}

void show(Stack* stack) {
	Node* curr = stack->top;
	printf("---������ �ֻ��---\n");
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	printf("---������ ���ϴ�---\n");
}

void main()
{
	printf("Welcome message");
	Stack s;
	s.top = NULL;
	push(&s, 7);
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 6);
	pop(&s);
	show(&s);
}