#include <stdio.h>
#include <stdlib.h>
#define SIZE 1005

/*
	command
	1 fill A
	2 fill B
	3 empty A
	4 empty B
	5 pour A B
	6 pur B A
*/

struct State{
	int a;
	int b;
	int com;
	struct State* prevState;
	struct State* nextQ;
	struct State* prevQ;
}*headQ, *tailQ;

int visited[SIZE][SIZE];
int count;

void pushQ(int a, int b, int com, struct State* current){
	
	struct State* newState = (struct State*)malloc(sizeof(struct State));
	newState->a = a;
	newState->b = b;
	newState->com = com;
	newState->prevState = current;
	newState->prevQ = NULL;
	newState->nextQ = NULL;
	
	if (headQ == NULL) headQ = tailQ = newState;
	else {
		tailQ->nextQ = newState;
		newState->prevQ = tailQ;
		tailQ = newState;
	}
	count++;
}

void pop(int fromFreeAll){
	if (headQ == NULL) return;
	
	struct State* toBeDeleted = headQ;
	headQ = headQ->nextQ;
	if (fromFreeAll) free(toBeDeleted);
	
	if (headQ == NULL) tailQ = NULL;
	else headQ->prevQ = NULL;
	
	count--;
}

struct State* bfs(int ca, int cb, int n){
	count = 0;
	pushQ(0, 0, 0, NULL);
	
	for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) visited[i][j] = 0;

	while (1){
		int currentQueueSize = count;
		for (int i = 0; i < currentQueueSize; i++){
			struct State* current = headQ;
			int currentStateA = headQ->a;
			int currentStateB = headQ->b;
			pop(0);
			
			if (currentStateB == n) return current;
			
			if (visited[currentStateA][currentStateB]) continue;
			
			visited[currentStateA][currentStateB] = 1;
			
			if (currentStateA < ca && !visited[ca][currentStateB]) pushQ(ca, currentStateB, 1, current);
			
			if (currentStateB < cb && !visited[currentStateA][cb]) pushQ(currentStateA, cb, 2, current);
			
			if (currentStateA > 0 && !visited[0][currentStateB]) pushQ(0, currentStateB, 3, current);
			
			if (currentStateB > 0 && !visited[currentStateA][0]) pushQ(currentStateA, 0, 4, current);
			
			if (currentStateA > 0 && currentStateB < cb){
				int nextA = currentStateA - (cb - currentStateB);
				nextA = (nextA < 0) ? 0 : nextA;
				
				int nextB = currentStateB + currentStateA;
				nextB = (nextB > cb) ? cb : nextB;
				
				if (!visited[nextA][nextB]) pushQ(nextA, nextB, 5, current);
			
			}
			
			if (currentStateB > 0 && currentStateA < ca){
				int nextB = currentStateB - (ca - currentStateA);
				nextB = (nextB < 0) ? 0 : nextB;
				
				int nextA = currentStateA + currentStateB;
				nextA = (nextA > ca) ? ca : nextA;
				
				if (!visited[nextA][nextB]) pushQ(nextA, nextB, 6, current);
			}
			
		}
	}
	
}

void printSteps(struct State* curr){
	if (curr == NULL) return;
	printSteps(curr->prevState);
	if (curr->com == 1) puts("fill A");
	if (curr->com == 2) puts("fill B");
	if (curr->com == 3) puts("empty A");
	if (curr->com == 4) puts("empty B");
	if (curr->com == 5) puts("pour A B");
	if (curr->com == 6) puts("pour B A");
}

void freeAll(){
	while (headQ != NULL) pop(1);
}

int main (){
	int ca, cb, n;
	while(scanf("%d %d %d", &ca, &cb, &n) != EOF){
		struct State* res = bfs(ca, cb, n);
		printSteps(res);
		puts("success");
		freeAll();
	}
	return 0;
}
