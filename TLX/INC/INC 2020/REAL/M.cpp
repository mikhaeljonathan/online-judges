#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int c[100100];

int main (){	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];
	int res = 0;
	
	for(int i = 0 ; i < n+10 ; i++){
		arr[i] = 0;
	}
	
	for (int i = 0; i < n; i++){
		if (c[i] == 0) continue;
		
		if(c[i] == 1 ){
			if (i - 1 >= 0 && arr[i - 1] == 0) {
				res++;
				arr[i-1] = 1;
				continue;
			}
			if(arr[i] == 0){
				res++;
				arr[i] = 1;
				continue;
			}
			
			if (i + 1 < n && arr[i + 1] == 0 ){
				arr[i+1]= 1;
				res++;
				continue;
			}
		}
		
		int cnt = 0;
		if (c[i] == 2){
			if(arr[i] == 0){
				res++;
				arr[i] = 1;
				cnt++;
			}
			if (i - 1 >= 0 && arr[i - 1] == 0) {
				res++;
				arr[i-1] = 1;
				cnt++;
			}
			if (i + 1 < n && arr[i + 1] == 0 && cnt < 2){
				arr[i+1]= 1;
				res++;
			}
		}
		
		if (c[i] == 3){
			if(arr[i] == 0){
				res++;
				arr[i] = 1;
			}
			if (i - 1 >= 0 && arr[i - 1] == 0) {
				arr[i-1] = 1;
				res++;
			}
			if (i + 1 < n && arr[i + 1] == 0) {
				arr[i+1]= 1;
				res++;
			}
		}
	}

	cout << res << endl;	
	return 0;
}
