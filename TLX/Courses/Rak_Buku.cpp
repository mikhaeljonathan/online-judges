#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	// Input
	int n;
	long long int b;
	cin >> n >> b;
	vector <int> h;
	for (int a = 0; a < n; a++){
		int temp;
		cin >> temp;
		h.push_back(temp);
	}
	
	// Sort the vector
	sort(h.begin(), h.end());
	
	// Execute
	int count = 0;
	int index = h.size() - 1;
	while (b > 0){
		b -= h.at(index);
		count++;
		index--;
	}
	
	// Output
	cout << count << endl;
	return 0;
}
