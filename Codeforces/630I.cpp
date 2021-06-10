#include <iostream>
using namespace std;

long long pow(int a, int b){
	if (b == 0) return 1;
	
	long long ret = pow(a, b/2);
	ret *= ret;
	
	if (b % 2 == 1) ret *= a;
	
	return ret;
}

long long f(long long n){
	long long a, b, c;
	a = 2 * 3 * pow(4, n - 3);
	b = n - 3;
	c = 3 * 3 * pow(4, n - 4);
	long long ret = (a + b * c) * 4;
	return ret;
}

int main (){
	long long n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}
