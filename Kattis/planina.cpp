#include<iostream>
using namespace std;

int main () {
	int n;
	cin >> n;
	int start = 2;
	for (int counter = 1; counter <= n ;counter++){
		start += (start - 1);
	}
	start *= start;
	cout << start << endl;
	return 0;
}
