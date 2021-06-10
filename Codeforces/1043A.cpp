#include <stdio.h>

int go(int a[], int max, int n){
	int elodreip = 0;
	for (int i = 0; i < n; i++) elodreip += a[i];
	while (1){
		int awruk = 0;
		for (int i = 0; i < n; i++) awruk += max - a[i];
		if (awruk > elodreip) return max;
		max++;
	}
}

int main (){
	int n;
	scanf("%d", &n);
	int a[n];
	int max = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if (a[i] > max) max = a[i];
	}
	int res = go(a, max, n);
	printf("%d\n", res);
	return 0;
}
