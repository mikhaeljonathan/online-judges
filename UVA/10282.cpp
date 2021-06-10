#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BASE 31
#define SIZE 200003

struct word{
	char eng[15];
	char fore[15];
	struct word* next;
}*hashTable[SIZE];

int hash (char in[]){
	int len = strlen(in);
	int ret = 0;
	for (int i = 0; i < len ;i++){
		int temp = in[i] - 'a';
		ret = ((ret * BASE) + temp) % SIZE;
	}
	ret %= SIZE;
	return ret;
}

void push(char a[], char b[]){
	struct word* neww = (struct word*)malloc(sizeof(struct word));
	strcpy(neww->eng, a);
	strcpy(neww->fore, b);
	neww->next = hashTable[hash(b)];
	hashTable[hash(b)] = neww;
}

struct word* find(char in[]){
	struct word* cur = hashTable[hash(in)];
	while (cur != NULL){
		if (!strcmp(cur->fore, in)) return cur;
		cur = cur->next;
	}
	return NULL;
}

int main (){
	char init[30];
	while (gets(init) && strcmp(init, "")){
		char eng[15];
		char fore[15];
		sscanf(init, "%s %s", eng, fore);
		push(eng, fore);
	}
	char in[15];
	while (gets(in)){
		if (find(in)) printf("%s\n", find(in)->eng);
		else puts("eh");
	}
	return 0;
}
