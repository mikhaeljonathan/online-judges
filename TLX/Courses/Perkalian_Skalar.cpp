#include <iostream>
#include <algorithm>
#define forr(a, n) for (int a = 0; a < n; a++)
using namespace std;

int main (){
	// Input
	int n;
	cin >> n;
	long long int x[n], y[n];
	forr (a, n){
		cin >> x[a];
	}
	forr (a, n){
		cin >> y[a];
	}
	
	// Initialize
	sort(x, x + n);
	sort(y, y + n);
	int yindex = n - 1;
	long long int res = 0;
	
	// Execute
	forr (xindex, n){
		res += x[xindex] * y[yindex];
		yindex--;
	}
	
	// Output
	cout << res << endl;
	return 0;
}
