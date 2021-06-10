#include <stdio.h>

char grid[505][505];
int n, m;
int total;
bool ever[505][505];

void floodfill(int i, int j){
	
	if (i < 0 || i == n || j < 0 || j == m) return;
	if (ever[i][j]) return;
	if (grid[i][j] == '#') return;
	
	total++;
	ever[i][j] = true;
	floodfill(i + 1, j);
	floodfill(i - 1, j);
	floodfill(i, j + 1);
	floodfill(i, j - 1);
	
}

int main (){
	scanf("%d %d", &n, &m);
	int total_bebek, total_kucing;
	for (int i = 0; i < n; i++) scanf("%s", grid[i]);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == 'B'){
				total = 0;
				for (int k = 0; k < 505; k++) for (int l = 0; l < 505; l++) ever[k][l] = false;
				floodfill(i, j);
				total_bebek = total;
			}
			if (grid[i][j] == 'K'){
				total = 0;
				for (int k = 0; k < 505; k++) for (int l = 0; l < 505; l++) ever[k][l] = false;
				floodfill(i, j);
				total_kucing = total;
			}
		}
	}
	if (total_bebek > total_kucing){
		printf("B %d\n", total_bebek - total_kucing);
	} else if (total_bebek < total_kucing){
		printf("K %d\n", total_kucing - total_bebek);
	} else {
		printf("SERI\n");
	}
	return 0;
}
