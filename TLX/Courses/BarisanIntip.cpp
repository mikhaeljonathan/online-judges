#include <stdio.h>
#include <stdlib.h>

struct Node{
	int val;
	int index;
	struct Node* next;
}*stack;

int total = 0;

void push(int x, int i){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = x;
	newNode->index = i;
	newNode->next = stack;
	stack = newNode;
	total++;
}

void pop(){
	struct Node* tobedeleted = stack;
	stack = stack->next;
	free(tobedeleted);
	total--;
}

int main (){
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		while (total > 0 && stack->val <= x) pop();
		ans += (total == 0) ? i + 1 : i - stack->index;
		push(x, i);
	}
	printf("%lld\n", ans);
	return 0;
}
