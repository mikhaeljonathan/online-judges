#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#define SIZE 10007

struct Species{
	char name[25];
	struct Species* child;
	struct Species* parent;
	struct Species* next;
}*hashtable[SIZE];

int hash(char x[]){
	int len = strlen(x);
	int res = 0;
	for (int i = 0; i < len; i++) res = ((res * 31) + x[i] - 'a' + 1) % SIZE;
	return (res * 31) % SIZE;
}

struct Species* find(char x[]){
	if (hashtable[hash(x)] == NULL) return NULL;
	else {
		struct Species* curr = hashtable[hash(x)];
		while (curr != NULL){
			if (!strcmp(curr->name, x)) return curr;
			curr = curr->next;
		}
	}
	return NULL;
}

void pushhash(char x[]){
	struct Species* newHash = (struct Species*)malloc(sizeof(struct Species));
	strcpy(newHash->name, x);
	newHash->child = NULL;
	newHash->parent = NULL;
	newHash->next = hashtable[hash(x)];
	hashtable[hash(x)] = newHash;
}

void push(char parent[], char child[]){
	if (find(parent) == NULL) pushhash(parent);
	if (find(child) == NULL) pushhash(child);
	
	struct Species* newChild = (struct Species*)malloc(sizeof(struct Species));
	strcpy(newChild->name, child);
	newChild->next = find(parent)->child;
	find(parent)->child = newChild;
	find(child)->parent = find(parent);
}

void print(struct Species* parent, struct Species* child){
	if (child == NULL || child == parent->parent) return;
	print(parent, child->parent);
	printf("%s\n", child->name);
}

int possible(char parent[], char child[]){
	std::stack<struct Species*> st;
	
	st.push(find(parent));
	
	while (!st.empty()){
		int currsize = st.size();
		for (int i = 0; i < currsize; i++){
			struct Species* curr = st.top();
			st.pop();
			
			for (struct Species* currchild = curr->child; currchild != NULL; currchild = currchild->next){
				if (!strcmp(child, currchild->name)){
					print(find(parent), find(child));
					return 1;
				}
				st.push(find(currchild->name));
			}
			
		}
	}
	return 0;
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n); getchar();
	while (n--){
		char parent[25], child[25];
		scanf("%s %s", parent, child);
		push(parent, child);
	}
	
	char begin[25], end[25];
	scanf("%s %s", begin, end);
	
	if (!possible(begin, end) && !possible(end, begin)) puts("TIDAK MUNGKIN");
	
	
//	for (int i = 0; i < SIZE; i++){
//		if (hashtable[i] == NULL)continue;
//		printf("%s ", hashtable[i]->name);
//		struct Species* curr = hashtable[i]->child;
//		while (curr != NULL){
//			printf("% s ", curr->name);
//			curr = curr->next;
//		}
//		puts("");
//	}
//	
//	puts("");
//	
//	for (int i = 0; i < SIZE; i++){
//		if (hashtable[i] == NULL)continue;
//		printf("%s ", hashtable[i]->name);
//		if (hashtable[i]->parent != NULL) printf("%s", hashtable[i]->parent->name);
//		puts("");
//	}

}
