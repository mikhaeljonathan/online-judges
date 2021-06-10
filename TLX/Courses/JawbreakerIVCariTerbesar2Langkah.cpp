#include <iostream>
#include <cstring>
using namespace std;

bool visited[25][25];
int count = 0;
int arr[25][25];
int arrChange[25][25];

void jawbreaker (int x, int y, int m, int n, int c){
	if ((x >= 0) && (x < m) && (y >= 0) && (y < n)){
		if (!visited[x][y]){
			visited[x][y] = true;
			if (arrChange[x][y] == c){
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

void jawbreakerRuntuh (int x, int y, int m, int n, int c){
	if ((x >= 0) && (x < m) && (y >= 0) && (y < n)){
		if (!visited[x][y]){
			visited[x][y] = true;
			if (arrChange[x][y] == c){
				arrChange[x][y] = 0;
				// Flood-fill
				jawbreakerRuntuh(x+1, y, m, n, c);
				jawbreakerRuntuh(x, y+1, m, n, c);
				jawbreakerRuntuh(x-1, y, m, n, c);
				jawbreakerRuntuh(x, y-1, m, n, c);
			}
		}
	}
}

int CariTerbesarKedua(int m, int n){
	count = 0;
	int max = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (arrChange[i][j] != 0){
				jawbreaker(i, j, m, n, arrChange[i][j]);
				if (max < count){
					max = count;
				}
				memset(visited, 0, sizeof(visited));
				count = 0;
			}
		}
	}
	return max;
}

void Runtuh /*From jawbreaker III */(int m, int n){
	for (int j = 0; j < n; j++){
		for (int i = m-1; i >= 0; i--){
			if (arrChange[i][j] == 0){
				
				// Identify how many zeros
				int countZero = 0;
				int index = i;
				do {
					countZero++;
					index--;
				} while (arrChange[index][j]==0);
				
				// Runtuh
				while (index >= 0){
					
					// Swap
					int temp = arrChange[index][j];
					arrChange[index][j] = 0;
					arrChange[index + countZero][j] = temp;
					
					index--;
				}
			}
		}
	}
}

void pindahArray (int m, int n) {
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			arrChange[i][j] = arr[i][j];
		}
	}
}

int jawbreaker4 (int x, int y, int m, int n){
	
	pindahArray(m, n);
	count = 0;
	jawbreaker(x, y, m, n, arrChange[x][y]);
	int countTemp = count;
	countTemp *= (countTemp - 1);
	memset(visited, 0, sizeof(visited));
	jawbreakerRuntuh(x, y, m, n, arrChange[x][y]);
	Runtuh(m, n);
	int countTemp2 = CariTerbesarKedua(m, n);
	countTemp2 *= (countTemp2 - 1);
	countTemp += countTemp2;
	return countTemp;
	
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
	int max = jawbreaker4(0, 0, m, n);
	
	//Execute
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			
			// Already stored in max variable
			if ((i == 0) && (j == 0)){
				continue;
			}
			
			// Pruning
			if ((i != 0) && (j != 0)){
				if ((arr[i-1][j] == arr[i][j]) || (arr[i][j-1] == arr[i][j])){
					continue;
				}
			}
			
			int temp = jawbreaker4(i, j, m, n);
			if (max < temp){
				max = temp;
			}
			
		}
	}
	
	cout << max << endl;
	
	return 0;
}
