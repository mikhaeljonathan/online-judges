#include<stdio.h>

int par[200005];

struct edge {
	int a;
	int b;
	int cost;
};

struct edge tempArr[200005];
struct edge edgeArr[200005];

void makeSet(int n) {
	for(int i=0; i<=n; i++) par[i] = i;
}
int findParent(int x) {
	if (par[x] != x) par[x] = findParent(par[x]);
	return par[x];
}
int isSameSet(int a, int b) {
	return findParent(a) == findParent(b);
}
void mergeSet(int a, int b) {
	par[findParent(a)] = findParent(b);
}

void mergeSort(struct edge *arr, int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	
	int leftIdx = l;
	int toLeftIdx = mid;
	int rightIdx = mid+1;
	int toRightIdx = r;
	int tempIdx = l;
	while(leftIdx <= toLeftIdx && rightIdx <= toRightIdx) {
		if (arr[leftIdx].cost < arr[rightIdx].cost) {
			tempArr[tempIdx] = arr[leftIdx];
			leftIdx++;
		} else {
			tempArr[tempIdx] = arr[rightIdx];
			rightIdx++;
		}
		tempIdx++;
	}
	while(leftIdx <= toLeftIdx) {
		tempArr[tempIdx++] = arr[leftIdx++];
	}
	while(rightIdx <= toRightIdx) {
		tempArr[tempIdx++] = arr[rightIdx++];
	}
	for(int i=l; i<=r; i++) {
		arr[i] = tempArr[i];
	}
}

int main() {
	
	
	int n,m;
	while(scanf("%d %d", &n, &m) != EOF) {
		if ( n==0 && m==0 ) break;
		makeSet(n);
		int allCost = 0;
		for(int i=0; i<m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edgeArr[i].a = a;
			edgeArr[i].b = b;
			edgeArr[i].cost = c;
			allCost += c;
		}
		mergeSort(edgeArr, 0, m-1);
		int mstCost = 0;
		for(int i=0; i<m; i++) {
			int a = edgeArr[i].a;
			int b = edgeArr[i].b;
			int c = edgeArr[i].cost;
			if (isSameSet(a,b)) continue;
			mergeSet(a,b);
			mstCost += c;
		}
		printf("%d\n", allCost - mstCost);
		
	}
	
	return 0;
}
