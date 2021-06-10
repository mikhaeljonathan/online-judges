#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 31
#define SIZE 10007

struct data{
	int val;
	char string[50];
	struct data* next;
}*hashTableString[SIZE];

char hashTableInt[3000][50];

int unknown;

int hash(char in[]){
	int len = strlen(in);
	int ret = 0;
	for (int i = 0; i < len; i++){
		ret = ((ret * BASE) + (in[i] - 'a')) % SIZE;
	}
	ret = ret % SIZE;
	return ret;
}

struct data* find(char in[]){
	struct data* cur = hashTableString[hash(in)];
	while (cur != NULL){
		if (!strcmp(cur->string, in)) return cur;
		cur = cur->next;
	}
	return NULL;
}

int getval(char in[]){
	if (find(in)) return find(in)->val;
	unknown = 1;
	return -5000;
}

void pushString(char in[], int val){
	if (find(in)) {
		find(in)->val = val;
	}
	else {
		struct data* newd = (struct data*)malloc(sizeof(struct data));
		strcpy(newd->string, in);
		newd->val = val;
		newd->next = hashTableString[hash(in)];
		hashTableString[hash(in)] = newd;
	}
}

int main (){
	char command[10];
	for (int i = 0; i < SIZE; i++) hashTableString[i] = NULL;
	for (int i = 0; i < 3000; i++) strcpy(hashTableInt[i], "");
	while (scanf("%s", command) != EOF){
		if (!strcmp(command, "def")){
			char in[35];
			scanf("%s", in);
			int val;
			scanf("%d", &val); getchar();
			if (find(in)) {
				strcpy(hashTableInt[find(in)->val + 1000], "");
				find(in)->val = val;
				strcpy(hashTableInt[val + 1000], in);
			}
			else {
				pushString(in, val);
			}
			strcpy(hashTableInt[val + 1000], in);
//			printf("masuk %s %d\n", find(in)->string, find(in)->val);
		} else if (!strcmp(command, "calc")){
			unknown = 0;
			char op = '+';
			char in[35];
			int ans = 0;
			while (op != '='){
				scanf("%s", in);
				getchar();
				if (op == '+') ans += getval(in);
				else if (op == '-') ans -= getval(in);
				scanf("%c", &op);
				printf("%s ", in);
				printf("%c ", op);
			}
//			printf("%d\n", ans);
			if (unknown || !strcmp(hashTableInt[ans + 1000], "")) printf("unknown\n");
			else printf("%s\n", hashTableInt[ans + 1000]);
		} else {
			for (int i = 0; i < SIZE; i++) hashTableString[i] = NULL;
			for (int i = 0; i < 3000; i++) strcpy(hashTableInt[i], "");
		}
	}
	return 0;
}
