#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int val;
	int qty;
	struct Node* next;
}*stack = NULL;

int total = 0;

void add(int x, int y){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = x;
	newNode->qty = y;
	newNode->next = stack;
	stack = newNode;
	total += newNode->qty;
}

void del(int y){
	total -= y;
	while (y > 0){
		if (stack->qty > y){
			stack->qty -= y;
			y = 0;
		} else {
			y -= stack->qty;
			struct Node* tobedeleted = stack;
			stack = stack->next;
			free(tobedeleted);
		}
	}
}

void adx(int x){
	struct Node* curr = stack;
	while (curr != NULL){
		curr->val += x;
		curr = curr->next;
	}
}

void dex(int x){
	struct Node* curr = stack;
	while (curr != NULL){
		curr->val -= x;
		curr = curr->next;
	}
}

int main (){
	int n;
	scanf("%d", &n); getchar();
	while (n--){
		char command[5];
		scanf("%s", command);
		if (!strcmp(command, "add")){
			int x, y;
			scanf("%d %d", &x, &y); getchar();
			add(x, y);
			printf("%d\n", total);
		} else if (!strcmp(command, "del")){
			int y;
			scanf("%d", &y); getchar();
			printf("%d\n", stack->val);
			del(y);
		} else if (!strcmp(command, "adx")){
			int x;
			scanf("%d", &x); getchar();
			adx(x);
		} else {
			int x;
			scanf("%d", &x); getchar();
			dex(x);
		}
	}
	return 0;
}
