#include <stdio.h>

char grid[105][105];
int visited[105][105];
int n;

void dfs(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == '.' || visited[x][y]) return;
	visited[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int main (){
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++){
		scanf("%d", &n); getchar();
		for (int i = 0; i < n; i++) scanf("%s", grid[i]);
		for (int i = 0; i < 105; i++) for (int j = 0; j < 105; j++) visited[i][j] = 0;
		int res = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (!visited[i][j] && grid[i][j] == 'x') {
					dfs(i, j);
					res++;
				}
			}
		}
		printf("Case %d: %d\n", tc, res);
	}
	return 0;
}
