#include <iostream>
using namespace std;

int modex(int x, int y, int z){
	if (y == 0) return 1;
	
	int ret = modex(x, y/2, z);
	ret = (ret % z) * (ret % z) % z;
	
	if (y % 2 == 1) ret = (ret % z) * (x % z) % z;
	
	return ret;
}

int main (){
	int t;
	while (cin >> t){
		if (t == 0) break;
		while (t--){
			int x,y,z;
			cin >> x >> y >> z;
			cout << modex(x, y, z) << endl;
		}
	}
	return 0;
}
