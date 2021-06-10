#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node* next;
};

struct Node* stack;

int precedence[300];

bool isOperator(char x){
	return x == '^' || x == '*' || x == '/' || x == '+' || x == '-' ;
}

bool isOperand(char x){
	return !isOperator(x) && x != '(' && x != ')';
}

bool higherPrecedenceOrEqualTo(char x, char y){
	return precedence[x] >= precedence[y];
}

bool empty(){
	return stack == NULL;
}

void push(char x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	if (empty()) newNode->next = NULL;
	else newNode->next = stack;
	stack = newNode;
}

char pop(){
	char ans = stack->data;
	struct Node* temp = stack;
	stack = stack->next;
	free(temp);
	return ans;
}

char top(){
	return stack->data;
}

void freeall(){
	while (stack != NULL){
		struct Node* temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int main (){
	int t;
	scanf("%d", &t);
	getchar();
	precedence['^'] = 3;
	precedence['*'] = 2;
	precedence['/'] = 2;
	precedence['+'] = 1;
	precedence['-'] = 1;
	while(t--){
		char s[500];
		scanf("%s", s);
		getchar();
		int len = strlen(s);
		for (int i = 0; i < len; i++){
			if (isOperand(s[i])) printf("%c", s[i]);
			else if (isOperator(s[i])) {
				while (!empty() && top() != '(' && higherPrecedenceOrEqualTo(top(), s[i])) printf("%c", pop());
				push(s[i]);
			} else if (s[i] == '(') push(s[i]);
			else if (s[i] == ')') {
				while (!empty() && top() != '(') printf("%c", pop());
				pop();
			}
		}
		while (!empty()) printf("%c", pop());
		puts("");
		freeall();
	}
	return 0;
}
