#include <stdio.h>
#include <string.h>

typedef struct{
	char x[100];
	int bub;
}DNA;

void swapdna(DNA *a, DNA *b){
	DNA temp = *a;
	*a = *b;
	*b = temp;
}

int bubble (char x[]){
	int len = strlen(x);
	int res = 0;
	for (int i = 0; i < len; i++){
		for (int j = i + 1; j < len; j++){
			if (x[j] < x[i]) res++;
		}
	}
	return res;
}

int main (){
	int M;
	scanf("%d", &M);
	while (M--){
		getchar();
		int n, m;
		scanf("%d %d", &n, &m);
		getchar();
		DNA dna[m];
		for (int i = 0; i < m; i++) gets(dna[i].x); 
		for (int i = 0; i < m; i++) dna[i].bub = bubble(dna[i].x);
		for (int i = 0; i < m - 1; i++)
			for (int j = 0; j < m - i - 1; j++)
				if (dna[j].bub > dna[j + 1].bub) swapdna(&dna[j], &dna[j + 1]);
		for (int i = 0; i < m; i++) puts(dna[i].x);
		if (M != 0) puts("");
	}
	return 0;
}
