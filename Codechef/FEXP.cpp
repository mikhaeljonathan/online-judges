#include <iostream>
#define MOD 1000000007
using namespace std;

long long modex(int a, int b){
	if (b == 0) return 1;
	
	long long temp = modex(a, b / 2);
	temp = (temp % MOD) * (temp % MOD) % MOD;
	
	if (b % 2 == 1) temp = (temp % MOD) * (a % MOD) % MOD;
	
	return temp;
}

int main (){
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		cout << modex(a, b) << endl;
	}
	return 0;
}
