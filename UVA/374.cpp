#include <stdio.h>
using namespace std;

int modex(int x, int y, int z){
	if (y == 0) return 1;
	
	int ret = modex(x, y/2, z);
	ret = (ret % z) * (ret % z) % z;
	
	if (y % 2 == 1) ret = (ret % z) * (x % z) % z;
	
	return ret;
}

int main (){
	int b, p, m;
	while (scanf("%d %d %d", &b, &p, &m) != EOF){
		printf("%d\n", modex(b, p, m));
	}
	return 0;
}
