#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char data;
	struct Node* next;
};

struct Node* head;
struct Node* tail;
struct Node* curr;

void push(char x){
	struct Node* newNode = (struct Node*) malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = curr->next;
	curr->next = newNode;
	curr = newNode;
	if (curr->next == NULL) tail = curr;
}

void print(){
	struct Node* temp = head->next;
	while (temp != NULL){
		printf("%c", temp->data);
		temp = temp->next;
	}
	puts("");
}

void free(){
	struct Node* temp = head->next;
	while (temp != NULL){
		struct Node* deleted = temp;
		temp = temp->next;
		free(deleted);
	}
}

int main (){
	char s[100005];
	struct Node* temp = (struct Node*) malloc(sizeof(Node));
	temp->data = '#'; //junk data
	while (scanf("%s", s) != EOF){
		getchar();
		temp->next = NULL;
		tail = curr = head = temp;
		int len = strlen(s);
		for (int i = 0; i < len; i++){
			if (s[i] == '[') curr = head;
			else if (s[i] == ']') curr = tail;
			else push(s[i]);
		}
		print();
		free();
	}
	return 0;
}
