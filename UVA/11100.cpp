#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool oneexist(bool exist[], int n){
	for (int i = 0; i < n; i++){
		if (exist[i]) return true;
	}
	return false;
}

int main (){
	int n;
	while (cin >> n){
		if (n == 0) break;
		int arr[n];
		bool exist[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			exist[i] = true;
		}
		
		sort(arr, arr + n);
		
		vector< vector <int> > v;
		while (oneexist(exist, n)){
			vector<int> vtemp;
			int before = -1;
			for (int i = 0; i < n; i++){
				if (!exist[i]) continue;
				if (arr[i] > before){
					before = arr[i];
					exist[i] = false;
					vtemp.push_back(arr[i]);
				}
			}
			v.push_back(vtemp);
		}
		
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++){
			for (int j = 0; j < v[i].size(); j++){
				cout << v[i][j];
				if (j != v[i].size() - 1) cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
