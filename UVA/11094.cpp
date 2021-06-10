#include <stdio.h>

char map[25][25];
int visited[25][25];
int area;
int m, n;
char cur;

void dfs(int x, int y){
	if (x < 0 || y < 0 || x > m || y > n || map[x][y] != cur || visited[x][y]) return;
	visited[x][y] = 1;
	area++;
	dfs(x + 1, y);
	dfs(x - 1, y);
	(y == n - 1) ? dfs(x, 0): dfs(x, y + 1);
	(y == 0) ? dfs(x, n - 1): dfs(x, y - 1);
}

int main (){
	while (scanf("%d %d", &m, &n) != EOF){
		getchar();
		for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++) visited[i][j] = 0;
		for (int i = 0; i < m; i++) scanf("%s", map[i]);
		int x, y;
		scanf("%d %d", &x, &y);
		cur = map[x][y];
		dfs(x, y);
		int res = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (visited[i][j] || map[i][j] != cur) continue;
				area = 0;
				dfs(i, j);
				if (area > res) res = area;
			}
		}
		printf("%d\n", res);
		getchar();
	}
	return 0;
}
