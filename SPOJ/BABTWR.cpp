#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Block{
	public:
		int x;
		int y;
		int z;
};

int n;
vector<Block> v;
int memo[3005][3005];

Block makeBlock(int x, int y, int z){
	Block ret;
	ret.x = x;
	ret.y = y;
	ret.z = z;
	return ret;
}

int dp(int w, int l){
	
	if (memo[w][l] != -1) return memo[w][l];
	
	int ret = 0;
	for (int i = 0; i < v.size(); ++i){
		if ((v[i].x < w && v[i].y < l) || (v[i].x < l && v[i].y < w))
			ret = max(ret, dp(v[i].x, v[i].y) + v[i].z);
			
		if ((v[i].y < w && v[i].z < l) || (v[i].y < l && v[i].z < w))
			ret = max(ret, dp(v[i].y, v[i].z) + v[i].x);
			
		if ((v[i].x < w && v[i].z < l) || (v[i].x < l && v[i].z < w))
			ret = max(ret, dp(v[i].x, v[i].z) + v[i].y);
	}
	
	return memo[w][l] = ret;
}

int main (){
	while (cin >> n){
		
		if (n == 0) break;
		
		v.clear();
		for (int i = 0; i < 3005; i++)
			for (int j = 0; j < 3005; j++)
				memo[i][j] = -1;
		
		while (n--){
			int x, y, z;
			cin >> x >> y >> z;
			v.push_back(makeBlock(x, y, z));
		}
		
		int ans = dp(3000, 3000);
		cout << ans << endl;
	}
	return 0;
}
