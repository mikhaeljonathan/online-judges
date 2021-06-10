#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}*stack, *queueBack, *queueFront, *priorityBack, *priorityFront;

void PushStack(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = stack;
	stack = newNode;
}

void PushQueue(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = queueBack;
	if (queueBack == NULL) queueFront = newNode;
	else newNode->next->prev = newNode;
	queueBack = newNode;
}

void PushPriority(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	if (priorityBack == NULL) {
		priorityFront = newNode;
		priorityBack = newNode;
		return;
	} else {
		if (priorityBack->data >= x) {
			newNode->next = priorityBack;
			newNode->next->prev = newNode;
			priorityBack = newNode;
			return;
		}
		
		struct Node* curr = priorityBack;
		while (curr->next != NULL && curr->next->data < x) curr = curr->next;
				
		if (curr->next == NULL){
			curr->next = newNode;
			newNode->prev = curr;
			priorityFront = newNode;
			return;
		}
		
		newNode->next = curr->next;
		newNode->next->prev = newNode;
		newNode->prev = curr;
		curr->next = newNode;
		
	}
	
}

int PopStack(){
	if (stack == NULL) return -1;
	else {
		struct Node* toBeDeleted = stack;
		int res = stack->data;
		stack = stack->next;
		free(toBeDeleted);
		return res;
	}
}

int PopQueue(){
	if (queueFront == NULL) return -1;
	else {
		struct Node* toBeDeleted = queueFront;
		int res = queueFront->data;
		queueFront = queueFront->prev;
		if (queueFront != NULL) queueFront->next = NULL;
		else queueBack = NULL;
		free(toBeDeleted);
		return res;
	}
}

int PopPriority(){
	if (priorityFront == NULL) return -1;
	else {
		struct Node* toBeDeleted = priorityFront;
		int res = priorityFront->data;
		priorityFront = priorityFront->prev;
		if (priorityFront != NULL) priorityFront->next = NULL;
		else priorityBack = NULL;
		free(toBeDeleted);
		return res;
	}
}

void FreeAllStack(){
	while (stack != NULL) PopStack();
}

void FreeAllQueue(){
	while (queueFront != NULL) PopQueue();
}

void FreeAllPriority(){
	while (priorityFront != NULL) PopPriority();
}

int main (){
	int n;
	while (scanf("%d", &n) != EOF){
	
		bool isStack, isQueue, isPriority;
		isStack = isQueue = isPriority = true;
		while (n--){
			int com, x;
			scanf("%d %d", &com, &x);
			if (com == 1){
				PushStack(x);
				PushQueue(x);
				PushPriority(x);
			} else {
				if (PopStack() != x) isStack = false;
				if (PopQueue() != x) isQueue = false;
				if (PopPriority() != x) isPriority = false;
			}
		}
		int res = 0;
		if (isStack) res++;
		if (isQueue) res++;
		if (isPriority) res++;
		if (res > 1){
			puts("not sure");
		} else if(res == 1){
			if (isStack) puts("stack");
			if (isQueue) puts("queue");
			if (isPriority) puts("priority queue");
		} else {
			puts("impossible");
		}
		
		FreeAllStack();
		FreeAllQueue();
		FreeAllPriority();
	}
	return 0;
}
