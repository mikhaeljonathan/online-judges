#include <bits/stdc++.h>
using namespace std;

int main (){
	int n;
	cin >> n;
	int pelat[n + 1];
	for (int i = 0; i <= n; i++) cin >> pelat[i];
	int m;
	cin >> m;
	
	vector<int> v;
	int idx = n + 1;
	while(idx >= 0){
		while (m >= pelat[idx]){
			v.push_back()
			m-=pelat[idx];
		}
		idx--;
	}
	
	
	return 0;
}
