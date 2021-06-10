#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > res;

void generateAns(vector<int> v, int x){
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0) {
			if (v.size() > 0 && i < v.at(v.size() - 1)) continue; //to prevent double permutation
			v.push_back(i);
			
			generateAns(v, x / i);
			
			v.push_back(x / i);
			res.push_back(v);
			v.pop_back(); //to delete the complement
			v.pop_back(); //to delete current i
		}
	}
}

int main (){
	int x;
	while(cin >> x){
		if (x == 0) break;
		
		res.clear();
		vector<int> v;
		generateAns(v, x);
		
		cout << res.size() << endl;
		
		for (int i = 0; i < res.size(); i++){
			for (int j = 0; j < res.at(i).size(); j++){
				if (j != 0) cout << " ";
				cout << res.at(i).at(j);
			}
			cout << endl;
		}
		
	}
	return 0;
}
