#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int board[10][10];
int xglobal, yglobal;
vector< vector<int> > ans;

int check(int x, int y){
	int i, j;
	
	//up
	for (i = x - 1; i >= 0; i--){
		if (board[i][y]) return 0;
	}
	
	//upleft
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
		if (board[i][j]) return 0;
	}
	
	//upright
	for (i = x - 1, j = y + 1; i >=0 && j < 8; i--, j++){
		if (board[i][j]) return 0;
	}
	
	return 1;
}

void queen(int x, int y, vector<int> temp){
	if (x == 7) {
		if (check(x, y)){
			if (temp[yglobal] == xglobal){
				ans.push_back(temp);
			}
		}
		return;
	}
	if (check(x, y)){
		board[x][y] = 1;
		for (int i = 0; i < 8; i++){
			temp.push_back(i);
			queen(x + 1, i, temp);
			temp.pop_back();
		}
		board[x][y] = 0;
	}
}

void nqueen(){
	for (int i = 0; i < 8; i++){
		vector<int> temp;
		temp.push_back(i);
		queen(0, i, temp);
	}
}

int main (){
	int n;
	cin >> n;
	while (n--){
		getchar();
		getchar();
		
		ans.clear();
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				board[i][j] = 0;
		
		cin >> xglobal >> yglobal;
		xglobal--;
		yglobal--;
		
		nqueen();
		
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl;
		cout << endl;
		
		for (int i = 0; i < ans.size(); i++){
			printf("%2d     ", i + 1);
			for (int j = 0; j < ans[i].size(); j++){
				cout << " " << ans[i][j] + 1;
			}
			cout << endl;
		}
		
		if (n != 0) cout << endl;
	
	}
	return 0;
}
