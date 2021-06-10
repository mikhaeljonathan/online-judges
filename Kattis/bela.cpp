#include <iostream>
using namespace std;

int main () {
	int n; char b;
	cin >> n >> b;
	int res = 0;
	for (int a = 1; a <= 4 * n; a++){
		string x;
		cin >> x;
		char num = x[0];
		char suit = x[1];
		bool dominant = (suit == b);
		if (!dominant) {
			switch (num) {
				case 'A':
					res += 11;
					break;
				case 'K':
					res += 4;
					break;
				case 'Q':
					res += 3;
					break;
				case 'J':
					res += 2;
					break;
				case 'T':
					res += 10;
					break;
				case '9':
				case '8':
				case '7':
					break;
			}
		} else {
			switch (num) {
				case 'A':
					res += 11;
					break;
				case 'K':
					res += 4;
					break;
				case 'Q':
					res += 3;
					break;
				case 'J':
					res += 20;
					break;
				case 'T':
					res += 10;
					break;
				case '9':
					res += 14;
				case '8':
				case '7':
					break;
			}
		}
	}
	cout << res << endl;
	return 0;
}
