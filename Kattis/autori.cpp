#include <iostream>
using namespace std;

int main (){
	string x;
	cin >> x;
	for (int a = 0; a < x.length(); a++){
		if ((x[a] >= 65) && (x[a] <= 90)){
			cout << x[a];
		}
	}
	cout << endl;
	return 0;
}
