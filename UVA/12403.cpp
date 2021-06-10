#include <iostream>
using namespace std;

int main (){
	int t;
	cin >> t;
	int total = 0;
	while (t--){
		string in;
		cin >> in;
		if (in.compare("donate") == 0) {
			int x;
			cin >> x;
			total += x;
		} else {
			cout << total << endl;
		}
	}
	return 0;
}
