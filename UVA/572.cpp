#include <stdio.h>
#include <stdlib.h>

struct Node{
	int r;
	int c;
	struct Node* next;
};

char field[105][105];
int visited[105][105];
int r, c;
int pocket;
struct Node* stack;
int count;

void push(int r, int c){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->r = r;
	newNode->c = c;
	newNode->next = stack;
	stack = newNode;
	count++;
}

void pop(){
	if (stack == NULL) return;
	struct Node* toBeDeleted = stack;
	stack = stack->next;
	free(toBeDeleted);
	count--;
}

void freeAll(){
	while (stack != NULL) pop();
}

void dfs(){
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			visited[i][j] = 0;
	count = 0;
	
	//here's the dfs
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			
			if (visited[i][j]) continue;
			if (field[i][j] == '*') continue;
			 
			push(i, j);
			
			while (count > 0){
				int currentSize = count;
				
				for (int __ = 0; __ < currentSize; __++){
					
					struct Node* curr = stack;
					int currentR = curr->r;
					int currentC = curr->c;
					pop();
					
					if (visited[currentR][currentC]) continue;
					
					visited[currentR][currentC] = 1;
					
					int dr[] = {+0, +0, +1, -1, +1, -1, +1, -1}; //delta row
					int dc[] = {+1, -1, +0, +0, +1, -1, -1, +1}; //delta col
					for(int i=0; i<8; i++){
				
						int nextR = currentR + dr[i];
						int nextC = currentC + dc[i];
						
						//kalau lewat batas
						if(nextR >= r) continue;
						if(nextR < 0) continue;
						if(nextC >= c) continue;
						if(nextC < 0) continue;
						
						//kalau nextR dan nextC tidak bisa dilalui
						if(field[nextR][nextC] == '*') {
							continue;
						}
						
						//kalau udah dikunjungi? skip
						if(visited[nextR][nextC] == 1) continue;
						
						push(nextR, nextC);
					}
				}
			}
			pocket++;
		}
	}
	
}

int main (){
	while (scanf("%d %d", &r, &c) && r != 0 && c != 0){
		for (int i = 0; i < r; i++) scanf("%s", field[i]), getchar();
		pocket = 0;
		dfs();
		printf("%d\n", pocket);
		freeAll();
	}
	return 0;
}
