#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int d, k;
	while (cin >> d >> k){
		if (d == 0 && k == 0) break;
		
		int dragon[d], knight[k];
		for (int i = 0; i < d; i++) cin >> dragon[i];
		for (int i = 0; i < k; i++) cin >> knight[i];
		sort(dragon, dragon + d);
		sort(knight, knight + k);
		
		int res = 0;
		bool completed = false;
		int idx = 0;
		for (int i = 0; i < k; i++) {
			if (knight[i] >= dragon[idx]){
				res += knight[i];
				idx++;
			}
			if (idx == d) {
				completed = true;
				break;
			}
		}
		
		if (!completed) cout << "Loowater is doomed!" << endl;
		else cout << res << endl;
	}
	
	return 0;
}
