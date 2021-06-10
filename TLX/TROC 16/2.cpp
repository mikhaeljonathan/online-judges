#include <stdio.h>
#include <algorithm>
using namespace std;

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int maxdist = m + a[0] - a[n - 1];
	for (int i = 1; i < n; i++){
		maxdist = max(maxdist, a[i] - a[i - 1]);
	}
	int res = m - maxdist;
	printf("%d\n", res);
	return 0;
}
