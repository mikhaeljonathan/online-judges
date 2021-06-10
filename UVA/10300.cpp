#include <iostream>
using namespace std;

int main (){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int res = 0;
		while (n--){
			int a, b, c;
			cin >> a >> b >> c;
			res += a * c;
		}
		cout << res << endl;
	}
	return 0;
}
