#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByFirst(pair<int, int> const &a, pair<int, int> const &b) {
	return (a.first > b.first);
}

int main (){
	int n;
	cin >> n;
	vector< pair<int, int> > v;
	for (int i = 0; i < n; i++){
		pair<int, int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), sortByFirst);
	
	bool visited[10005];
	for (int i = 0; i < 10005; i++) visited[i] = false;
	
	int res = 0;
	for (int i = 0; i < v.size(); i++){
		for (int j = v.at(i).second; j >= 1; j--){
			if (visited[j]) continue;
			res += v.at(i).first;
			visited[j] = true;
			break;
		}
	}
	
	cout << res << endl;
	return 0;
}
