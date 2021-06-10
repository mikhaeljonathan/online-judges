#include<iostream>
using namespace std;

int main (){
	int n;
	cin >> n;
	double res = 0.0;
	for (int z = 1; z <= n; z++){
		double a, b;
		cin >> a >> b;
		double temp = a * b;
		res += temp;
	}
	cout << res << endl;
	return 0;
}
