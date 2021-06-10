#include <iostream>
#include <vector>
using namespace std;

int main (){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> v;
		while (n--){
			int c;
			cin >> c;
			v.push_back(c);
		}
		
		int total = 1;
		int res = v.size() > 1 ? 2 : 1;
		
		for (int i = 1; i < v.size() - 1; i++){
			if (total + v[i] < v[i + 1]){
				total += v[i];
				res++;
			}
		}
		
		cout << res << endl;
	}
	return 0;
}
