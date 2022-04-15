#include <stdio.h>
#include <algorithm>
using namespace std;

int main (){
	int n;
	scanf("%d", &n);
	int s[n];
	int counts[10];
	for (int i = 0; i < 10 ; i++) counts[i] = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &s[i]);
		counts[s[i]]++;
	}
	
	// kalau 4 udah pasti nambah taxi, begitu juga utk 3
	// kalau 3 mencari 1 untuk saling melengkapi
	int res = counts[4] + counts[3];
	counts[1] -= counts[3];
	if (counts[1] < 0) counts[1] = 0;
	
	// 4 sama 3 nya beserta 1 yg merupakan pasangan 3 diexclue dr list, jadi list ini hny berisi 1 dan 2
	int temp[n];
	int idx = 0;
	for (int i = 1; i <= counts[1]; i++){
		temp[idx++] = 1;
	}
	for (int i = 1; i <= counts[2]; i++){
		temp[idx++] = 2;
	}
	
	// loop
	int container = 4;
	for (int i = 0; i < idx; i++){
		if (container + temp[i] <= 4) {
			container += temp[i];
		} else {
			container = temp[i];
			res++;
		}
	}
	
//	for (int i = 0; i < n; i++){
//		printf("%d ", s[i]);
//	}
//	printf("\n");
	

	printf("%d\n", res);
	return 0;
}
