#include <stdio.h>
#include <stdlib.h>
#define SIZE 2503

struct combination{
	int num[500];
	int total;
	struct combination* next;
};

struct combination* hashTable[SIZE];

void freeall(){
	for (int i = 0; i < SIZE; i++) hashTable[i] = NULL;
}

int hash(int a, int b, int c, int d, int e){
	return a+b+c+d+e;
}

int same(struct combination* cur, int a, int b, int c, int d, int e){
	if (cur->num[a] && cur->num[b] && cur->num[c] && cur->num[d] && cur->num[e]) return 1;
	return 0;
}

struct combination* find(int a, int b, int c, int d, int e){
	struct combination* cur = hashTable[hash(a,b,c,d,e)];
	while (cur != NULL){
		if (same(cur, a, b, c, d, e)) return cur;
		cur = cur->next;
	}
	return cur;
}

void push(int a, int b, int c, int d, int e){
	struct combination* newc = (struct combination*)malloc(sizeof(struct combination));
	newc->total = 1;
	for (int i = 0; i < 500; i++) newc->num[i] = 0;
	newc->num[a] = 1;
	newc->num[b] = 1;
	newc->num[c] = 1;
	newc->num[d] = 1;
	newc->num[e] = 1;
	newc->next = hashTable[hash(a,b,c,d,e)];
	hashTable[hash(a,b,c,d,e)] = newc;
}

int main (){
	int n;
	while (scanf("%d", &n) && n != 0){
		freeall();
		while (n--){
			int a, b, c, d, e;
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			if (find(a, b, c, d, e) != NULL) (find(a,b,c,d,e)->total)++;
			else push(a,b,c,d,e);
		}
		int max = 0;
		for (int i = 0; i < SIZE; i++){
			struct combination* cur = hashTable[i];
			while (cur != NULL){
				if (cur->total > max) max = cur->total;
				cur = cur->next;
			}
		}
//		printf("max %d\n", max);
		int res = 0;
		for (int i = 0; i < SIZE; i++){
			struct combination* cur = hashTable[i];
			while (cur != NULL){
				if (cur->total == max) res += cur->total;
				cur = cur->next;
			}
		}
//		for (int i = 0; i < SIZE; i++){
//			struct combination* cur = hashTable[i];
//			while (cur != NULL){
//				for (int i = 0; i < 500; i++){
//					if (cur->num[i] != 0) printf("%d ", i);
//				}
//				printf("total %d\n", cur->total);
//				cur = cur->next;
//			}
//		}
		printf("%d\n", res);
	}
	return 0;
}
