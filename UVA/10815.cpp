#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

struct Node{
	char s[205];
	struct Node* next;
	struct Node* prev;
};

struct Node* hashTableHead[SIZE];
struct Node* hashTableTail[SIZE];

int isAlphabet(char x){
	return ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'));
}

void changeToLower(char s[]){
	int len = strlen(s);
	
	for (int i = 0; i < len; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 'a' - 'A';

}

int hash(char s[]){
	return s[0] - 'a';
}

void push(char s[]){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->s, s);
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if (hashTableHead[hash(s)] != NULL) {
		struct Node* curr = hashTableHead[hash(s)];
		
		while (curr != NULL) {
			if (!strcmp(curr->s, s)){
				free(newNode);
				return;
			}
			curr = curr->next;
		}
		
		curr = hashTableHead[hash(s)];
		
		while (curr != NULL && strcmp(curr->s, s) < 0) curr = curr->next;

		if (curr != NULL) {
			newNode->prev = curr->prev;
			curr->prev = newNode;
			newNode->next = curr;
			if (newNode->prev != NULL) newNode->prev->next = newNode;
			else hashTableHead[hash(s)] = newNode;
		} else{
			newNode->prev = hashTableTail[hash(s)];
			hashTableTail[hash(s)]->next = newNode;
			hashTableTail[hash(s)] = newNode;
		}
		
	} else {
		hashTableHead[hash(s)] = hashTableTail[hash(s)] = newNode;
	}
	
}

int main (){
	for (int i = 0; i < SIZE; i++) hashTableHead[i] = NULL, hashTableTail[i] = NULL;
	char in[205];
	char x;
	int n = 0;
	bool trigger = false;
	while (scanf("%c", &x) != EOF){
		if (isAlphabet(x)){
			in[n++] = x;
			trigger = true;
		} else if (trigger){
			in[n] = '\0', n = 0;
			changeToLower(in);
			push(in); 
			trigger = false;
		}
	}
	
	for (int i = 0; i < SIZE; i++){
		if (hashTableHead[i] == NULL) continue;
		else {
			struct Node* curr = hashTableHead[i];
			while (curr != NULL){
				printf("%s\n", curr->s);
				curr = curr->next;
			}
		}
	}
	return 0;
}
