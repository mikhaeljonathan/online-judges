#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Cylinder{
	public:
		int o;
		int n;
		int w;
};

vector<Cylinder> v;
int t, a;
int table[1005][505][505];

Cylinder newCylinder(int o, int n, int w){
	Cylinder ret;
	ret.o = o;
	ret.n = n;
	ret.w = w;
	return ret;
}

int dp(int idx, int oxy, int nit){
	
	if (oxy >= t && nit >= a) return 0;
		
	if (idx < 0) return (1 << 30);
	
	if (table[idx][oxy][nit] != -1) return table[idx][oxy][nit];
	
	return table[idx][oxy][nit] = min(dp(idx - 1, oxy, nit), dp(idx - 1, oxy + v[idx].o, nit + v[idx].n) + v[idx].w);
}

int main (){
	int c;
	cin >> c;
	while(c--){
		for (int i = 0; i < 1005; i++)
			for (int j = 0; j < 505; j++)
				for (int k = 0; k < 505; k++)
					table[i][j][k] = -1;
					
		v.clear();
		cin >> t >> a;
		int n;
		cin >> n;
		while (n--){
			int o, ni, w;
			cin >> o >> ni >> w;
			v.push_back(newCylinder(o, ni, w));
		}
		cout << dp(v.size() - 1, 0, 0) << endl;
	}
	return 0;
}
