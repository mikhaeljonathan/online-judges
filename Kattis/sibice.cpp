#include <iostream>
#include <math.h>
using namespace std;

int main () {
	int n, w, h;
	cin >> n >> w >> h;
	double pythagoras = sqrt(w * w + h * h);
	for (int a = 1; a <= n; a++){
		int temp;
		cin >> temp;
		if (temp <= pythagoras){
			cout << "DA" << endl;
		} else {
			cout << "NE" << endl;
		}
	}
	return 0;
}
