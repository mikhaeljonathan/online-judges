#include <iostream>
#define MOD 10000007
using namespace std;

long long modex(long long x, long long y, long long z){
	if (y == 0) return 1;
	
	long long ret = modex(x, y/2, z);
	ret = (ret % z) * (ret % z) % z;
	
	if (y % 2 == 1) ret = (ret % z) * (x % z) % z;
	
	return ret;
}

int main (){
	long long n, k;
	while (cin >> n >> k){
		if (n == 0 && k == 0) break;
		long long sn, pn;
		
		sn = (2 * modex(n - 1, k, MOD)) % MOD;
		sn = (sn + modex(n, k, MOD)) % MOD;
		
		pn = (2 * modex(n - 1, n - 1, MOD)) % MOD;
		pn = (pn + modex(n, n, MOD)) % MOD;
		
		long long ret = (sn % MOD + pn % MOD) % MOD;
		cout << ret << endl;
	}
	return 0;
}
