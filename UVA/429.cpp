#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 311

struct Node{
	int indexNode;
	struct Node* nextQ;
	struct Node* prevQ;
};

char list[SIZE][20];
int index_;
struct Node *headQ;
struct Node *tailQ;
int count;
int visited[SIZE];

int find(char s[]){
	for (int i = 0; i < index_; i++) if (!strcmp(s, list[i])) return i;
}

int differentOne(char a[], char b[]){
	int lena = strlen(a);
	int lenb = strlen(b);
	if (lena != lenb) return 0;
	int count = 0;
	for (int i = 0; i < lena; i++) if (a[i] != b[i]) count++;
	return (count == 1);
}

void pushQ(int x){
	
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->indexNode = x;
	newNode->nextQ = newNode->prevQ = NULL;
	
	if(headQ == NULL){
		headQ = tailQ = newNode;
	}
	else{
		tailQ->nextQ = newNode;
		newNode->prevQ = tailQ;
		tailQ = newNode;
	}
	count++;
}

void pop(){
	
	if(headQ == NULL) return;
	
	struct Node *tobeDeleted = headQ;
	
	headQ = headQ->nextQ;
	free(tobeDeleted);
	
	if(headQ == NULL) tailQ = NULL;
	else headQ->prevQ = NULL;
	count--;
}

int bfs(char start[], char end[]){
	if (!strcmp(start, end)) return 0;
	count = 0;
	pushQ(find(start));
	
	for (int i = 0; i < SIZE; i++) visited[i] = 0;
	
	for (int moves = 0; count > 0; moves++){
		
		int currentQueueSize = count;
		
		for (int __ = 0; __ < currentQueueSize; __++){
			
			struct Node* theFront = headQ;
			int currIndex = theFront->indexNode;
			char current[20];
			strcpy(current, list[theFront->indexNode]);
			pop();
			
			if (!strcmp(current, end)) return moves;
			
			if (visited[currIndex]) continue;
			
			visited[currIndex] = 1;
			
			for (int i = 0; i < index_; i++){
				
				if (!differentOne(current, list[i])) continue;
				
				if (visited[i]) continue;
				
				pushQ(i);
			}
		}
	}
}

void freeAll(){
	while (headQ != NULL) pop();
}

int main (){
	int n;
	scanf("%d", &n);
	getchar(), getchar();
	while(n--){
		char a[20];
		index_ = 0;
		while (gets(a) && strcmp(a, "*")) strcpy(list[index_++], a);
		
		char temp[40];
		char start[20], end[20];
		while (gets(temp) && strcmp(temp, "")){
			sscanf(temp, "%s %s", start, end);
			printf("%s %s %d\n", start, end, bfs(start, end));
			freeAll();
		}
		if (n != 0) puts("");
	}
	return 0;
}
