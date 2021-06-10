#include <stdio.h>

int avl;
int arr[1000];

int abs(int x){
	return (x < 0) ? -x : x;
}

int max(int a, int b){
	return (a < b) ? b : a;
}

int height(int val, int index){
	if (val == -1) return 0;
	
	int height1 = height(arr[index*2+1], index*2+1);
	int height2 = height(arr[index*2+2], index*2+2);
	if (abs(height1 - height2) > 1) avl = 0;
	return max(height1, height2) + 1;
}


int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 1000; i++) arr[i]= -1;
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		avl = 1;
		if (n != 0) height(arr[0], 0);
		if (!avl) printf("F\n");
		else printf("T\n");
	}
	return 0;
}
