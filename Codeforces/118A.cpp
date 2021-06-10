#include <iostream>
using namespace std;

int main () {
	string x;
	cin >> x;
	string ans = "";
	for (int a = 0; a < x.length(); a++){
		if (x[a] == 'A' || x[a] == 'a' || x[a] == 'i' || x[a] == 'I' || x[a] == 'u' || x[a] == 'U'
		|| x[a] == 'e' || x[a] == 'E' || x[a] == 'O' || x[a] == 'o' || x[a] == 'y' || x[a] == 'Y' ){
			continue;
		} else {
			char temp;
			if (x[a] < 97){
				temp = x[a] + 32;
			} else {
				temp = x[a];
			}
			ans += '.';
			ans += temp;
		}
	}
	cout << ans << endl; 
	return 0;
}
