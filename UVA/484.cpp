#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000003
#define BASE 999983

struct Node{
	long long num;
	long long quantity;
	struct Node* nextQ;
	struct Node* nextH;
	struct Node* prevQ;
};

struct Node* hashTable[SIZE];
struct Node* front;
struct Node* back;

int abs(int x){
	return (x < 0) ? -x : x;
}

int hash(long long x){
	return abs((x * BASE) % SIZE);
}

int isFound(long long x){
	struct Node* curr = hashTable[hash(x)];
	while (curr != NULL){
		if (curr->num == x) return 1;
		curr = curr->nextH;
	}
	return 0;
}

void push(long long x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->num = x;
	newNode->quantity = 1;
	newNode->nextQ = NULL;
	newNode->nextH = NULL;
	newNode->prevQ = NULL;
	
	if (back == NULL){
		front = back = newNode;
	} else {
		newNode->nextQ = back;
		back->prevQ = newNode;
		back = newNode;
	}
	
	if (hashTable[hash(x)] != NULL) newNode->nextH = hashTable[hash(x)];
	hashTable[hash(x)] = newNode;
	
}

struct Node* find(long long x){
	struct Node* curr = hashTable[hash(x)];
	while (curr != NULL){
		if (curr->num == x) return curr;
		curr = curr->nextH;
	}
	return NULL;
}

int main (){
	long long x;
	while (scanf("%lld", &x) != EOF){
		if (!isFound(x)) push(x);
		else {
			struct Node* temp = find(x);
			temp->quantity++;
		}
	}
	struct Node* curr = front;
	while (curr != NULL){
		printf("%lld %lld\n", curr->num, curr->quantity);
		curr = curr->prevQ;
	}
	return 0;
}
