#include <iostream>
using namespace std;

int main (){
	int t;
	cin >> t;
	int index = 1;
	while (t--){
		int l, w, h;
		cin >> l >> w >> h;
		printf("Case %d: %s\n", index++, (l <= 20 && w <= 20 && h <= 20) ? "good" : "bad");
	}
	return 0;
}
