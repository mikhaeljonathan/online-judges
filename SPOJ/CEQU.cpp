#include <iostream>
#include <math.h>
using namespace std;
// https://cp-algorithms.com/algebra/linear-diophantine-equation.html

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

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main (){
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int a, b, c, x, y, g;
		cin >> a >> b >> c;
		cout << "Case " << tc << ": ";
		if (find_any_solution(a, b, c, x, y, g)){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
