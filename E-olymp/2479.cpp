#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char data;
	struct node* next;
}*stack;

int key[300];

void push(char x){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = stack;
	stack = newnode;
}

void pop(){
	if (stack == NULL) return;
	struct node* del = stack;
	stack = stack->next;
	free(del);
}

void freeall(){
	while (stack != NULL) pop();
}

int balance(char in[]){
	int len = strlen(in);
	for (int i = 0; i < len; i++){
		if (in[i] == '(' || in[i] == '[' || in[i] == '{') push(in[i]);
		else {
			if (stack == NULL || key[stack->data] != key[in[i]]) return false;
			else pop();
		}
	}
	if (stack != NULL) return false;
	return true;
}

int main (){
	int n;
	scanf("%d", &n);
	getchar();
	char in[300];
	key['('] = key[')'] = 1;
	key['['] = key[']'] = 2;
	key['{'] = key['}'] = 3;
	while (n--){
		gets(in);
		printf("%s\n", balance(in) ? "Yes" : "No");
		freeall();
	}
	return 0;
}
