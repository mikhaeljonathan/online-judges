#include <iostream>
using namespace std;

bool visited[25][25];
int count = 0;
int arr[25][25];

void jawbreaker (int x, int y, int m, int n, int c){
	if ((x >= 0) && (x < m) && (y >= 0) && (y < n)){
		if (!visited[x][y]){
			visited[x][y]=true;
			if (arr[x][y]==c){
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
	int b, k;
	cin >> b >> k;
	// Execute
	jawbreaker(b, k, m, n, arr[b][k]);
	cout << count*(count-1) << endl;
	
	return 0;
}
