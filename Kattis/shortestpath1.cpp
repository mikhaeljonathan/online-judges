#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct tdata {
	int kota;
	int cost;
	struct tdata *next;
};

struct heapData {
	int distance;
	int kota;
};

heapData arrHeap[500000];
int heapCountData = 0;

struct tdata *adjListHead[10005];

/* ALL HEAP OPERATION */
int compare(struct heapData a, struct heapData b) {
	// -1, JIKA a < b
	// 0, JIKA a == b
	// 1, JIKA a > b
	if (a.distance < b.distance) return -1;
	if (a.distance == b.distance) {
		if (a.kota < b.kota) return -1;
		if (a.kota == b.kota) return 0;
		return 1;
	}
	return 1;
}
void downHeap(struct heapData *heapArr, int idx,
						int ndata) {
	int toIdx = idx;
	if (2*idx <= ndata &&
			compare(heapArr[toIdx], heapArr[2*idx]) > 0) {
		toIdx = 2*idx;
	}
	if (2*idx+1 <= ndata &&
		compare(heapArr[toIdx], heapArr[2*idx+1]) > 0) {
		toIdx = 2*idx+1;
	}
	if (toIdx == idx) return;
	
	// swap
	struct heapData temp = heapArr[toIdx];
	heapArr[toIdx] = heapArr[idx];
	heapArr[idx] = temp;
	
	downHeap(heapArr, toIdx, ndata);
}

void makeHeap(struct heapData *heapArr, int n) {
	for(int i=n/2; i > 0; i--) {
		downHeap(heapArr, i, n);
	}
}

void popHeap(struct heapData *heapArr, int *n) {
	if (*n == 1) {
		(*n)--;
		return;
	}
	heapArr[1] = heapArr[*n];
	// swap root dengan si arrHeap[n]
	//int temp = heapArr[1];
	//heapArr[1] = heapArr[*n];
	//heapArr[*n] = temp;
	(*n)--;
	downHeap(heapArr, 1, *n);
}

void upHeap(struct heapData *heapArr, int idx,
						int ndata) {
	if (idx == 1) return;
	int ParentIdx = idx / 2;
	// heapArr[ParentIdx] < heapArr[idx]
	if (compare(heapArr[ParentIdx], heapArr[idx]) < 0) return;
	// swap with parent
	struct heapData temp = heapArr[ParentIdx];
	heapArr[ParentIdx] = heapArr[idx];
	heapArr[idx] = temp;
	
	upHeap(heapArr, ParentIdx, ndata);
}

void pushHeap(struct heapData *heapArr, int *n,
							int distance, int kota) {
	(*n)++;
	heapArr[*n].distance = distance;
	heapArr[*n].kota = kota;
	upHeap(heapArr, *n, *n);
}

struct heapData topHeap(struct heapData *heapArr, int n) {
	// THIS FUNCTION TIDAK BOLEH
	// DI PANGGIL JIKA DI DALAM HEAP
	// TIDAK ADA DATA.
	// ASUMSI DI BAWAH ADALAH
	// -2MILYAR TIDAK AKAN PERNAH ADA
	// GUNAKAN NILAI LAIN JIKA PERLU
	if (n < 1) return {-1, -1};
	return heapArr[1];
}
 

/* ADJ LIST OPERATION */
void pushList(struct tdata **localHead, int kota, int cost) {
	struct tdata *newnode = (struct tdata *)malloc(
										sizeof(struct tdata));
	newnode->next = NULL;
	newnode->kota = kota;
	newnode->cost = cost;
	if (*localHead == NULL) {
		*localHead = newnode;
	} else {
		newnode->next = *localHead;
		*localHead = newnode;
	}
}

void popAll(struct tdata **localHead) {
	while(*localHead != NULL) {
		struct tdata *del = *localHead;
		*localHead = (*localHead)->next;
		free(del);
	}
}

// kalau V nya byk, declare visited & distance
// di global
int visited[10005];
int distance[10005];


void dijkstra(struct tdata **localAdjList, int V, int a) {
	// kalo V nya sedikit, bisa declare
	// visited & distance di local
	// int visited[V+5];
	// int distance[V+5];

	heapCountData = 0;
	for(int i=0; i<V; i++) {
		visited[i] = 0;
		// our infinity is 2^30
		// di rubah sesuai kebutuhan
		distance[i] = (1 << 30);
	}
	distance[a] = 0;
	
	// masukkan a ke heap
	pushHeap(arrHeap, &heapCountData, distance[a], a);
	
	//for(int _=0; _<V; _++) {
	while(heapCountData > 0) {
		// cari terminimum
		struct heapData topData = topHeap(arrHeap, heapCountData);
		popHeap(arrHeap, &heapCountData);
		int curKota = topData.kota;
		int curDist = topData.distance;

		if (visited[curKota]) continue;
		visited[curKota] = 1;
		
		// bisa kalo ketemu lsg return
		/*
		if (curKota == b) {
			return distance[b];
		}
		*/
		
		struct tdata *current = localAdjList[curKota];
		while(current != NULL) {
			if (visited[current->kota] == 0
				&& (distance[curKota]
					+ current->cost) <
					distance[current->kota]) {
						
				distance[current->kota] = distance[curKota]
					+ current->cost;
				pushHeap(arrHeap, &heapCountData,
							distance[current->kota],
								current->kota);
			}
			current = current->next;
		}
		
	}
}

int main() {
	
	int n, m, q, s;
	while(scanf("%d %d %d %d", &n, &m, &q, &s) != EOF) {
		if (n==0 && m==0 && q==0 && s==0) break;
		for(int i=0; i<n; i++) {
			adjListHead[i] = NULL;
		}
		for(int i=0; i<m; i++) {
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			pushList(&adjListHead[u], v, w);
			//pushList(&adjListHead[v], u, w);
		}
		dijkstra(adjListHead, n, s);
		for(int i=0; i<q; i++) {
			int to;
			scanf("%d", &to);
			if (distance[to] >= (1 << 30)) puts("Impossible");
			else printf("%d\n", distance[to]);
		}
		puts("");
		for(int i=0; i<n; i++) {
			popAll(&adjListHead[i]);
		}
	}
	
}
