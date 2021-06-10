#include <stdio.h>
#include <stdlib.h>

char map[205][205];
int visited[205][205];
int r, c, x, y;
int qcount;

struct node{
	int x;
	int y;
	struct node* next;
}*head, *tail;

struct fire{
	int x;
	int y;
	struct fire* next;
}*headf, *tailf;

void push(int x, int y){
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->x = x;
	newn->y = y;
	newn->next = NULL;
	map[x][y] = 'J';
	
	if (head == NULL){
		head = tail = newn;
	} else {
		tail->next = newn;
		tail = newn;
	}
	
	qcount++;
}

void pop(){
	if (head == NULL) return;
	
	if (head == tail){
		head = tail = NULL;
	} else {
		struct node* tobedel = head;
		head = head->next;
		free(tobedel);
	}
	qcount--;
}

void freeall(){
	while (head) pop();
}

void pushfire(int x, int y){
	struct fire* newf = (struct fire*)malloc(sizeof(struct fire));
	newf->x = x;
	newf->y = y;
	newf->next = NULL;
	
	if (headf == NULL){
		headf = tailf = newf;
	} else {
		tailf->next = newf;
		tailf = newf;
	}
}

void burnn(){
	while (headf){
		int i = headf->x;
		int j = headf->y;
		if (i != 0 && map[i - 1][j] == '.') map[i - 1][j] = 'F';
		if (j != 0 && map[i][j - 1] == '.') map[i][j - 1] = 'F';
		if (i != r - 1 && map[i + 1][j] == '.') map[i + 1][j] = 'F';
		if (j != c - 1 && map[i][j + 1] == '.') map[i][j + 1] = 'F';
		struct fire* tobedel = headf;
		headf = headf->next;
		free(tobedel);
	}
}

void apinyanyebarbos(){
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (map[i][j] == 'F') pushfire(i, j);
	burnn();
}

void printsemua(){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int bfs (){
	head = tail = NULL;
	headf = tailf = NULL;
	push(x, y);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) visited[i][j] = 0;
	for (int moves = 0; qcount > 0; moves++){
		apinyanyebarbos();
//		printsemua();
		int cursize = qcount;
		
		for (int __ = 0; __ < cursize; __++){
			struct node* cur = head;
			int curx = cur->x;
			int cury = cur->y;
			pop();
			
			if (visited[curx][cury]) continue;
			
			visited[curx][cury] = 1;
			
			int dr[] = {+1, -1, +0, -0};
			int dc[] = {+0, - 0, -1, + 1};
			
			for (int i = 0; i < 4; i++){
				int nextx = curx + dr[i];
				int nexty = cury + dc[i];
				
//				printf("nextx %d nexty %d %c\n", nextx, nexty, map[nextx][nexty]);
				if (nextx == r || nexty == c || nextx < 0 || nexty < 0) return moves + 1;
				
				if (map[nextx][nexty] != '.') continue;
				
				if (visited[nextx][nexty]) continue;
				
				push(nextx, nexty);
			}
			
		}
	}
	
	return -1;
}

int main (){
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++){
		scanf("%d %d", &r, &c); getchar();
		qcount = 0;
		for (int i = 0; i < r; i++) scanf("%s", map[i]);
		for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (map[i][j] == 'J') x = i, y = j;
		int ans = bfs();
		if (ans == -1) printf("Case %d: IMPOSSIBLE\n", tc);
		else printf("Case %d: %d\n", tc, ans);
		freeall();
	}
	return 0;
}
