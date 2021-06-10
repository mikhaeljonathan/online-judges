#include <stdio.h>

int heapleft[100005];
int heapright[100005];
int leftchild;
int rightchild;
int median;
int in;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int abs(int x){
	return (x < 0) ? -x : x;
}

void downheap(int idx, int left){
	int toidx = idx;
	
	if (left){
		if (2 * idx <= leftchild && heapleft[2 * idx] > heapleft[toidx]) 
			toidx = 2 * idx;
		if (2 * idx + 1 <= leftchild && heapleft[2 * idx + 1] > heapleft[toidx]) 
			toidx = 2 * idx + 1;
		if (toidx == idx) return;
		
		swap(&heapleft[idx], &heapleft[toidx]);
		
		downheap(toidx, left);
	} else {
		if (2 * idx <= rightchild && heapright[2 * idx] < heapright[toidx]) 
			toidx = 2 * idx;
		if (2 * idx + 1 <= rightchild && heapright[2 * idx + 1] < heapright[toidx]) 
			toidx = 2 * idx + 1;
		if (toidx == idx) return;
		
		swap(&heapright[idx], &heapright[toidx]);
		
		downheap(toidx, left);
	}
}

void deletetop(int left){
	if (left){
		if (leftchild == 1){
			leftchild--;
			return;
		}
		heapleft[1] = heapleft[leftchild];
		leftchild--;
		downheap(1, left);
	} else {
		if (rightchild == 1){
			rightchild--;
			return;
		}
		heapright[1] = heapright[rightchild];
		rightchild--;
		downheap(1, left);
	}
}

void upheap(int idx, int left){
	if (idx == 1) return;
	
	int parentidx = idx / 2;
	if (left) {
		if (heapleft[parentidx] > heapleft[idx]) return;
		swap(&heapleft[parentidx], &heapleft[idx]);
		upheap(parentidx, left);
	} else {
		if (heapright[parentidx] < heapright[idx]) return;
		swap(&heapright[parentidx], &heapright[idx]);
		upheap(parentidx, left);
	}
}

void push(int in, int left){
	if (left){
		leftchild++;
		heapleft[leftchild] = in;
		upheap(leftchild, 1);
	} else {
		rightchild++;
		heapright[rightchild] = in;
		upheap(rightchild, 0);
	}
}

void balanceandupdatemedian(){
	if (abs(leftchild - rightchild) > 1){
		int left = 0;
		if (leftchild > rightchild) left = 1;
		if (left){
			push(heapleft[1], 0);
			deletetop(1);
		} else {
			push(heapright[1], 1);
			deletetop(0);
		}
	}
	median = (leftchild >= rightchild) ? heapleft[1] : heapright[1];
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		//init
		leftchild = rightchild = 0;
		median = 1<<30;
		
		//execution
		while (scanf("%d", &in) && in != 0){
			if (in == -1){
				printf("%d\n", median);
				if (leftchild >= rightchild) deletetop(1);
				else deletetop(0);
			} else {
				if (in <= median) push(in, 1);
				else push(in, 0);
			}
			balanceandupdatemedian();
		}
		
	}
	return 0;
}
