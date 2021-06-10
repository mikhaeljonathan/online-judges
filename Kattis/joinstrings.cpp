#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000005];

struct Node{
	char data;
	struct Node* next;
};

struct List{
	struct Node* head;
	struct Node* tail;
};

void insert (struct List* list, char x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	if (list->head == NULL){
		newNode->next = NULL;
		list->head = newNode;
		list->tail = newNode;
	} else {
		newNode->next = NULL;
		list->tail->next = newNode;
		list->tail = newNode;
	}
}

void print(struct List list){
	struct Node* curr = list.head;
	while (curr != NULL){
		printf("%c", curr->data);
		curr = curr->next;
	}
	puts("");
}

int main (){
	int n;
	scanf("%d", &n);
	int temp = n;
	getchar();
	struct List lists[n];
	for (int i = 0; i < n; i++){
		lists[i].head = NULL;
		lists[i].tail = NULL;
	}
	for (int i = 0; i < n; i++){
		scanf("%s", s);
		getchar();
		int len = strlen(s);
		for (int j = 0; j < len; j++) insert(&lists[i], s[j]);
	}
	n--;
	int res = -1;
	while (n--){
		int a, b;
		scanf("%d %d", &a, &b);
		lists[a - 1].tail->next = lists[b - 1].head;
		lists[a - 1].tail = lists[b - 1].tail;
		res = a - 1;
	}
	if (temp == 1) print(lists[0]);
	else print(lists[res]);
	return 0;
}
