#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tnode {
	int hash;
	struct tnode *next;
	
};

const int maxhashtable = 50000;
const int curmod = 49811;
const int curbase = 137;

struct tnode *listHead[maxhashtable];
struct tnode *listTail[maxhashtable];
int listCount[maxhashtable];

// resolve collision
char hashOwner[maxhashtable][50];
int isHashExist[maxhashtable];

// bfs
int visited[maxhashtable];
int ans[maxhashtable];


void push(struct tnode **localHead, struct tnode **localTail,
				int *count, int hash) {
	struct tnode *nowNode = (struct tnode*)malloc(sizeof(
										struct tnode));
	nowNode->hash = hash;
	nowNode->next = NULL;
	
	if (*localHead == NULL) {
		*localHead = *localTail = nowNode;
	} else {
		(*localTail)->next = nowNode;
		*localTail = nowNode;
	}
	(*count)++;
}

void pop(struct tnode **localHead, struct tnode **localTail,
				int *count) {
	if (*localHead == NULL) return;
	if (*localHead == *localTail) {
		free(*localHead);
		*localHead = *localTail = NULL;
	} else {
		struct tnode *del = *localHead;
		*localHead = (*localHead)->next;
		free(del);
	}
	(*count)--;
}

void freeAll(struct tnode **localHead, struct tnode **localTail,
					int *count) {
	while(*localHead != NULL) {
		pop(localHead, localTail, count);
	}
}


int hash(const char *str, int base, int mod) {
	int ret = 0;
	int len = strlen(str);
	for(int i=0; i<len; i++) {
		ret = (ret * base) + str[i];
		ret = ret % mod;
	}
	return ret;
}

int getHash(const char *str) {
	/*
	if (curAuth.count(str) > 0) {
		return curAuth[str];
	} else {
		curAuth[str] = currentAuth++;
		return currentAuth-1;
	}
	*/
	
	int curhash = hash(str, curbase, curmod);
	if (isHashExist[curhash] == 0) {
		isHashExist[curhash] = 1;
		strcpy(hashOwner[curhash], str);
	} else {
		if (strcmp(hashOwner[curhash], str) == 0) return curhash;

		for(int i=curhash; i+1 != curhash; i = (i+1)%curmod) {
			if (isHashExist[i] == 0) {
				isHashExist[i] = 1;
				strcpy(hashOwner[i], str);
				return i;
			} else {
				if (strcmp(hashOwner[i], str) == 0) {
					return i;
				}
			}
		}
	}
	return curhash;
}



void bfs(const char *wordA) {
	
	for(int i=0; i<maxhashtable; i++) {
		visited[i] = 0;
	}
	int hashA = getHash(wordA);

	struct tnode *qhead = NULL;
	struct tnode *qtail = NULL;
	int qcount = 0;
	
	push(&qhead, &qtail, &qcount, hashA);
	visited[hashA] = 1;
	for(int moves=0; qcount > 0; moves++) {
		int currentQcount = qcount;
		for(int __=0; __<currentQcount; __++) {
			
			int currentHash = qhead->hash;
			pop(&qhead, &qtail, &qcount);
			
			
			ans[currentHash] = moves;

			if (visited[currentHash] == 2) continue;
			visited[currentHash] = 2;
			
			struct tnode *current = listHead[currentHash];
			while(current != NULL) {
				
				int nextHash = current->hash;
				if (!visited[nextHash]) {
					push(&qhead, &qtail, &qcount, nextHash);
					visited[nextHash] = 1;
				}
				current = current->next;
			}
			
		}
	}
}

int main() {
	
	
	int p, n;
	int tc = 1;
	while(scanf("%d %d", &p, &n) != EOF) {
		getchar();
		if (p == 0 && n == 0) break;
		
		for(int i=0; i<maxhashtable; i++) {
			listHead[i] = listTail[i] = NULL;
			listCount[i] = 0;
			isHashExist[i] = 0;
			strcpy(hashOwner[i], "");
		}
		
		char line[300];
		for(int __=0; __<p; __++) {
			scanf("%[^\n]", line);
			getchar();
			int len = strlen(line);

			char authors[300][45];
			int idxAuthors = 0;
			int authorsLen = 0;
			int count = 0;
			for(int i=0; i<len; i++) {
				if (line[i] == ':') { // this is the last author
					authors[idxAuthors][authorsLen] = '\0';
					idxAuthors++;
					//printf(" last : %c\n", line[i]);
					break;
				} else if (line[i] == ',' && count == 0) {
					authors[idxAuthors][authorsLen] = line[i];
					authorsLen++;
					count = (count + 1) % 2;
					//printf(" haha : %c\n", line[i]);
				} else if (line[i] == ',' && count == 1) {
					authors[idxAuthors][authorsLen] = '\0';
					idxAuthors++;
					i++;
					count = (count + 1) % 2;
					authorsLen = 0;
					//printf(" huwe : %c\n", line[i]);
				} else {
					authors[idxAuthors][authorsLen] = line[i];
					authorsLen++;
					//printf(" disini : %c\n", line[i]);
				}
			}
			for(int i=0; i<idxAuthors; i++) {
				for(int k=i+1; k<idxAuthors; k++) {
					int auth1 = getHash(authors[i]);
					int auth2 = getHash(authors[k]);
					
					push(&listHead[auth1], &listTail[auth1], &listCount[auth1], auth2);
					push(&listHead[auth2], &listTail[auth2], &listCount[auth2], auth1);
				}
			}
		}
		printf("Database #%d\n", tc++);
		for(int i=0; i<maxhashtable; i++) ans[i] = -1;
		bfs("Erdos, P.");
		for(int __=0; __<n; __++) {

			scanf("%[^\n]", line);
			getchar();
			
			int auth2 = getHash(line);

			int moves = ans[auth2];
			printf("%s: ", line);
			if (moves == -1) puts("infinity");
			else printf("%d\n", moves);
		}
		puts("");
		
		
		for(int i=0; i<maxhashtable; i++) freeAll(&listHead[i], &listTail[i], &listCount[i]);
		
	}
	return 0;
}
