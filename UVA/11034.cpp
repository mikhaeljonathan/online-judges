#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode{
	int x;
	struct tnode* next;
};

void push(struct tnode** h, struct tnode** t, int x){
	struct tnode* newn = (struct tnode*)malloc(sizeof(struct tnode));
	newn->x = x;
	newn->next = NULL;
	
	if (!(*h)){
		*h = *t = newn;
	} else {
		(*t)->next = newn;
		(*t) = newn;
	}
}

void pop(struct tnode** h, struct tnode** t){
	if (!(*h)) return;
	
	if (*h == *t){
		*h = *t = NULL;
		return;
	}
	
	struct tnode* tobedeleted = *h;
	(*h) = (*h)->next;
	free(tobedeleted);
}

int empty(struct tnode** h){
	return !(*h);
}

int front(struct tnode** h){
	return (*h)->x;
}

void freeall(struct tnode** h, struct tnode** t){
	while (*h) pop(h, t);
}

int main (){
	int c;
	scanf("%d", &c);
	while (c--){
		struct tnode *lh, *lt, *rh, *rt;
		lh = lt = rh = rt = NULL;
		int l, m;
		scanf("%d %d", &l, &m);
		while (m--){
			int x;
			char where[6];
			scanf("%d %s", &x, where);
			if (!strcmp(where, "left")) push(&lh, &lt, x);
			else push(&rh, &rt, x);
		}
		l *= 100;
		int res = 0;
		int left = 1;
		while (!empty(&lh) || !empty(&rh)){
			int capacity = 0;
			
			while (left ? !empty(&lh) : !empty(&rh)){
				if (left) capacity += front(&lh);
				else capacity += front(&rh);
				
				if (capacity > l) break;
				
				left ? pop(&lh, &lt) : pop(&rh, &rt);
			}
			if (left) left = 0;
			else left = 1;
			res++;
		}
		printf("%d\n", res);
		freeall(&lh, &lt);
		freeall(&rh, &rt);
	}
	return 0;
}
