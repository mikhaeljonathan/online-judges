#include <stdio.h>

typedef struct{
	int x;
	int y;
}enemy;

void swap(enemy *a, enemy *b){
	enemy temp = *a;
	*a = *b;
	*b = temp;
}

bool test(enemy dragon[], int n, int s){
	for (int i = 0; i < n; i++){
		if (s > dragon[i].x) s += dragon[i].y;
		else return false;
	}
	return true;
}

int main (){
	int s, n;
	scanf("%d %d", &s, &n);
	enemy dragon[n];
	for (int i = 0; i < n; i++) scanf("%d %d", &dragon[i].x, &dragon[i].y);
	//bubble sort
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (dragon[j].x > dragon[j + 1].x) swap(&dragon[j], &dragon[j + 1]);
	printf("%s\n", (test(dragon, n, s)) ? "YES" : "NO");
	return 0;
}
