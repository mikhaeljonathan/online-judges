#include <iostream>
using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(int a, int b){
	long long ret = a / gcd(a, b);
	ret *= b;
	return ret;
}

int main (){
	int t;
	cin >> t;
	while (t--){
		int a, b;	
		cin >> a >> b;
		long long llcm = lcm(a, b);
		cout << gcd(a, b) << " " << llcm << endl;
	}
	return 0;
}
