#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> app[100005];
int gen[100005];
pair<int, long long> hasil[100005];

int main (){
	int n, m;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%d",&gen[i]);
	for (int i = 1; i <= m; i++){
		int c;
		scanf("%d",&c);
		while(c--){
			int s;
			scanf("%d",&s);
			app[i].push_back(s);
		}
	}
	//cout << "S" << endl;
	int q;
	scanf("%d",&q);
	
	for (int i = 0; i < 100005; i++) hasil[i] = pair<int, long long>(0,0);
	int version = 1;
	
	while(q--){
		int com;
		scanf("%d",&com);
		
		if (com == 1){
			int i, x;
			scanf("%d %d",&i,&x);
			gen[i] = x;
			version++;
		} else {
			int j;
			scanf("%d",&j);
			if(hasil[j].second != 0 && hasil[j].first == version){
				printf("%lld\n",hasil[j].second);
				continue;
			}
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
			
			printf("%lld\n",res);
			
			hasil[j].first = version;
			hasil[j].second = res;
		}
	}
	return 0;
}
