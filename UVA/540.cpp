#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key[1000005];

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}*front, *back, *backTeam[1005];

void push(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	if (back == NULL){
		backTeam[key[x]] = newNode;
		front = back = newNode;
		return;
	}
	
	if (backTeam[key[x]] == NULL){
		newNode->next = back;
		back->prev = newNode;
		back = newNode;
		backTeam[key[x]] = newNode;
		return;
	}
	
	newNode->next = backTeam[key[x]];
	newNode->prev = backTeam[key[x]]->prev;
	backTeam[key[x]]->prev = newNode;
	if (newNode->prev != NULL) newNode->prev->next = newNode;
	else back = newNode;
	backTeam[key[x]] = newNode;
}

int pop(){
	if (front == NULL) return -1;
	else {
		int res = front->data;
		int team = key[front->data];
		struct Node* toBeDeleted = front;
		front = front->prev;
		
		if (front != NULL) {
			if (team != key[front->data]) backTeam[team] = NULL;
			front->next = NULL;
		} else {
			back = NULL;
			backTeam[team] = NULL;
		}
		free(toBeDeleted);
		return res;
	}
}

void freeAll(){
	while (front != NULL) pop();
}

int main (){
	int t;
	int tc = 1;
	while (scanf("%d", &t) && t != 0){
		for (int i = 1; i <= t; i++){
			int e;
			scanf("%d", &e);
			while (e--){
				int x;
				scanf("%d", &x);
				key[x] = i;
			}
		}
		printf("Scenario #%d\n", tc);
		char s[10];
		while (scanf("%s", s) && strcmp(s, "STOP")){
			if (!strcmp(s, "ENQUEUE")) {
				int x;
				scanf("%d", &x);
				push(x);
			} else printf("%d\n", pop());
		}
		puts("");
		tc++;
		freeAll();
	}
	return 0;
}
