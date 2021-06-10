#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int n;
	cin >> n;
	int f[10000];
	f[0] = 0;
	for (int a = 1; a <= n; a++){
		f[a] = max(a, f[a / 2] + f[a / 3] + f[a / 4]);
	}
	cout << f[n] << endl;
	return 0;
}
