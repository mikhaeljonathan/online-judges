#include <iostream>
using namespace std;

int main (){
	int month, depreciation;
	double dp, loan;
	while (cin >> month >> dp >> loan >> depreciation){
		if (month < 0) break;
		
		double dep[month];
		for (int i = 0; i < month; i++) dep[i] = -1;
		while (depreciation--){
			int x;
			double y;
			cin >> x >> y;
			dep[x] = y;
		}
		
		double carvalue = loan + dp;
		double ratecar = dep[0];
		carvalue = carvalue - (ratecar * carvalue);
		double rateloan = loan / (double)month;
		
		int mnth = 0;
		while (loan >= carvalue){
		
			if (mnth != 0) loan -= rateloan;
			
			
			if (mnth != 0){
				if (dep[mnth] != -1) ratecar = dep[mnth];
				carvalue = carvalue - (ratecar * carvalue);
			}
			
			
			mnth++;
		}
		
		if (mnth != 0) mnth--;
		cout << mnth << " ";
		if (mnth == 1) cout << "month" << endl;
		else cout << "months" << endl;
	}
	return 0;
}
