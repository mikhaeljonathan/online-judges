#include <stdio.h>
#include <string.h>

void makeset(int par[], int x){
	for (int i = 0; i <= x; i++) par[i] = i;
}

int findpar(int par[], int x){
	if (par[x] == x) return x;
	else return par[x] = findpar(par, par[x]);
}

void mergeset(int par[], int x, int y){
	par[findpar(par, x)] = findpar(par, y);
}

int issameset(int par[], int x, int y){
	return (findpar(par, x) == findpar(par, y));
}

int main (){
	int n;
	scanf("%d", &n); getchar();
	while (n--){
		getchar();
		int vtx;
		scanf("%d", &vtx); getchar();
		int par[vtx + 1];
		makeset(par, vtx);
		char query[100];
		int success = 0;
		int unsucc = 0;
		while (scanf("%[^\n]", query) && strcmp(query, "")){
			getchar();
			char com;
			int x, y;
			sscanf(query, "%c %d %d", &com, &x, &y);
			if (com == 'c'){
				mergeset(par, x, y);
			} else {
				if (issameset(par, x, y)) success++;
				else unsucc++;
			}
			strcpy(query, "");
		}
		printf("%d,%d\n", success, unsucc);
		if (n != 0) puts("");
	}
	return 0;
}
