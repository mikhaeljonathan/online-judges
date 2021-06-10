#include <stdio.h>
#include <stdlib.h>
#define SIZE 53
#define BASE 47

struct Node{
	long long x;
	long long indexAdjacent;
	long long adjacent[50];
	long long visited;
	struct Node* nextH;
}*hashTable[SIZE];

struct Queue{
	long long x;
	struct Queue* nextQ;
};

struct Queue* headQ;
struct Queue* tailQ;
int count = 0;
 
void init(){
	for (long long i = 0; i < SIZE; i++) hashTable[i] = NULL;
}

long long hash_(long long x){
	return (x * BASE) % SIZE;
}

struct Node* makeNode(long long x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->x = x;
	newNode->indexAdjacent = 0;
	newNode->visited = 0;
	newNode->nextH = NULL;
	
	return newNode;
}

struct Node* find(long long x){
	struct Node* curr = hashTable[hash_(x)];
	while (curr != NULL){
		if (curr->x == x) return curr;
		curr = curr->nextH;
	}
	return NULL;
}

void pushHash(long long a, long long b){
	
	if (find(a) == NULL) {
		struct Node* newNode = makeNode(a);
		if (hashTable[hash_(a)] != NULL) newNode->nextH = hashTable[hash_(a)];
		hashTable[hash_(a)] = newNode;
		newNode->adjacent[newNode->indexAdjacent++] = b;
	} else {
		find(a)->adjacent[find(a)->indexAdjacent++] = b;
	}
	
	if (find(b) == NULL){
		struct Node* newNode = makeNode(b);
		if (hashTable[hash_(b)] != NULL) newNode->nextH = hashTable[hash_(b)];
		hashTable[hash_(b)] = newNode;
		newNode->adjacent[newNode->indexAdjacent++] = a;
	} else {
		find(b)->adjacent[find(b)->indexAdjacent++] = a;
	}
	
}

void pushQ(long long x){
	struct Queue* newQueue = (struct Queue*) malloc (sizeof(struct Queue));
	newQueue->x = x;
	newQueue->nextQ = NULL;
	if (headQ == NULL) headQ = tailQ = newQueue;
	else {
		tailQ->nextQ = newQueue;
		tailQ = newQueue;
	}
	count++;
}

void popQ(){
	if (headQ == NULL) return;
	
	struct Queue* toBeDeleted = headQ;
	
	headQ = headQ->nextQ;
	free(toBeDeleted);
	
	if (headQ == NULL) tailQ = NULL;
	
	count--;
}

void bfs(long long a, long long b){
	if (b == 0) {
		if (find(a) != NULL) find(a)->visited = 1;
		return;
	}
	
	pushQ(a);
	while (b >= 0) {
		
		long long currentQueueSize = count;
		for (long long i = 0; i < currentQueueSize; i++){

			long long currentX = headQ->x;
			popQ();
			
			if (find(currentX)->visited) continue;
			
			find(currentX)->visited = 1;
			
			for (long long j = 0; j < find(currentX)->indexAdjacent; j++){
				
				if (find(find(currentX)->adjacent[j])->visited) continue;
				
//				printf("%lld %lld %lld\n", currentX, find(currentX)->adjacent[j], b);
				pushQ(find(currentX)->adjacent[j]);
				
			}
		}
		b--;
	}
}

long long howManyNodes(long long a, long long b){
	if (find(a) != NULL) bfs(a, b);

	long long res = 0;
	
	for (long long i = 0; i < SIZE; i++) if (hashTable[i] != NULL && !hashTable[i]->visited) res++;
	
	for (long long i = 0; i < SIZE; i++){
		if (hashTable[i] != NULL){
			struct Node* curr = hashTable[i];
			while (curr != NULL){
				hashTable[i]->visited = 0;
				curr = curr->nextH;
			}
		}
	}
	
	while (headQ != NULL) popQ();
	
	return res;
	
}

void freeHash(){
	for (long long i = 0; i < SIZE; i++) if (hashTable[i] != NULL) free(hashTable[i]);
}

int main (){
	long long nc;
	long long cases = 1;
	while (scanf("%lld", &nc) && nc != 0){
		init();
		while (nc--){
			long long a, b;
			scanf("%lld %lld", &a, &b);
			pushHash(a, b);
		}

//		for (long long i = 0; i < SIZE; i++){
//			if (hashTable[i] != NULL){
//				printf("[%2d]: ", i);
//				printf("%lld ", hashTable[i]->x);
//				printf("adjacent ");
//				for (long long j = 0; j < hashTable[i]->indexAdjacent; j++){
//					printf("%lld ", hashTable[i]->adjacent[j]);
//				}
//				puts("");
//			}
//		}
		
		long long c, d;
		while (scanf("%lld %lld", &c, &d) && (c != 0 || d != 0)) {
			printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n", cases++, howManyNodes(c, d), c, d);
		}
		
		freeHash();
	}
	return 0;
}
