#include <stdio.h>
#include <string.h>

int visited[505];
int distance[505];
char state[505][7];
int n;

int min(int a, int b){
	return (a < b) ? a : b;
}

int max(int a, int b){
	return (a < b) ? b : a;
}

int getdist(char a[], char b[]){
	int res = 0;
	for (int i = 0; i < 4; i++) 
		res += min( max(a[i], b[i]) - min(a[i], b[i]), min(a[i], b[i]) + 10 - max(a[i], b[i]) );
	return res;
}

void prim(int begin, int begindist){
	for (int i = 0; i < n; i++){
		visited[i] = 0;
		distance[i] = 1 << 29;
	}
	distance[begin] = begindist;
	
	for (int _ = 0; _ < n; _++){
		int min = (1 << 29) + 1;
		int curstate = -1;
		for (int i = 0; i < n; i++){
			if (visited[i]) continue;
			if (distance[i] < min){
				min = distance[i];
				curstate = i;
			}
		}
		
		if (visited[curstate]) continue;
		visited[curstate] = 1;
		
		for (int i = 0; i < n; i++){
			if (visited[i]) continue;
			int dist = getdist(state[curstate], state[i]);
			if (dist < distance[i]) distance[i] = dist;
 		}
	}
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		
		char beginning[7];
		strcpy(beginning, "0000");
		
		int min = 1 << 30;
		int minstate = -1;
		for (int i = 0; i < n; i++) {
			scanf("%s", state[i]);
			int dist = getdist(state[i], beginning);
			if (dist < min){
				min = dist;
				minstate = i;
			}
		}
		
		prim(minstate, min);
		
		int res = 0;
		for (int i = 0; i < n; i++) res += distance[i];
		printf("%d\n", res);
		
	}
	return 0;
}
