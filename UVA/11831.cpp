#include <stdio.h>

int current(char x){
	if (x == 'N' || x == 'L' || x == 'S' || x == 'O') return 1;
	return 0;
}

char map[105][105];

int main (){
	int n, m, s;
	while (scanf("%d %d %d", &n, &m, &s) != EOF && n != 0 && m != 0 && s != 0){
		getchar();
		for (int i = 0; i < n; i++) scanf("%s", map[i]);
		char com[50005];
		scanf("%s", com);
		int x, y, pos;
		char position[4] = {'N', 'L', 'S' ,'O'};
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (current(map[i][j])){
					x = i;
					y = j;
					if (map[i][j] == 'N') pos = 0;
					if (map[i][j] == 'L') pos = 1;
					if (map[i][j] == 'S') pos = 2;
					if (map[i][j] == 'O') pos = 3;
				}
			}
		}
		int idx = 0;
		int res = 0;
		while (idx < s){
			if (com[idx] == 'D') pos = (pos + 1) % 4;
			if (com[idx] == 'E') {
				if (pos == 0) pos = 3;
				else pos--;
			}
			if (com[idx] == 'F'){
				if (pos == 0 && x - 1 >= 0 && map[x - 1][y] != '#') x--;
				if (pos == 1 && y + 1 < m && map[x][y + 1] != '#') y++;
				if (pos == 2 && x + 1 < n && map[x + 1][y] != '#') x++;
				if (pos == 3 && y - 1 >= 0 && map[x][y - 1] != '#') y--;
			}
//			printf("%c %c x %d y %d\n",com[idx], position[pos], x, y);
			if (map[x][y] == '*'){
//				puts("wow");
				map[x][y]= '.';
				res++;
			}
			idx++;
		}
		printf("%d\n", res);
	}
	return 0;
}
