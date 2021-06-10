#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	// Input
	int n;
	cin >> n;
	while (n--){
		string x;
		cin >> x;
		int temp = x.length();
		int dp[temp][temp];
		
		//initialize
		for (int a = 0; a < temp; a++){
			for (int b = 0; b < temp; b++){
				dp[a][b] = 0;
			}
		}
		for (int a = 0; a < temp; a++){
			dp[a][a] = 1;
		}
		
		// Execute
		for (int length = 2; length <= temp; length++){
			for (int i = 0; i <= temp - length; i++){
				int j = i + length - 1;
				if (x[i] == x[j]){
					dp[i][j] = dp[i + 1][j - 1] + 2;
				} else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		
		// Output
		cout << dp[0][temp - 1] << endl;
	}
	return 0;
}
