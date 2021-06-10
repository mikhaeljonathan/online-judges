#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int m;
	cin >> m; 
	int arr[m];
	for (int i = 0; i < m; i++) cin >> arr[i];
	sort(arr, arr + m);
	int n;
	cin >> n;
	
	return 0;
}
