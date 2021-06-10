#include <iostream>
using namespace std;

int modex(int x, int y, int z){
	if (y == 0) return 1;
	
	int ret = modex(x, y/2, z);
	ret = (ret % z) * (ret % z) %z;
	
	if (y % 2 == 1) ret = (ret % z) * (x % z) % z;
	
	return ret;
}

int main (){
	int t;
	cin >> t;
	while (t--){
		int a, b;
		cin >> a >> b;
		cout << modex(a, b, 10) << endl;
	}
	return 0;
}
