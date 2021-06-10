#include <stdio.h>

int resx, resy;

int abs(int x){
	return (x < 0) ? -x : x;
}

void getResult(int point[], int s, int a, int min){
	
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int s, a, f;
		scanf("%d %d %d", &s, &a, &f);
		int point[s][a];
		for (int i = 0; i < s; i++) for (int j = 0; j < a; j++) point[i][j] = 0;
		while (f--){
			int x, y;
			scanf("%d %d", &x, &y);
			for (int i = 0; i < s; i++)
				for (int j = 0; j < a; j++)
					point[i][j] += abs(i + 1 - x) + abs(j + 1 - y);
		}
		
		int min = 1000000000;
		for (int i = 0; i < s; i++)
			for (int j = 0; j < a; j++)
				if (point[i][j] < min) min = point[i][j];

		int x, y;
		bool breakout = false;
		for (x = 0; !breakout && x < s; x++){
			for(y = 0; y < a; y++){
				if (point[x][y] == min) {
					breakout = true;
					break;
				}
			}
		}
			
		printf("(Street: %d, Avenue: %d)\n", x, y + 1);
	}
	return 0;
}
