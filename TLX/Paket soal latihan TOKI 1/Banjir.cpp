#include <stdio.h>

char grid[85][85];
int n, m;
bool kosong;
bool res;

void floodfill(int i, int j){
	
	if (grid[i][j] == '#') return;
	
	if (i == 0 || i == n - 1 || j == 0 || j == m - 1){
		kosong = false;
		return;
	}
	
	grid[i][j] = '#';
	floodfill(i + 1, j);
	floodfill(i - 1, j);
	floodfill(i, j + 1);
	floodfill(i, j - 1);
	
}

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m); getchar();
		for (int i = 0; i < n; i++){
			scanf("%[^\n]", grid[i]); getchar();
		}
		res = false;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (grid[i][j] == '#') continue;
				kosong = true;
				floodfill(i, j);
				res = res || kosong;
			}
		}
		if (res) printf("YA\n");
		else printf("TIDAK\n");
	}
	return 0;
}
