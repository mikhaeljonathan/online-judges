#include <iostream>
using namespace std;

int main (){
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++){
		int n;
		scanf("%d", &n);
		getchar();
		char s[n + 5];
		scanf("%s", s);
		int res = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == '#') continue;
			s[i] = '#';
			if (i + 1 < n) s[i + 1] = '#';
			if (i + 2 < n) s[i + 2] = '#';
			res++;
		}
		printf("Case %d: %d\n", tc, res);
	}
	return 0;
}
