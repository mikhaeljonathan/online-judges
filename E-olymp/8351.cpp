#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, p, q;
int tm[1500];
vector< pair<int, int> > v;

bool doable(int idx){
	for (int i = -v[idx].second; i <= -v[idx].first; i++){
		if (tm[i] > n) return false;
	}
	return true;
}

int main (){
	cin >> n >> k;
	for (int i = 0; i < 1500; i++) tm[i] = 0;
	
	while (k--){
		int a,b,c,d;
		scanf("%d:%d-%d:%d",&a,&b,&c,&d);
		int minute1 = 60*a+b;
		int minute2 = 60*c+d;
		v.push_back(make_pair(-(minute2+29),-minute1));
	}
	
	sort(v.rbegin(), v.rend());
	
//	for (int i = 0; i < v.size(); i++){
//		cout<<v.at(i).first << " " << v.at(i).second << endl;
//	}
//	
	q = 0;
	for (int i = 0; i < v.size(); i++){
		bool check = true;
		
		for(int j = -v[i].second; j <= -v[i].first; j++){
			int temp = tm[j] + 1;
			if(temp > n){
				check = false;
				break;
			} 
		}
		
		if (check){
			for (int j=-v[i].second; j<=-v[i].first; j++){
				tm[j]++;
				if (tm[j] > q) q = tm[j];
			}
			p++;
		}
	}
	
	cout << p << " " << q << endl;
	
	return 0;
}
