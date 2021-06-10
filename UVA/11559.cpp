#include <iostream>
using namespace std;

int main (){
	int n, b, h, w;
	while (cin >> n >> b >> h >> w){
		int res = 1 << 30;
		for (int j = 1; j <= h; j++){
			int p;
			cin >> p;
			for (int i = 1; i <= w; i++){
				int a;
				cin >> a;
				if (a < n) continue;
				if (n * p > b) continue;
				if (n * p < res) res = n * p;
			}
		}
		if (res == 1 << 30) cout << "stay home" << endl;
		else cout << res << endl;
	}
	
	return 0;
}
