#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 9999

typedef struct { 	             
	int data;
	struct Node* next;
}Node;
// Node는 int형 데이터를 담을 수 있으며 다른 노드를 가리킬 수 있도록 next 포인터를 넣어줌.

typedef struct {
	Node* top;
}Stack;
// 여기서의 Stack은 자료구조의 top을 가리키는 것을 의미함.
// Stack a는 1번 묶음의 탑을 가리키고 있으며, Stack b는 2번 묶음의 탑을 가리키는 식으로 stack 구분

void push(Stack *stack, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));// 노드를 동적할당한다. 동적할당이므로 주소를 가리키는 형식이니 포인터!
	node->data = data; // 넣고자하는 데이터를 동적할당한 노드에 대입함.
	node->next = stack->top; // 새로 만든 노드가 top을 가리키도록 함.
	stack->top = node; // 노드를 새로 갱신한다.
}
/* 삽입할 노드의 next가 현재의 top이 될 수 있도록 만들어주며, top이 가리킬 노드를 삽입할 노드를 
가리키도록 함으로써 top을 갱신할 수 있다. */

int pop(Stack* stack) {
	if (stack->top == NULL)
	{
		printf("Stack 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* node = stack->top; //노드포인터를 선언하여 현재 top을 가리키도록 설정
	int data = node->data; // 현재 top의 데이터를 저장!
	stack->top = node->next; // top 노드를 삭제할 예정이므로 가리키고 있는 다음 노드를 top으로 전환
	free(node); // data 임시저장 및 다른 노드르 가리키도록 top을 선언하였으므로 동적할당 해제 가능.
	return data;
}

void show(Stack* stack) {
	Node* curr = stack->top;
	printf("---스택의 최상단---\n");
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	printf("---스택의 최하단---\n");
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