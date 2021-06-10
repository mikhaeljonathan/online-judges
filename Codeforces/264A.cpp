#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head;
struct Node* curr;
bool right = true;

void insert(int x, char s){
	struct Node* newNode = (struct Node*)malloc(sizeof(Node));
	newNode->data = x;
	if (head == NULL){
		newNode->prev = NULL;
		newNode->next = NULL;
		head = newNode;
	} else {
		if (right){
			newNode->next = curr->next;
			newNode->prev = curr;
			curr->next = newNode;
		} else {
			if (curr == head){
				newNode->next = head;
				newNode->prev = NULL;
				head->prev = newNode;
				head = newNode;
			} else {
				newNode->next = curr;
				newNode->prev = curr->prev;
				curr->prev = newNode;
				newNode->prev->next = newNode;
			}
		}
	}
	curr = newNode;
	if (s == 'l') right = false;
	else right = true;
	return;
}

void print(){
	struct Node* temp = head;
	while (temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
int main (){
	char s[1000005];
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) insert(i + 1, s[i]);
	print();
	return 0;
}
