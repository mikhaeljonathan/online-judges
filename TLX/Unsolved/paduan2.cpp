#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> constraint;
vector<int> finalconstraint;
int sound[20000];
int jump;
int m;

vector<int> modify(vector<int> constraint, int index){
	constraint.push_back(sound[index]);
	return constraint;
}

void execute (int n, int times, int index, vector<int> constraint){
	if (n == 1){
		for (int a = 0; a < constraint.size(); a++){
			finalconstraint.push_back(constraint.at(a)); // copy
		}
	} else {
		if (times != 0){ // possible to take big
			if (sound[index + jump] == sound[index + jump - 1]){
				execute(n - 1, times, index + jump - 1, modify(constraint, index + jump - 1)); // take small
			} else {
				execute(n - 1, times - 1, index + jump, modify(constraint, index + jump)); // take big
			}
		
		} else { // take small instead
			execute(n - 1, times, index + jump - 1, modify(constraint, index + jump - 1)); // take small
		}
	}
}

int main (){
	//input
	cin >> m;
	for (int a = 0; a < m; a++){
		cin >> sound[a];
	}
	sort(sound, sound + m);
	int n;
	cin >> n;
	
	//initialize
	jump = m / n + 1;
	int times = m % n; // how many times we can do jump with m / n + 1
	
	// execute
	execute(n, times, 0, constraint);
	
	// output
	for (int a = 0; a < finalconstraint.size(); a++){
		cout << finalconstraint.at(a);
		if (a != finalconstraint.size() - 1){
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
