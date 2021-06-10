#include <iostream>
using namespace std;

int main () {
	// Input
	long long n;
	cin >> n;
	long long x[n + 1];
	x[0] = 0;
	for (long long a = 1; a <= n; a++){
		long long temp;
		cin >> temp;
		x[a] = x[a - 1] + temp; // Automatically sorted
	}
	long long q;
	cin >> q;
	for (long long a = 0; a < q; a++){
		long long input;
		cin >> input; // Input
		// Binary search
		long long hasil = 0;
		long long left = 1;
		long long right = n;
		long long mid;
		while ((left <= right) && (hasil == 0)){
			mid = (left + right) / 2;
			if ((input <= x[mid]) && (input > x[mid - 1])){
				hasil = mid;
			} else if ((input <= x[mid]) && (input <= x[mid - 1])){ // input too small
				right = mid - 1;
			} else if ((input > x[mid]) && (input > x[mid - 1])){
				left = mid + 1;
			}
		}
		cout << mid << endl;
	}
	return 0;
}
