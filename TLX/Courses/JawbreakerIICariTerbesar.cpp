#include <iostream>
using namespace std;

bool visited[25][25];
int count = 0;
int arr[25][25];

void jawbreaker (int x, int y, int m, int n, int c){
	if ((x >= 0) && (x < m) && (y >= 0) && (y < n)){
		if (!visited[x][y]){
			visited[x][y] = true;
			if (arr[x][y] == c){
				count++;
				// Flood-fill
				jawbreaker(x+1, y, m, n, c);
				jawbreaker(x, y+1, m, n, c);
				jawbreaker(x-1, y, m, n, c);
				jawbreaker(x, y-1, m, n, c);
			}
		}
	}
}

int main (){
	int m, n;
	cin >> m >> n;
	
	// Input
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	// Initiation
	jawbreaker(0, 0, m, n, arr[0][0]);
	int max = count;
	count = 0;
	
	// Check 1 by one
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			
			// Already stored in max variable
			if ((i == 0) && (j == 0)){
				continue;
			}
			
			// Initiation for bool visited to be false
			for (int k = 0; k < 25; k++){
				for (int l = 0; l < 25; l++){
					visited[k][l] = false;
				}
			}
			
			//Execute
			jawbreaker(i, j, m, n, arr[i][j]);
			if (max < count){
				max = count;
			}
			count = 0;
		}
	}
	cout << max*(max-1) << endl;
	
	return 0;
}
