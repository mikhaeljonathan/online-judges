#include <stdio.h>
#include <stdlib.h>

struct Node{
	char data;
	struct Node* next;
};

struct Node* stack;

int precedence[300];

bool isOperator(char x){
	return x == '*' || x == '/' || x == '+' || x == '-' ;
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
	precedence['*'] = 2;
	precedence['/'] = 2;
	precedence['+'] = 1;
	precedence['-'] = 1;
	int t;
	scanf("%d", &t);
	getchar();
	getchar();
	while (t--){
		char x;
		while (scanf("%c", &x) != EOF && x != '\n'){
			getchar();
			if (isOperand(x)) printf("%c", x);
			else if (isOperator(x)) {
				while (!empty() && top() != '(' && higherPrecedenceOrEqualTo(top(), x)) printf("%c", pop());
				push(x);
			} else if (x == '(') push(x);
			else if (x == ')') {
				while (!empty() && top() != '(') printf("%c", pop());
				pop();
			}
		}
		while (!empty()) printf("%c", pop());
		freeall();
		if (t != 0) puts("");
		puts("");
	}
	return 0;
}
