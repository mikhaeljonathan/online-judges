#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	// input
	int n, m;
	cin >> n >> m;
	int feet[n];
	for (int a = 0; a < n; a++){
		cin >> feet[a];
	}
	int shoes[m];
	for (int a = 0; a < m; a++){
		cin >> shoes[a];
	}
	
	//initialize
	sort (feet, feet + n);
	sort (shoes, shoes + m);
	int feetindex = 0, shoesindex = 0, counter = 0;
	
	//execute;
	while ((feetindex < n) && (shoesindex < m)){
		if ((feet[feetindex] == shoes[shoesindex]) || (feet[feetindex] == shoes[shoesindex] - 1)){ // new shoes
			counter++;
			feetindex++;
			shoesindex++;
		} else if ((feet[feetindex] < shoes[shoesindex]) || (feet[feetindex] < shoes[shoesindex] - 1)){ // feet to small
			feetindex++;
		} else if (feet[feetindex] > shoes[shoesindex]){
			shoesindex++;
		}
	}
	
	// output
	cout << counter << endl;
	return 0;
}
