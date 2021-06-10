#include <stdio.h>
#include <stdlib.h>

int visited[10][10];
char start[5], end[5];

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

int bfs(){
	struct tnode *headQ = NULL;
	struct tnode *tailQ = NULL;
	int Qcount = 0;
	
	push(&headQ, &tailQ, &Qcount, start[0] - 'a', start[1] - '1');
	
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
				visited[i][j] = 0;
	
	for(int moves=0; Qcount > 0; moves++){

		int currentQueueSize = Qcount;
		
		for(int __=0; __<currentQueueSize; __++){
			
			struct tnode *theFront = front(headQ);
			int currentR = theFront->r;
			int currentC = theFront->c;
			pop(&headQ, &tailQ, &Qcount);
						
			if(currentR == (end[0] - 'a') && currentC == (end[1] - '1')){
				return moves;
			}
			
			//kalau currentR dan currentC sudah visited, lanjutkan
			if(visited[currentR][currentC] == 1){
				continue;
			}
			
			visited[currentR][currentC] = 1;
			
			int dr[] = {+2, +2, -2, -2, +1, +1, -1, -1}; //delta row
			int dc[] = {+1, -1, +1, -1, +2, -2, +2, -2}; //delta col
			
			for(int i=0; i<8; i++){
				int nextR = currentR + dr[i];
				int nextC = currentC + dc[i];
				
				//kalau lewat batas
				if(nextR > 8) continue;
				if(nextR < 0) continue;
				if(nextC > 8) continue;
				if(nextC < 0) continue;
								
				//kalau udah dikunjungi? skip
				if(visited[nextR][nextC] == 1) continue;
				
				push(&headQ, &tailQ, &Qcount, nextR, nextC);
			}
		}
	}
	
	return -1;
}

int main (){
	while (scanf("%s %s", start, end) != EOF){
		int moves = bfs();
		printf("To get from %s to %s takes %d knight moves.\n", start, end, moves);
	}
	return 0;
}
