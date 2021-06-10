#include <stdio.h>
#include <math.h>
using namespace std;

int modex(int x, int y, int z){
	if (y == 0) return 1;
	
	int ret = modex(x, y/2, z);
	ret = (ret % z) * (ret % z) % z;
	
	if (y % 2 == 1) ret = (ret % z) * (x % z) % z;
	
	return ret;
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, k;
		scanf("%d %d", &n, &k);
		int header = (int) pow(10, 2 + fmod(k * log10(n), 1));
		int trailer = modex(n, k, 1000);
		printf("%d...%03d\n", header, trailer);
	}
	return 0;
}
