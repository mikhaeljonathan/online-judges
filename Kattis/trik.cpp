#include <iostream>
using namespace std;

int main () {
	string x;
	cin >> x;
	int res = 1;
	for (int a = 0; a < x.length(); a++){
		if (x[a] == 'A'){
			if (res == 1){
				res = 2;
			} else if (res == 2){
				res = 1;
			}
		} else if (x[a] == 'B'){
			if (res == 2){
				res = 3;
			} else if (res == 3){
				res = 2;
			}
		} else {
			if (res == 1){
				res = 3;
			} else if (res == 3){
				res = 1;
			}
		}
	}
	cout << res << endl;
	return 0;
}
