#include <iostream>
#include <set>
using namespace std;

int main (){
	int n, m;
	while (cin >> n >> m){
		if (n == 0 && m == 0) break;
		set<int> cds;
		while (n--){
			int x;
			cin >> x;
			cds.insert(x);
		}
		int res = 0;
		while(m--){
			int x;
			cin >> x;
			if (cds.count(x) > 0) res++;
		}
		cout << res << endl;
	}
	
	return 0;
}
