#include <iostream>
#define MOD 1000000
using namespace std;

bool over999999;

long long int pow (long long int a, long long int b) {
	if (b == 0) {
		return 1;
	}
	
	//fastexp
	long long int res;
	res = pow(a, b/2);
	long long int temp = res * res;
	if (temp > 999999){
		over999999 = true;
	}
	
	res = ((res % MOD) * (res % MOD)) % MOD;
	if (b % 2 == 1){
		res = ((res % MOD) * (a % MOD)) % MOD;
	}
	
	return res;
}

int main () {
	long long int a, b;
	cin >> a >> b;
	over999999 = false;
	long long int res = pow (a, b);
	res %= MOD;
	
	// leading zero if over than 999999
	if (over999999){
		if (res < 10){
			cout << "00000" << res;
		} else if (res > 10 && res < 100) {
			cout << "0000" << res;
		} else if (res > 100 && res < 1000) {
			cout << "000" << res;
		} else if (res > 1000 && res < 10000) {
			cout << "00" << res;
		} else if (res > 10000 && res < 100000) {
			cout << "0" << res;
		} else {
			cout << res;
		}
	} else {
		cout << res;
	}
	
	cout << endl;
	return 0;
}
