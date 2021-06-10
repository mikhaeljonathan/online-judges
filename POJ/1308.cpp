#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

bool isTree(vector< pair<int, int> > conn){
	set<int> s1;
	set<int> s2;
	
	for (int i = 0; i < conn.size(); i++){
		if (s2.count(conn.at(i).second) > 0) return false;
		s1.insert(conn.at(i).first);
		
		if (conn.at(i).first == conn.at(i).second) return false;
		s2.insert(conn.at(i).second);
	}
	
	int x = 0;
	set<int>::iterator it;
	for (it = s1.begin(); it != s1.end(); ++it){
		if (s2.count(*it) == 0) x++;
	}
	if (x != 1) return false;
	return true;
}

int main (){
	int a, b;
	int cases = 1;
	while (cin >> a >> b){
		vector< pair<int, int> > conn;
		if (a < 0 && b < 0) break;
		
		//first pair
		pair<int, int> temp;
		temp.first = a;
		temp.second = b;
		conn.push_back(temp);
		
		if (a == 0 && b == 0) {
			printf("Case %d is a tree.\n", cases++);
			continue;
		}
		
		int x, y;
		while (cin >> x >> y){
			if (x == 0 && y == 0) break;
			pair<int, int> temp;
			temp.first = x;
			temp.second = y;
			conn.push_back(temp);
		}
		printf("Case %d %s\n", cases++, isTree(conn) ? "is a tree." : "is not a tree.");
	}
	return 0;
}
