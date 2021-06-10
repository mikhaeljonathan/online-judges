#include <stdio.h>
#include <stdlib.h>

char board[1005][1005];
int visited[1005][1005];
int r, c;
int moves = 0;

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

void bfs(int x, int y){
	struct tnode *headQ = NULL;
	struct tnode *tailQ = NULL;
	int Qcount = 0;
	
	push(&headQ, &tailQ, &Qcount, x, y);
	
	for(int i=0; i<r; i++){
		for(int k=0; k<c; k++){
			visited[i][k] = 0;
		}
	}
	
	while (Qcount > 0){
		
		int currentQueueSize = Qcount;
		
		for(int __=0; __<currentQueueSize; __++){
			
			struct tnode *theFront = front(headQ);
			int currentR = theFront->r;
			int currentC = theFront->c;
			pop(&headQ, &tailQ, &Qcount);
			
			//kalau currentR dan currentC sudah visited, lanjutkan
			if(visited[currentR][currentC] || board[currentR][currentC] == '#'){
				continue;
			}
			
			if (board[currentR][currentC] == 'G'){
				board[currentR][currentC] = '.';
				moves++;
			} 
			
			visited[currentR][currentC] = 1;
			
			int dr[] = {+1, -1, +0, +0}; //delta row
			int dc[] = {+0, +0, -1, +1}; //delta col
			
			int lanjot = 1;
			
			for (int i = 0; i < 4; i++){
				int nextR = currentR + dr[i];
				int nextC = currentC + dc[i];
				
				if (board[nextR][nextC] == 'T') lanjot = 0;
			}
						
			for(int i=0; i<4; i++){
				
				int nextR = currentR + dr[i];
				int nextC = currentC + dc[i];
				
				//kalau lewat batas
				if(nextR >= r) continue;
				if(nextR < 0) continue;
				if(nextC >= c) continue;
				if(nextC < 0) continue;
				
				//kalau udah dikunjungi? skip
				if(visited[nextR][nextC] == 1) continue;
				
				if (lanjot) push(&headQ, &tailQ, &Qcount, nextR, nextC);
			}
		}
	}
	
}

int main (){
	scanf("%d %d", &c, &r);
	getchar();
	for (int i = 0; i < r; i++) scanf("%s", board[i]);
	
	int x, y;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (board[i][j] == 'P') {
				x = i;
				y = j;
			}
		}
	}
	
	bfs(x, y);
	printf("%d\n", moves);
		
	return 0;
}
