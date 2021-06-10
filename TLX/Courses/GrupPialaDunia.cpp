#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> arr;
int n;

// if n = 4, then <0,1>, <0,2>, <0.3>, <1,2>, <1,3>, <2,3>, <-1,3>
pair<int, int> match (pair<int, int> battle) {
	if (battle.second == n - 1){
		if (battle.first == n - 2){
			battle.first = -1;
		} else {
			battle.first++;
			battle.second = battle.first + 1;
		}
	} else {
		battle.second++;
	}
	return battle;
}

//use vector bcz we cant return an array in a function
vector<int> modify (vector<int> score, int indicator, pair<int, int> battle){
	if (indicator == 2){
		score.at(battle.first) += 3;
	} else if (indicator == 1) {
		score.at(battle.first) += 1;
		score.at(battle.second) += 1;
	} else if (indicator == 0) {
		score.at(battle.second) += 3;
	}
	return score;
}

//check whether the score and arr same or not
bool same (vector<int> score){
	for (int a = 0; a < n; a++){
		if (arr.at(a) != score.at(a)){
			return false;
		}
	}
	return true;
}


bool possible (pair<int, int> battle, vector<int> score) {
		
	// Base case
	if (battle.first == -1){
		if (same(score)){
			return true;
		} else {
			return false;
		}
	}
	
	// reccurence (if one of them true, the others are true)
	bool option1 = possible(match(battle), modify(score, 2, battle));
	
	bool option2 = possible(match(battle), modify(score, 1, battle));
	
	bool option3 = possible(match(battle), modify(score, 0, battle));
	
	return (option1 || option2 || option3);

}

int main (){
	// Input
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int a = 0; a < n; a++){
			int input;
			cin >> input;
			arr.push_back(input);
		}
		
		// Initialize
		vector<int> score;
		for (int a = 0; a < n; a++){
			score.push_back(0);
		}
	
		pair<int, int> battle;
		battle.first = 0;
		battle.second = 1;
		
		// Output
		if (possible(battle, score) || possible(battle, score) || possible(battle, score)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
		// clearing vectors
		arr.clear();
		score.clear();
	}
	return 0;
}
