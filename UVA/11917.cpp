#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 31
#define SIZE 503

struct node{
	char name[25];
	int val;
	struct node* nextH;
}*hashTable[SIZE];

int hash(char in[]){
	int len = strlen(in);
	int ret = 0;
	for (int i = 0; i < len; i++) ret = ((ret * BASE) + in[i] - 'a' + 1) % SIZE;
	ret %= SIZE;
	return ret;
}

void pushH(char in[], int val){
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	strcpy(newn->name, in);
	newn->val = val;
	newn->nextH = hashTable[hash(in)];
	hashTable[hash(in)] = newn;
}

struct node* find(char in[]){
	struct node* cur = hashTable[hash(in)];
	while (cur){
		if (!strcmp(cur->name, in)) return cur;
		cur = cur->nextH;
	}
	return NULL;
}

int main (){
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++){
		for (int i = 0; i < SIZE; i++) hashTable[i] = NULL;
		int n;
		scanf("%d", &n); getchar();
		while (n--){
			char in[25];
			int val;
			scanf("%s %d", in, &val); getchar();
			pushH(in, val);
		}
		int d;
		scanf("%d", &d); getchar();
		char in[25];
		scanf("%s", in);
		int yes, late, doyour;
		yes = late = doyour = 0;
		
		if (!find(in)) doyour = 1;
		else {
			if (find(in)->val <= d) yes = 1;
			else if (find(in)->val <= d + 5) late = 1;
			else doyour = 1;
		}
		printf("Case %d: ", tc);
		if (yes) puts("Yesss");
		if (late) puts("Late");
		if (doyour) puts("Do your own homework!");
	}
	return 0;
}
