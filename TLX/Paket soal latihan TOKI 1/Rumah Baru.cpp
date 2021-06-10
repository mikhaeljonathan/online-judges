#include <stdio.h>

bool old[205][205];

bool newable(int x, int y){
	
	bool syarat1 = false;
	for (int i = x + 1; i < 205; i++){
		if (old[i][y]){
			syarat1 = true;
			break;
		}
	}
	
	bool syarat2 = false;
	for (int i = x - 1; i >= 0; i--){
		if (old[i][y]){
			syarat2 = true;
			break;
		}
	}
	
	bool syarat3 = false;
	for (int i = y + 1; i < 205; i++){
		if (old[x][i]){
			syarat3 = true;
			break;
		}
	}
	
	bool syarat4 = false;
	for (int i = y - 1; i >= 0; i--){
		if (old[x][i]){
			syarat4 = true;
			break;
		}
	}
	
	return (syarat1 && syarat2 && syarat3 && syarat4);
}

int main (){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 205; i++) for (int j = 0; j < 205; j++) old[i][j] = false;
	int x[n];
	int y[n];
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 0; i < n; i++) scanf("%d", &y[i]);
	for (int i = 0; i < n; i++) old[x[i] + 100][y[i] + 100] = true;
	int res = 0;
	for (int i = 0; i < 205; i++){
		for (int j = 0; j < 205; j++){
			if (newable(i, j)) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
