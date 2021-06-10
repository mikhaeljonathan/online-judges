#include <iostream>
#include <vector>
using namespace std;


int main (){
	int n;
	cin >> n;
	vector<int> a;
	while (n--){
		int x;
		cin >> x;
		a.push_back(x);
	}
	int res = 0;
	int temp = 1;
	int valbefore = 1000000003;
	for (int i = 0; i < a.size(); i++){
		if (a[i] >= valbefore){
			temp++;
		} else {
			temp = 1;
		}
		res = max(res, temp);
		valbefore = a[i];
	}
	cout << res << endl;
	return 0;
}
