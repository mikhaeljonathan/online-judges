#include <stdio.h>
#include <stdlib.h>
#define SIZE 100005

struct node{
	int pos;
	int c;
	struct node* nextadj;
}*hashTable[SIZE];

int visited[SIZE];
int min;

void newnode(int x, int cx){
	struct node* newn = (struct node*) malloc(sizeof(struct node));
	newn->pos = x;
	newn->c= cx;
	newn->nextadj = NULL;
	hashTable[x] = newn;
}

void pushH(int a, int ca, int b, int cb){
	if (!hashTable[a]) newnode(a, ca);
	struct node* newb = (struct node*)malloc(sizeof(struct node));
	newb->pos = b;
	newb->c = cb;
	newb->nextadj = NULL;
	
	if (!hashTable[a]->nextadj){
		hashTable[a]->nextadj = newb;
	} else {
		struct node* cur = hashTable[a]->nextadj;
		while (cur->nextadj) cur = cur->nextadj;
		cur->nextadj = newb;
	}
}

void dfs(int i){
	if (visited[i]) return;
	if (hashTable[i]->c < min) min = hashTable[i]->c;
	visited[i] = 1;
	
	for (struct node* cur = hashTable[i]->nextadj; cur; cur = cur->nextadj){
		if (visited[cur->pos]) continue;
		dfs(cur->pos);
	}
}

int main (){
	for (int i = 0; i < SIZE; i++) {
		hashTable[i] = NULL;
		visited[i] = 0;
	}
	int n, m;
	scanf("%d %d", &n, &m);
	int characters[n];
	for (int i = 0; i < n ;i++) scanf("%d", &characters[i]);
	while (m--){
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		pushH(a, characters[a], b, characters[b]);
		pushH(b, characters[b], a, characters[a]);
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i++){
		if (!hashTable[i]) {
			ans += characters[i];
			visited[i] = 1;
		}
		else {
			if (visited[i]) continue;
			min = characters[i];
			dfs(i);
			ans += min;
		}
	}
	printf("%lld\n", ans);


//	for (int i = 0; i < n; i++){
//		if (!hashTable[i]) continue;
//		printf("current: %d %d\n", hashTable[i]->pos, hashTable[i]->c);
//		printf("adj:");
//		struct node* cur = hashTable[i]->nextadj;
//		while (cur){
//			printf(" %dx%d", cur->pos, cur->c);
//			cur = cur->nextadj;
//		}
//		puts("");
//	}
	return 0;
}
