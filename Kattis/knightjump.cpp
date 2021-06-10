#include <stdio.h>
#include <stdlib.h>

char board[105][105];
int visited[105][105];
int n;

struct tnode{
	int r;
	int c;
	struct tnode *next;
	struct tnode *prev;
};

struct tnode *front(struct tnode *head){
	return head;
}

void push(struct tnode **head, struct tnode **tail, int *count, int r, int c){
	
	struct tnode *newNode = (struct tnode*) malloc(sizeof(tnode));
	newNode->r = r;
	newNode->c = c;
	newNode->next = newNode->prev = NULL;
	
	if(*head == NULL){
		*head = *tail = newNode;
	}
	else{
		(*tail)->next = newNode;
		newNode->prev = *tail;
		*tail = newNode;
	}
	(*count)++;
}

void pop(struct tnode **head, struct tnode **tail, int *count){
	
	if(*head == NULL) return;
	
	struct tnode *tobeDeleted = *head;
	
	*head = (*head)->next;
	free(tobeDeleted);
	
	if(*head == NULL) *tail = NULL;
	else (*head)->prev = NULL;
	(*count)--;
}

int bfs(int x, int y){
	if (x == 0 && y == 0) return 0;
	struct tnode *headQ = NULL;
	struct tnode *tailQ = NULL;
	int Qcount = 0;
	
	push(&headQ, &tailQ, &Qcount, x, y);
	
	for(int i=0; i<n; i++){
		for(int k=0; k<n; k++){
			visited[i][k] = 0;
		}
	}
	
	for(int moves=0; Qcount > 0; moves++){
		
		int currentQueueSize = Qcount;
		
		for(int __=0; __<currentQueueSize; __++){
			
			struct tnode *theFront = front(headQ);
			int currentR = theFront->r;
			int currentC = theFront->c;
			pop(&headQ, &tailQ, &Qcount);
			
			if(currentR == 0 && currentC == 0){
				return moves;
			}
			
			//kalau currentR dan currentC sudah visited, lanjutkan
			if(visited[currentR][currentC]){
				continue;
			}
			
			visited[currentR][currentC] = 1;
			
			int dr[] = {+2, +2, -2, -2, +1, +1, -1, -1}; //delta row
			int dc[] = {+1, -1, +1, -1, +2, -2, +2, -2}; //delta col
			
			for(int i=0; i<8; i++){
				
				int nextR = currentR + dr[i];
				int nextC = currentC + dc[i];
				
				//kalau lewat batas
				if(nextR >= n) continue;
				if(nextR < 0) continue;
				if(nextC >= n) continue;
				if(nextC < 0) continue;
				
				//kalau nextR dan nextC tidak bisa dilalui
				if(board[nextR][nextC] == '#') continue;

				//kalau udah dikunjungi? skip
				if(visited[nextR][nextC] == 1) continue;
				
				push(&headQ, &tailQ, &Qcount, nextR, nextC);
			}
		}
	}
	
	return -1;
}

int main (){
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) scanf("%s", board[i]);
	
	int x, y;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (board[i][j] == 'K') {
				x = i;
				y = j;
			}
		}
	}
	
	int moves = bfs(x, y);
	printf("%d\n", moves);
		
			
	
	return 0;
}
