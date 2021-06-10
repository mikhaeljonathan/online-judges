#include <stdio.h>
#include <stdlib.h>

char forest[205][205];
int visited[205][205];
int R, C;

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

int isEmpty(struct tnode *head, struct tnode *tail){
	return (head == NULL);
}

int getSize(struct tnode *head, struct tnode *tail, int count){
	return count;
}

int bfs(){
	
	if(forest[1][1] == 1) return -1;
	struct tnode *headQ = NULL;
	struct tnode *tailQ = NULL;
	int Qcount = 0;
	
	push(&headQ, &tailQ, &Qcount, 1, 1); //push 1,1 ke queue
	
	for(int i=0; i<=R; i++){
		for(int k=0; k<=C; k++){
			visited[i][k] = 0;
		}
	}
	
	//here is the bfs
	for(int moves=0; getSize(headQ, tailQ, Qcount)>0; moves++){
		
		int currentQueueSize = getSize(headQ, tailQ, Qcount);
		
		for(int __=0; __<currentQueueSize; __++){
			
			struct tnode *theFront = front(headQ);
			int currentR = theFront->r;
			int currentC = theFront->c;
			pop(&headQ, &tailQ, &Qcount);
			
			if(currentR == R && currentC == C){
				return moves;
			}
			
//			kalau currentR dan currentC sudah visited, lanjutkan
			if(visited[currentR][currentC]){
				continue;
			}
			
			visited[currentR][currentC] = 1;
			
			int dr[] = {+1, -1, +0, +0}; //delta row
			int dc[] = {+0, +0, -1, +1}; //delta col
			
			for(int i=0; i<4; i++){
				
				int nextR = currentR + dr[i];
				int nextC = currentC + dc[i];
				
				//kalau lewat batas
				if(nextR > R) continue;
				if(nextR < 1) continue;
				if(nextC > C) continue;
				if(nextC < 1) continue;
				
				//kalau nextR dan nextC tidak bisa dilalui
				if(forest[nextR][nextC] == 1) continue;

				//kalau udah dikunjungi? skip
				if(visited[nextR][nextC] == 1) continue;
				
				push(&headQ, &tailQ, &Qcount, nextR, nextC);
			}
		}
	}
	
	return -1;
}

int main(){
	
	while(scanf("%d %d", &R, &C) != EOF){
		if(R == 0 && C == 0){
			break;
		}
		
		for(int i=0; i<=R; i++){
			for(int k=0; k<=C; k++){
				forest[i][k] = 0;
			}
		}
		
		int m;
		scanf("%d", &m);
		for(int i=0; i<m; i++){
			int r, c;
			scanf("%d %d", &r, &c);
			forest[r][c] = 1;
		}
		
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int r, c, L;
			scanf("%d %d %d", &r, &c, &L);
			
			int rowKeAtas = r - L;
			if(rowKeAtas < 1) rowKeAtas = 1;
			
			int rowKeBawah = r + L;
			if(rowKeBawah > R) rowKeBawah = R;
			
			int colKeKiri = c - L;
			if(colKeKiri < 1) colKeKiri = 1;
			
			int colKeKanan = c + L;
			if(colKeKanan > C) colKeKanan = C;
			
			for(int ii=rowKeAtas; ii<=rowKeBawah; ii++){
				for(int kk=colKeKiri; kk<=colKeKanan; kk++){
					if((ii-r)*(ii-r) + (kk-c)*(kk-c) <= (L*L)){
						forest[ii][kk] = 1;
					}
				}
			}
		}
		
		int moves = bfs();
		if(moves == -1) puts("Impossible.");
		else printf("%d\n", moves);
	}
	
	return 0;
}
