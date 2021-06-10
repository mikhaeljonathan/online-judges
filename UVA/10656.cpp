#include <iostream>
using namespace std;

int main (){
	int n;
	while (cin >> n){
		if (n == 0) break;
		int arr[n];
		for (int i = 0; i < n; i++) cin >> arr[i];
		bool first = true;
		for (int i = 0; i < n; i++){
			if (arr[i] == 0) continue;
			if (first) first = false;
			else cout << " ";
			
			cout << arr[i];
		}
		if (first) cout << "0";
		cout << endl;
	}
	return 0;
}
