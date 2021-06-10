#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int n, d, r;
	while (scanf("%d %d %d", &n, &d, &r)){
		if (n == 0 && d == 0 && r == 0) break;
		int morn[n], eve[n];
		for (int i = 0; i < n; i++) scanf("%d", &morn[i]);
		for (int i = 0; i < n; i++) scanf("%d", &eve[i]);
		sort(morn, morn + n);
		sort(eve, eve + n, greater<int>());
		int res = 0;
		for (int i = 0; i < n; i++){
			if (morn[i] + eve[i] <= d) continue;
			res += (morn[i] + eve[i]) - d;
		}
		res *= r;
		printf("%d\n", res);
	}
	
	return 0;
}
