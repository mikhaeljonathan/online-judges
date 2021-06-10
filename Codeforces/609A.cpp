#include <stdio.h>

int doit(int size[], int n, int m){
	int total = 0;
	for (int i = 0; i < n; i++){
		total += size[i];
		if (total >= m) return i;
	}
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int size[n];
	for (int i = 0; i < n; i++) scanf("%d", &size[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (size[j] < size[j + 1]) swap(size[j], size[j + 1]);
	int res = doit(size, n, m);
	printf("%d\n", res + 1);
	return 0;
}
