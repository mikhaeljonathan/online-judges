#include <iostream>
#include <cmath>

using namespace std;

/*
 * This code solves x which satisfies the equation:
 * (p*e^-x) + (qsin(x)) + (rcos(x)) + (s*tan(x)) + (t * x^2) + u = 0
 * 
 * Constraints:
 *    0 <= p, r <= 20
 *    -20 <= q, s, t <= 0
 *    0 <= x <= 1
 */

double p, q, r, s, t, u;
 
double pExp(double x){
	return p * exp(-x);
}

double qSin(double x){
	return q * sin(x);
}

double rCos(double x){
	return r * cos(x);
}

double sTan(double x){
	return s * tan(x);
}

double txx(double x){
	return t * x * x;
}

double result(double x){
	return pExp(x) + qSin(x) + rCos(x) + sTan(x) + txx(x) + u;
}

double findX(){
	double l, m, r;
	l = 0.0, r = 1.0;
	int iterate = 50;
	while (iterate--){
		m = (l + r) / 2.0;
		if (result(m) > 0) l = m;
		else r = m;
	}
	return r;
}

int main(){
	while (cin >> p >> q >> r >> s >> t >> u){
		if (result(1) > 1e-9 || p + r + u < 0){
			cout << "No solution" << endl;
			continue;
		}
		printf("%.4lf\n", findX());
	}
	return 0;
}
