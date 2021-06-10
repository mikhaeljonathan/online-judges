#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int x, y, n, m;
int maze[105][105];
vector< pair<int, int> > graph[105][105];

int bfs(){
	queue< pair<int, int> > q;
	int visitTime[105][105];
	memset(visitTime, 0, sizeof(visitTime));
	
	pair<int, int> temp;
	temp.first = x;
	temp.second = y;
	q.push(temp);
	visitTime[x][y] = 1;
	if ((x == 0) || (x == n - 1) || (y == 0) || (y == m - 1)){
		return visitTime[x][y];
	}
	
	while (!q.empty()){
		pair<int, int> current = q.front();
		q.pop();
		for (int a = 0; a < graph[current.first][current.second].size(); a++){
			pair <int, int> temp = graph[current.first][current.second].at(a);
			if (visitTime[temp.first][temp.second] == 0){
				q.push(temp);
				visitTime[temp.first][temp.second] = visitTime[current.first][current.second] + 1;
				if ((temp.first == 0) || (temp.first == n - 1) || (temp.second == 0) || (temp.second == m - 1)){
					return visitTime[temp.first][temp.second];
				}
			}
		}
	}
}

int main (){
	// Input
	cin >> n >> m;
	for (int a = 0; a < n; a++){
		for (int b = 0; b < m; b++){
			cin >> maze[a][b];
		}
	}
	cin >> x >> y;
	x--;
	y--;
	
	// Initialize graph
	for (int a = 0; a < n; a++){
		for (int b = 0; b < m; b++){
			// up
			if ((a != 0) && (maze[a - 1][b] == 0)){
				pair <int, int> temp;
				temp.first = a - 1;
				temp.second = b;
				graph[a][b].push_back(temp);
			}
			// right
			if ((b != m - 1) && (maze[a][b + 1] == 0)){
				pair <int, int> temp;
				temp.first = a;
				temp.second = b + 1;
				graph[a][b].push_back(temp);
			}
			// down
			if ((a != n - 1) && (maze[a + 1][b] == 0)){
				pair <int, int> temp;
				temp.first = a + 1;
				temp.second = b;
				graph[a][b].push_back(temp);
			}
			// left
			if ((b != 0) && (maze[a][b - 1] == 0)){
				pair <int, int> temp;
				temp.first = a;
				temp.second = b - 1;
				graph[a][b].push_back(temp);
			}
		}
	}
	
	int result = bfs();
	cout << result << endl;
	/*
	for (int a = 0; a < n; a++){
		for (int b = 0; b < m; b++){
			cout << "graph["<< a <<"][" << b<<"] = ";
			for (int c = 0; c < graph[a][b].size(); c++){
				cout << "<" << graph[a][b].at(c).first <<", "<<graph[a][b].at(c).second <<"> ";
			}
			cout << endl;
		}
		cout << endl;
	}
	*/
	return 0;
}
