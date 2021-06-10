#include <iostream>
using namespace std;

bool subseq(string s, string t){	
	int idx = 0;
	for (int i = 0; i < t.length(); i++){
		if (t[i] == s[idx]){
			idx++;
		}
		if (idx == s.length()) return true;
	}
	
	return false;
}

int main (){
	string s, t;
	while (cin >> s >> t){
		if (subseq(s, t)) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
	return 0;
}
