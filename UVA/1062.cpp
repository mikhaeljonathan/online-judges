#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char val;
	struct node* nextElement;
};

struct list{
	struct node* s;
	struct list* nextList;
}*Lists;

int res = 0;

void init(){
	Lists = NULL;
	res = 0;
}

void newList(char x){
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->val = x;
	newn->nextElement = NULL;
	
	struct list* newl = (struct list*)malloc(sizeof(struct list));
	newl->s = newn;
	newl->nextList = Lists;
	Lists = newl;
}

void push(struct list** masukin, char x){
	struct node* newn = (struct node*)malloc(sizeof(struct node));
	newn->val = x;
	newn->nextElement = (*masukin)->s;
	(*masukin)->s = newn;
	
}

int main (){
	int tc = 1;
	char in[1005];
	while (gets(in) && strcmp(in, "end")){
		init();
		int len = strlen(in);
		for (int i = 0; i < len; i++){
			int addStack = 1;
			struct list* cur = Lists;
			int min = -1;
			struct list* masukin = NULL;
			while(cur != NULL){
				if (in[i] <= cur->s->val){
					masukin = cur;
				}
				cur = cur->nextList;
			}
			if (masukin != NULL){
				push(&masukin, in[i]);
				addStack = 0;
			}
			if (addStack){
				newList(in[i]);
				res++;
			}
		}
		
		printf("Case %d: %d\n", tc++, res);
	}
	return 0;
}
