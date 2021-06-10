#include <iostream>
#include <algorithm>
using namespace std;

long long int take(long long int a, long long int b){
	
	long long int temp = a*b;
	if (temp < 0){
		if (a > 0){
			return a;
		} else {
			return b;
		}
	}
	
	if (a < b){
		return a;
	} else {
		return b;
	}
	
}

long long int solve(long long int money[], long long int n, long long int k){
	long long int f[k];
	f[0] = 0;
	
	for (int a = 1; a <= k; a++){
		long long int best = -1;
		for (int b = 0; b < n; b++){
			if (money[b] <= a){
				long long int temp;
				if (a - money[b] < 0){ // to prevent f[negative value]
					temp = -1;
				} else if (f[a - money[b]] == -1){ // when the smaller problem couldnt solve
					temp = -1;
				} else {
					temp = f[a - money[b]] + 1;
				}
				

				best = take(best, temp);

			}
		}
		f[a] = best;
	}
	
	return f[k];
}

int main (){
	// input
	long long int n;
	cin >> n;
	long long int money[n];
	for (int a = 0; a < n; a++){
		cin >> money[a];
	}
	long long int k;
	cin >> k;
	
	// execute
	long long int result = solve(money, n, k);
	
	// output
	cout << result << endl;
	return 0;
}
