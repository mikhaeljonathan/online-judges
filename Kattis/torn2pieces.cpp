#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 97
#define SIZE 10007

struct station{
	char name[25];
	char strict[25];
	int visited;
	struct station* adj;
	struct station* nextH;
	struct station* nextQ;
	struct station* prevState;
}*hashTable[SIZE], *Qhead, *Qtail;

int qcount = 0;

struct station* newstation(char in[]){
	struct station* news = (struct station*)malloc(sizeof(struct station));
	strcpy(news->name, in);
	strcpy(news->strict, "");
	news->adj = NULL;
	news->visited = 0;
	news->nextH = NULL;
	news->nextQ = NULL;
	news->prevState = NULL;
}

int hash(char in[]){
	int len = strlen(in);
	int ret = 0;
	for (int i = 0; i < len; i++){
		ret = ((ret * BASE) + in[i] - 'A' + 1) % SIZE;
	}
	ret %= SIZE;
	return ret;
}

void pushH(char in[]){
	struct station* news = newstation(in);
	news->nextH = hashTable[hash(in)];
	hashTable[hash(in)] = news;
}

struct station* find(char in[]){
	struct station* cur = hashTable[hash(in)];
	while (cur){
		if (!strcmp(cur->name, in)) return cur;
		cur = cur->nextH;
	}
	return NULL;
}

struct station* findAdj(char begin[], char end[]){
	struct station* cur = find(begin);
	while (cur){
		if (!strcmp(cur->name, end)) return cur;
		cur = cur->adj;
	}
	return NULL;
}

void pushAdjStrict(char begin[], char end[]){
	if (!find(begin)) pushH(begin);
	if (!find(end)) pushH(end);
	
	strcpy(find(begin)->strict, end);
}

void pushAdj(char begin[], char end[]){
	if (!find(begin)) pushH(begin);
	if (!find(end)) pushH(end);
	
	if (findAdj(begin, end)) return;
	struct station* news = newstation(end);
	news->adj = find(begin)->adj;
	find(begin)->adj = news;
}

void pushQ(char in[], struct station* prev){
	struct station* news = newstation(in);
	news->prevState = prev;
	
	if (!Qhead){
		Qhead = Qtail = news;
	} else {
		Qtail->nextQ = news;
		Qtail = news;
	}
	
	qcount++;
}

void popQ(){
	if (!Qhead) return;
	
	if (Qhead == Qtail){
		Qhead = Qtail = NULL;
	} else {
		Qhead = Qhead->nextQ;
	}
	
	qcount--;
}

struct station* bfs(char begin[], char end[]){
	find(begin)->prevState = NULL;
	find(begin)->visited = 1;
	pushQ(find(find(begin)->strict)->name, find(begin));
	while (qcount > 0){
		int cursize = qcount;
		for (int __ = 0; __ < cursize; __++){
			char x[25];
			struct station* cur = Qhead;
//			printf("cur %s\n", cur->name);
			strcpy(x, cur->name);
			popQ();
			
			if (!strcmp(cur->name, end)) return cur;
			
			if (find(cur->name) && find(cur->name)->visited) continue;
			
			find(cur->name)->visited = 1;
			for (struct station* adj = find(cur->name)->adj; adj; adj = adj->adj){
				if (find(adj->name) && find(adj->name)->visited) continue;
				pushQ(adj->name, cur);
			}
		}
	}
	return NULL;
}

void print(struct station *ans, char end[]){
	if (!ans) return;
	print(ans->prevState, end);
	if (strcmp(ans->name, end)) printf("%s ", ans->name);
}

void init(){
	for (int i = 0; i < SIZE; i++) hashTable[i] = NULL;
	qcount = 0;
}

int main (){
	int n;
	scanf("%d", &n); getchar();
	char in[1000];
	char begin[25];
	char end[25];
	init();
	while (n--){
		scanf("%s", begin); getchar();
		scanf("%[^\n]", in);
		int len = strlen(in);
		in[len++] = ' ';
		in[len] = '\0';
		int first = 1;
		int index = 0;
		for (int i = 0; i < len; i++){
			if (in[i] == ' '){
				end[index] = '\0';
				if (first){
					pushAdjStrict(begin, end);
					first = 0;
				}
				pushAdj(begin, end);
				pushAdj(end, begin);
				strcpy(begin, end);
				index = 0;
			} else end[index++] = in[i];
		}
		
	}
//	for (int i = 0; i < SIZE; i++){
//		if (!hashTable[i]) continue;
//		
//		struct station* cur = hashTable[i];
//		while (cur){
//			printf("Station: %s\n", cur->name);
//			printf("Strict: %s\n", cur->strict);
//			printf("adjacent:");
//			struct station* cur2 = cur->adj;
//			while (cur2){
//				printf(" %s", cur2->name);
//				cur2 = cur2->adj;
//			}
//			printf("\n");
//			cur = cur->nextH;
//		}
//		printf("\n");
//		
//	}
	scanf("%s %s", begin, end);
	struct station* ans = bfs(begin, end);
	if (!ans) printf("no route found\n");
	else {
		print(ans, end);
		printf("%s\n", end);
	}
	return 0;
}
