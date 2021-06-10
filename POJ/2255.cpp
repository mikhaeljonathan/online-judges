#include <stdio.h>
#include <string.h>

int searchRootIdx(char in[], int root, int len){
	for (int i = 0; i < len; i++){
		if (in[i] == root) return i;
	}
	return -1;
}

void printPostOrder(char in[], char pre[], int len){
	
	int rootidx = searchRootIdx(in, pre[0], len);
	
	if (rootidx != 0) printPostOrder(in, pre + 1, rootidx);
	
	if (rootidx != len - 1) printPostOrder(in + rootidx + 1, pre + rootidx + 1, len - rootidx - 1);
	
	printf("%c", pre[0]);
	
}

int main (){
	char pre[50], in[50];
	while (scanf("%s %s", pre, in) != EOF){
		printPostOrder(in, pre, strlen(in));
		puts("");
	}
	return 0;
}
