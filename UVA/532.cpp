#include <stdio.h>
#include <stdlib.h>

char dungeon[50][50][50];
int visited[50][50][50];
int l, r, c;

struct tnode{
	int l;
	int r;
	int c;
	struct tnode *next;
	struct tnode *prev;
};

struct tnode *front(struct tnode *head){
	return head;
}

void push(struct tnode **head, struct tnode **tail, int *count, int l, int r, int c){
	struct tnode *newNode = (struct tnode*) malloc(sizeof(tnode));
	newNode->l = l;
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

int bfs(int templ, int tempr, int tempc){
	struct tnode *headQ = NULL;
	struct tnode *tailQ = NULL;
	int Qcount = 0;
	
	push(&headQ, &tailQ, &Qcount, templ, tempr, tempc);
	
	for(int i=0; i<l; i++)
		for(int j=0; j<r; j++)
			for (int k=0; k<c; k++)
				visited[i][j][k] = 0;
	
	for(int moves=0; Qcount > 0; moves++){

		int currentQueueSize = Qcount;
		
		for(int __=0; __<currentQueueSize; __++){
			
			struct tnode *theFront = front(headQ);
			int currentL = theFront->l;
			int currentR = theFront->r;
			int currentC = theFront->c;
			pop(&headQ, &tailQ, &Qcount);
						
			if(dungeon[currentL][currentR][currentC] == 'E'){
				return moves;
			}
			
			//kalau currentR dan currentC sudah visited, lanjutkan
			if(visited[currentL][currentR][currentC] == 1 || dungeon[currentL][currentR][currentC] == '#'){
				continue;
			}
			
			visited[currentL][currentR][currentC] = 1;
			
			int dl[] = {+0, +0, +0, +0, +1, -1}; //delta level
			int dr[] = {+1, -1, +0, +0, +0, +0}; //delta row
			int dc[] = {+0, +0, -1, +1, +0, +0}; //delta col
			
			for(int i=0; i<6; i++){
				int nextL = currentL + dl[i];
				int nextR = currentR + dr[i];
				int nextC = currentC + dc[i];
				
				//kalau lewat batas
				if(nextL >= l) continue;
				if(nextL < 0) continue;
				if(nextR >= r) continue;
				if(nextR < 0) continue;
				if(nextC >= c) continue;
				if(nextC < 0) continue;
								
				//kalau nextR dan nextC tidak bisa dilalui
				if(dungeon[nextL][nextR][nextC] == '#') continue;

				//kalau udah dikunjungi? skip
				if(visited[nextL][nextR][nextC] == 1) continue;
				
				push(&headQ, &tailQ, &Qcount, nextL, nextR, nextC);
			}
		}
	}
	
	return -1;
}

int main (){
	while (scanf("%d %d %d", &l, &r, &c) && l != 0 && r != 0 && c != 0){
		getchar();
		for (int i = 0; i < l; i++){
			for (int j = 0; j < r; j++) {
				scanf("%s", dungeon[i][j]);
				getchar();
			}
			getchar();
		}
		int templ, tempr, tempc;
		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				for (int k = 0; k < c; k++)
					if (dungeon[i][j][k] == 'S')
						templ = i, tempr = j, tempc = k;
			
		int moves = bfs(templ, tempr, tempc);
		if (moves != -1) printf("Escaped in %d minute(s).\n", moves);
		else puts("Trapped!");
	}
	
	return 0;
}
