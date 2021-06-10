#include <iostream>
using namespace std;

int main (){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int left = 0;
	int right = k - 1;
	int container[30] = {0};
	int maxx = 0;
	for (int i = left; i <= right; i++){
		int alphabet = s[i] - 'A';
		container[alphabet]++;
		if (container[alphabet] > maxx) {
			maxx = container[alphabet];
		}
	}
	for (left+=1, right+=1; right < n; left++, right++){
		int alphabet = s[right] - 'A';
		container[s[left - 1] - 'A']--;
		container[alphabet]++;
		if (container[alphabet] > maxx){
			maxx = container[alphabet];
		}
	}
	int res = k - maxx;
	if (res < 0) cout << "0" << endl;
	else cout << res << endl;
	return 0;
}
