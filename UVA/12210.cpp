#include <stdio.h>
#include <algorithm>
using namespace std;

int main (){
	int b, s;
	int cases = 1;
	while (scanf("%d %d", &b, &s)){
		if (b == 0 && s == 0) break;
		int bachelor[b];
		int spinster[s];
		for (int i = 0; i < b; i++) scanf("%d", &bachelor[i]);
		for (int i = 0; i < s; i++) scanf("%d", &spinster[i]);
		
		sort(bachelor, bachelor + b);
		
		if (b > s) printf("Case %d: %d %d\n", cases++, b - s, bachelor[0]);
		else printf("Case %d: %d\n", cases++, 0);
	}
	return 0;
}
