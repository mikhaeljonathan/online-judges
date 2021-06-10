#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> constraint;

void execute (int sound[], int n, int jump, int times, int index){
	if (n == 1){
		return;
	} else {
		if (times != 0){
			if (sound[index + jump] != sound[index + jump - 1]){
				constraint.push_back(sound[index + jump]);
				execute (sound, n - 1, jump, times - 1, index + jump);
			} else{
				constraint.push_back(sound[index + jump]);
				execute (sound, n - 1, jump, times, index + jump - 1);
			}
		} else {
			constraint.push_back(sound[index + jump - 1]);
			execute (sound, n - 1, jump, times, index + jump - 1);
		}
	}
}

int main (){
	//input
	int m;
	cin >> m;
	int sound[m];
	for (int a = 0; a < m; a++){
		cin >> sound[a];
	}
	sort(sound, sound + m);
	int n;
	cin >> n;
	
	//initialize
	int jump = m / n + 1;
	int times = m % n; // how many times we can do jump with m / n + 1
	
	// execute
	execute(sound, n, jump, times, 0);
	
	// output
	for (int a = 0; a < constraint.size(); a++){
		cout << constraint.at(a);
		if (a != constraint.size() - 1){
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
