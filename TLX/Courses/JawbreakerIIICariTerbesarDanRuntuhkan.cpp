#include <iostream>
using namespace std;

bool visited[25][25];
int count = 0;
int arr[25][25];
int row, column;

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
				row = x;
				column = y;
			}
		}
	}
}

void jawbreakerRuntuh (int x, int y, int m, int n, int c){
	if ((x >= 0) && (x < m) && (y >= 0) && (y < n)){
		if (!visited[x][y]){
			visited[x][y] = true;
			if (arr[x][y] == c){
				arr[x][y] = 0;
				// Flood-fill
				jawbreakerRuntuh(x+1, y, m, n, c);
				jawbreakerRuntuh(x, y+1, m, n, c);
				jawbreakerRuntuh(x-1, y, m, n, c);
				jawbreakerRuntuh(x, y-1, m, n, c);
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
	
	// Initiation for row and column max value
	int rowMax = 0, columnMax = 0;
	
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
				rowMax = row;
				columnMax = column;
			}
			count = 0;
		}
	}
	
	// Initiation for bool visited to be false
	for (int k = 0; k < 25; k++){
		for (int l = 0; l < 25; l++){
			visited[k][l] = false;
		}
	}
	
	// Execute
	jawbreakerRuntuh(rowMax,columnMax,m,n,arr[rowMax][columnMax]);

	// Execute
	for (int j = 0; j < n; j++){
		for (int i = m-1; i >= 0; i--){
			if (arr[i][j] == 0){
				
				// Identify how many zeros
				int countZero = 0;
				int index = i;
				do {
					countZero++;
					index--;
				} while (arr[index][j]==0);
				
				// Runtuh
				while (index >= 0){
					
					// Swap
					int temp = arr[index][j];
					arr[index][j] = 0;
					arr[index + countZero][j] = temp;
					
					index--;
				}
			}
		}
	}
	
	// Output
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (arr[i][j] == 0){
				cout << ".";
			} else {
				cout << arr[i][j];
			}
			if (j!=n-1){
				cout << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}
