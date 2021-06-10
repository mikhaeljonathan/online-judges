#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int val;
	int qty;
	struct Node* next;
}*front, *tail;

int total = 0;

void add(int x, int y){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = x;
	newNode->qty = y;
	newNode->next = NULL;

	if (front == NULL){
		front = tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
	
	total += newNode->qty;
}

void del(int y){
	total -= y;
	while (y > 0){
		if (front->qty > y){
			front->qty -= y;
			y = 0;
		} else {
			y -= front->qty;
			struct Node* tobedeleted = front;
			front = front->next;
			free(tobedeleted);
		}
	}
}

void rev(){
	struct Node* temp = NULL;
	struct Node* curr = front;
	tail = front;
	while (curr != NULL){
		struct Node* nextcurr = curr->next;
		curr->next = temp;
		temp = curr;
		curr = nextcurr;
		if (curr == NULL){
			front = temp;
		}
	}
}

int main (){
	int n;
	scanf("%d", &n); getchar();
	while (n--){
		char command[5];
		scanf("%s", command);
		if (!strcmp(command, "add")) {
			int x, y;
			scanf("%d %d", &x, &y); getchar();
			add(x, y);
			printf("%d\n", total);
		} else if (!strcmp(command, "del")){
			int y;
			scanf("%d", &y); getchar();
			printf("%d\n", front->val);
			del(y);
		} else {
			rev();
		}
	}
	return 0;
}
