#include <stdio.h>
using namespace std;

int p[100005];
bool sudahdibid[100005];

int main(){
	int n;
	scanf("%d", &n);
	
	int minbarang = (2<<29);
	
	for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		if (p[i] < minbarang) minbarang = p[i];
		sudahdibid[i] = false;
	}
	
	int res = 0;
	
	int m;
	scanf("%d", &m);
	int bidbefore = -1;
	int itembid = -1;
	
	while(m--){
		
		int b;
		scanf("%d", &b);
		
		if (b < minbarang) continue;

		int j = (b < bidbefore) ? itembid + 1 : 0;
		
		for (; j < n; j++){
			
			if (b >= p[j]){
				
				if (!sudahdibid[j]) res++;
				p[j] = b + 1;
				sudahdibid[j] = true;
				itembid = j;
				bidbefore = b;
				break;
				
			}
			
		}
		
	}
	
	printf("%d\n", res);
	
	return 0;
}
