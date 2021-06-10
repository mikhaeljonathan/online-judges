#include <iostream>
#include <vector>
using namespace std;

vector<int> app[100005];
int gen[100005];

int main (){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> gen[i];
	for (int i = 1; i <= m; i++){
		int c;
		cin >> c;
		while(c--){
			int s;
			cin >> s;
			app[i].push_back(s);
		}
	}
	
	int q;
	cin >> q;
	while(q--){
		int com;
		cin >> com;
		if (com == 1){
			int i, x;
			cin >> i >> x;
			gen[i] = x;
		} else {
			int j;
			cin >> j;
			long long res = 0;
			int size = app[j].size();
			long long term1 = 0;
			long long term2 = 0;
			for (int a = 0; a < size; a++){
				term1 += gen[app[j][a]];
				term2 += gen[app[j][a]] * gen[app[j][a]];
			}
			term1 *= term1;
			res = term1 - term2;
			res /= 2;
			
			cout << res << endl;
		}
	}
	return 0;
}
