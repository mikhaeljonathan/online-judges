#include <iostream>
#define MOD 1000000007
// https://medium.com/@palak001/spoj-locker-magic-of-the-locker-a758bccf432f
using namespace std;

long long modex(long long x, long long y, long long z){
	if (y == 0) return 1;
	
	long long ret = modex(x, y/2, z);
	ret = (ret % z) * (ret % z) % z;
	
	if (y % 2 == 1) ret = (ret % z) * (x % z) % z;
	
	return ret;
}

int main (){
	long long t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		long long res, temp;
		if (n % 3 == 1){
			temp = (n - 4) / 3;
			res = 4 * modex(3, temp, MOD) % MOD;
		} else if (n % 3 == 2){
			temp = (n - 2) / 3;
			res = 2 * modex(3, temp, MOD) % MOD;
		} else {
			res = modex(3, n / 3, MOD);
		}
		
		if (n < 3) cout << n << endl;
		else cout << res << endl;
	}
	return 0;
}
