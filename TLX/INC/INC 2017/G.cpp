#include <iostream>
using namespace std;

int a[305][305];
int n;

bool exotic(int i, int j){
	int temp = a[i][j];
	for (int x = i; x < n; x++){
		for (int y = j; y < n; y++){
			if (x == i && y == j) continue;
			if (a[x][y] == temp) return true;
		}
	}
	return false;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
			
	int res = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] < res) continue;
			if (exotic(i, j)){
				res = max(res, a[i][j]);
			}
		}
	}
	cout << res << endl;
	return 0;
}
