#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head;

void deleteFront(){
	if (head == NULL) return;
	else {
		struct Node* temp = head;
		head = head->next;
		free(temp);
	}
}

void insertFront(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = head;
	head = newNode;
}

void insertAtIndex(int index, int x){
	if (head == NULL || index == 0) insertFront(x);
	else {
		struct Node* curr = head;
		for (int i = 0; i < index - 1; i++){
			if (curr->next == NULL) break;
			curr = curr->next;
		}
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

void deleteAtIndex(int index){
	if (head == NULL) return;
	if (head->next == NULL || index == 0) deleteFront();
	else {
		struct Node* curr = head;
		for (int i = 0; i < index - 1; i++){
			curr = curr->next;
			if (curr->next == NULL) return;
		}
		struct Node* deleted = curr->next;
		curr->next = curr->next->next;
		free(deleted);
	}
}

void print(){
	if (head == NULL) puts("empty");
	else {
		struct Node* curr = head;
		while (curr != NULL){
			printf("%d", curr->data);
			if (curr->next != NULL) printf(" ");
			curr = curr->next;
		}
		puts("");
	}
}

int main (){
	char tmp;
	scanf("%c", &tmp);
	while (tmp != 'q'){
		getchar();
		if (tmp == 'f'){
			int x;
			scanf("%d", &x); getchar();
			insertFront(x);
		} else if (tmp == 'i'){
			int index, x;
			scanf("%d %d", &index, &x); getchar();
			insertAtIndex(index, x);
		} else if (tmp == 'r'){
			deleteFront();
		} else if (tmp == 'd'){
			int index;
			scanf("%d", &index); getchar();
			deleteAtIndex(index);
		}
		print();
		scanf("%c", &tmp);
	}
	return 0;
}
