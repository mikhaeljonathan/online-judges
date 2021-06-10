#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int n, m;
	cin >> n >> m;
	int matrix[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &matrix[i][j]);
	
	int entries;
	cin >> entries;
	while (entries--){
		string com;
		int x, val;
		cin >> com >> x >> val;
		if (com == "row"){
			for (int i = 0; i < m; i++){
				matrix[x - 1][i] += val;
			}
		} else {
			for (int i = 0; i < n; i++){
				matrix[i][x - 1] += val;
			}
		}
	}
	int sum, minans, maxans;
	sum = 0, minans = 2<<29, maxans = -1 * (2<<29);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			sum += matrix[i][j];
			minans = min(minans, matrix[i][j]);
			maxans = max(maxans, matrix[i][j]);
		}
	}
	cout << sum << " " << minans << " " << maxans << endl;
	return 0;
}
