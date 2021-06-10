#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	struct Node* next;
	struct Node* prev;
}*stack;

void push(int x){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = x;
	newNode->next = NULL;
	newNode->prev = stack;
	
	if (stack != NULL) stack->next = newNode;
	
	stack = newNode;
	
}

void pop(){
	if (stack == NULL) return;
	
	struct Node* tobedeleted = stack;
	stack = stack->prev;
	if (stack != NULL) stack->next = NULL;
	free(tobedeleted);
}


int main (){
	int n;
	scanf("%d", &n);
	long long res = 0;
	while(n--){
		int x;
		scanf("%d", &x);
		if (stack != NULL && x >= stack->val){
			if (stack->prev != NULL && stack->prev->val < x) res += stack->prev->val;
			else res += x;
			pop();
			if (stack != NULL && stack->val <= x){
				res += x;
				pop();
			}
		}
		push(x);
	}
	pop();
	while (stack != NULL){
		res += stack->val;
		pop();
	}
	printf("%lld\n", res);
	return 0;
}
