#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(int *heap, int idx){
	if (idx == 1) return;
	int paridx = idx / 2;
	if (heap[paridx] > heap[idx]) return;
	swap(&heap[paridx], &heap[idx]);
	upheap(heap, paridx);
}

void push(int *heap, int *n, int nx){
	(*n)++;
	heap[*n] = nx;
	upheap(heap, *n);
}

void downheap(int *heap, int idx, int n){
	int toidx = idx;
	if (2 * idx <= n && heap[toidx] < heap[2 * idx]){
		toidx = 2 * idx;
	}
	if (2 * idx + 1 <= n && heap[toidx] < heap[2 * idx + 1]){
		toidx = 2 * idx + 1;
	}
	if (toidx == idx) return;
	swap(&heap[toidx], &heap[idx]);
	downheap(heap, toidx, n);
}

void extractmax(int *heap, int *n){
	if (*n == 1) {
		(*n)--;
		return;
	}
	
	swap(&heap[1], &heap[*n]);
	
	(*n)--;
	downheap(heap, 1, *n);
}

int top(int *heap){
	return heap[1];
}

void print(int *heap, int n){
	for (int i = 1; i <= n; i++){
		printf("%d ", heap[i]);
	}
	puts("");
}

int main (){
	int t;
	scanf("%d", &t);
	int n = 0;
	int heap[100005];
	while (t--){
		int com;
		scanf("%d", &com);
		if (com == 1){
			int x;
			scanf("%d", &x);
			push(heap, &n, x);
		} else if (com == 2){
			printf("%d\n", top(heap));
		} else {
			extractmax(heap, &n);
		}
//		print(heap, n);
	}
	return 0;
}
