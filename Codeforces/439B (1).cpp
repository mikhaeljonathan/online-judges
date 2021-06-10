#include <stdio.h>

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	char pixel[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%c", &pixel[i][j]);
			getchar();
		}
	}
	
	bool color = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (pixel[i][j] == 'C' || pixel[i][j] == 'M' || pixel[i][j] == 'Y') color = true;
	
	if (color) puts("#Color");
	else puts("#Black&White");
	
	return 0;
}
