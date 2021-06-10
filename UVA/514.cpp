#include <stdio.h>
#include <stdlib.h>
 
struct Node{
	int data;
	struct Node* next;
};

struct Node* stack;

bool empty(){
	return stack == NULL;
}

void push(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	if (empty()) newNode->next = NULL;
	else newNode->next = stack;
	stack = newNode;
}

void pop(){
	if (stack == NULL) return;
	struct Node* temp = stack;
	stack = stack->next;
	free(temp);
}

int top(){
	if (stack == NULL) return -1;
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
	int n;
	scanf("%d", &n);
	while (n != 0){
		int train[n];
		bool temp = false;
		while (1){
			for (int i = 0; i < n; i++){
				scanf("%d", &train[i]);
				if (train[i] == 0){
					temp = true;
					break;
				} 
			}
			if (temp) break;
			int i = 1;
			int k = 0;
			while (i <= n){
				while (!empty() && top() == train[k]) k++, pop();
				if (i != train[k]) push(i);
				else k++;
				i++;
			}
			while (!empty() && top() == train[k]) k++, pop();	
			puts((k == n) ? "Yes" : "No");
			freeall();
		}
		scanf("%d", &n);
		puts("");
	}
	return 0;
}
