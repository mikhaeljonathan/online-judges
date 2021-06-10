#include <iostream>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main (){
	int a, b;
	while (cin >> a >> b){
		int x, y;
		int res = gcd(a, b, x, y);
		cout << x << " " << y << " " << res << endl;
	}
	return 0;
}
