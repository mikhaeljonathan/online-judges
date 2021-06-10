#include <stdio.h>
#include <math.h>

struct point{
	int x;
	int y;
}hashtable[1005];

struct rd{
	int begin;
	int end;
	double cost;
};

int par[1005];

double getdist(int begin, int end){
	double ret = sqrt(pow(hashtable[begin].x - hashtable[end].x, 2) + pow(hashtable[begin].y - hashtable[end].y, 2));
	return ret;
}

void merge(struct rd roads[], int aleft, int aright, int bleft, int bright){
	int size = bright - aleft + 1;
	struct rd temp[size];
	int aindex = aleft;
	int bindex = bleft;
	int tindex = 0;
	
	while (aindex <= aright && bindex <= bright){
		if (roads[aindex].cost <= roads[bindex].cost) temp[tindex++] = roads[aindex++];
		else temp[tindex++] = roads[bindex++];
	}
	
	while (aindex <= aright) temp[tindex++] = roads[aindex++];
	
	while (bindex <= bright) temp[tindex++] = roads[bindex++];
	
	for (int i = 0; i < size; i++) roads[aleft + i] = temp[i];
}

void mergesort(struct rd roads[], int left, int right){
	if (left == right) return;
	
	int mid = (left + right) / 2;
	mergesort(roads, left, mid);
	mergesort(roads, mid + 1, right);
	merge(roads, left, mid, mid + 1, right);
}

int findpar(int x){
	if (par[x] == x) return x;
	return par[x] = findpar(par[x]);
}

int issameset(int a, int b){
	return (findpar(a) == findpar(b));
}

void mergeset(int a, int b){
	int para = findpar(a);
	int parb = findpar(b);
	
	if (para == parb) return;
	
	par[para] = parb;
}

int main (){
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++){
		int n, r;
		scanf("%d %d", &n, &r);
		int x, y;
		
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			hashtable[i].x = x;
			hashtable[i].y = y;
			par[i] = i;
		}
		
		int size = n * (n - 1) / 2;
		struct rd roads[size];
		int idx = 0;
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				roads[idx].begin = i;
				roads[idx].end = j;
				roads[idx++].cost = getdist(i, j);
			}
		}
		
		mergesort(roads, 0, size - 1);
		
		double roadsvalue, railroadsvalue;
		roadsvalue = railroadsvalue = 0.0;
		int states = 1;
		for (int i = 0; i < size; i++){
			if (issameset(roads[i].begin, roads[i].end)) continue;
			mergeset(roads[i].begin, roads[i].end);
			
			if (roads[i].cost > r){
				states++;
				railroadsvalue += roads[i].cost;
			} else 
				roadsvalue += roads[i].cost;
		}
		
		printf("Case #%d: %d %d %d\n", tc, states, (int)round(roadsvalue), (int)round(railroadsvalue));
		
	}
	return 0;
}
