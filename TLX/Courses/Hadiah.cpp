#include <iostream>
using namespace std;

long long modex(long long a, long long b, long long n){
	if (b == 0){
		return 1;
	} else {
		long long temp = modex(a, b/2, n) % n;
		temp = ((temp % n) * (temp % n)) % n;
		if (b % 2 != 0){
			temp = ((temp % n) * (a % n)) % n;
		} 
		return temp;
	}
}

// a^(b^c)%n == ((a^b)%n)^(b^(c-1))

long long calculate (long long a, long long b, long long c, long long n){
	for (long long i = c; i >= 1; i--){ // i'm using iterative, not recursive to prevent stack overflow
		a = modex(a, b, n) % n;
	}
	a = a % n;
	return a;
}

int main (){
	// Input
	long long a, b, c, n;
	cin >> a >> b >> c >> n;
	// Execute
	long long res = calculate(a, b, c, n) % n;
	// 0 ^ 0 = 1
	if ((a == 0) && (b == 0) && (c != 0)){
		res = 1 % n;
	}
	res++;
	// Output
	cout << res << endl;
	return 0;
}
