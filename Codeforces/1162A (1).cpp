#include <stdio.h>

typedef struct{
	int l;
	int r;
	int x;
}Restriction;

void swap(Restriction &a, Restriction &b){
	Restriction temp = a;
	a = b;
	b = temp;
}

int main (){
	int n, h, m;
	scanf("%d %d %d", &n, &h, &m);
	int height[n];
	for (int i = 0; i < n; i++) height[i] = h;
	Restriction restrictions[m];
	for (int i = 0; i < m; i++) scanf("%d %d %d", &restrictions[i].l, &restrictions[i].r, &restrictions[i].x);
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - 1 - i; j++)
			if (restrictions[j].x < restrictions[j + 1].x) swap(restrictions[j], restrictions[j + 1]);
	for (int i = 0; i < m; i++)
		for (int j = restrictions[i].l - 1; j <= restrictions[i].r - 1; j++)
			height[j] = restrictions[i].x;
	long long total = 0;
	for (int i = 0; i < n; i++) total += height[i] * height[i];
	printf("%lld\n", total);
	return 0;
}
