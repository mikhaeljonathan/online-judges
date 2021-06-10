#include <stdio.h>
#include <stdlib.h>
#define BASE 11
#define SIZE 1000003

struct node{
	int val;
	struct node* nextQ;
	struct node* nextH;
	struct node* prevH;
}*hashTable[SIZE], *Qhead, *Qtail;

int qsize;

int hash(int val){
	long long ret = val * 11;
	ret = ret % SIZE; 
	return ret;
}

struct node* newnode(int val){
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->val = val;
	newn->nextQ = NULL;
	newn->nextH = NULL;
	newn->prevH = NULL;
	return newn;
}

struct node* find(int val){
	struct node* cur = hashTable[hash(val)];
	while (cur){
		if (cur->val == val) return cur;
		cur = cur->nextH;
	}
	return NULL;
}

void pushH(int val){
	struct node* newn = newnode(val);
	
	if (!hashTable[hash(val)]) hashTable[hash(val)] = newn;
	return;
	
	newn->nextH = hashTable[hash(val)];
	hashTable[hash(val)]->prevH = newn;
	hashTable[hash(val)] = newn;
	
}

void pushQ(int val){
	struct node* newq = newnode(val);
	
	if (!Qhead){
		Qhead = Qtail = newq;
	} else {
		Qtail->nextQ = newq;
		Qtail = newq;
	}
	
	qsize++;
}

void popH(int val){
	struct node* cur = hashTable[hash(val)];
	while (cur){
		if (cur->val == val){
			if (!(cur->prevH)) {
				struct node* tobedel = hashTable[hash(val)];
				hashTable[hash(val)] = hashTable[hash(val)]->nextH;
				free(tobedel);
			} else if (!(cur->nextH)){
				struct node* tobedel = cur;
				cur = cur->prevH;
				free(tobedel);
			} else {
				cur->prevH->nextH = cur->nextH;
				cur->nextH->prevH = cur->prevH;
				free(cur);
			}
		}
		cur = cur->nextH;
	}
}

void popQ(int val){
	if (!Qhead) return;
	
	while (Qhead->val != val){
		popH(Qhead->val);
		struct node* tobedel = Qhead;
		Qhead = Qhead->nextQ;
		free(tobedel);
		qsize--;
	}
	
	if (Qhead == Qtail){
		free(Qhead);
		Qhead = Qtail = NULL;
	} else {
		struct node* tobedel = Qhead;
		Qhead = Qhead->nextQ;
		free(tobedel);
	}
	qsize--;
	
}

void init(){
	for (int i = 0; i < SIZE; i++) hashTable[i] = NULL;
	qsize = 0;
	Qhead = Qtail = NULL;
}


int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		init();
		int n;
		scanf("%d", &n);
		int max = 0;
		while (n--){
			int val;
			scanf("%d", &val);
			pushQ(val);
			if (find(val)) popQ(val);
			else pushH(val);
//			printf("qsize %d\n", qsize);
			if (qsize > max) max = qsize;
		}
		printf("%d\n", max);
	}
	return 0;
}
