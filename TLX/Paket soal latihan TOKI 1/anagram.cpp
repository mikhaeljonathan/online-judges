#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isAnagram(string a, string b){
	if (a.length() != b.length()) return false;
	
	int alphaCountA[30];
	int alphaCountB[30];
	for (int i = 0; i < 30 ;i++){
		alphaCountA[i] = 0;
		alphaCountB[i] = 0;
	}
	for (int i = 0; i < a.length(); i++){
		alphaCountA[(int)a[i] - (int)'a']++;
	}
	
	for (int i = 0; i < b.length(); i++){
		alphaCountB[(int)b[i] - (int)'a']++;
	}
	
	for (int i = 0; i < 30; i++){
		if (alphaCountA[i] != alphaCountB[i]) return false;
	}
	
	return true;
}

int main (){
	int n;
	cin >> n;
	vector<string> strings;
	bool eliminated[n];
	for (int i = 0; i < n; i++){
		eliminated[i] = false;
		string temp;
		cin >> temp;
		strings.push_back(temp);
	} 
	
	sort(strings.begin(), strings.end());
	
//	for (int i = 0; i < strings.size(); i++){
//		cout << strings[i] << endl;
//	}

	vector< vector<string> > vvs;
	for (int i = 0; i < n; i++){
		if (eliminated[i]) continue;
		vector<string> vs;
		vs.push_back(strings[i]);
		eliminated[i] = true;
		for (int j = i + 1; j < n; j++){
			if (isAnagram(strings[i], strings[j])){
				vs.push_back(strings[j]);
				eliminated[j] = true;
			}
		}
		vvs.push_back(vs);
	}
	
	int res = 0;
	int idxres = 0;
	for (int i = 0; i < vvs.size(); i++){
		if (vvs[i].size() > res){
			idxres = 0;
			res = vvs[i].size();
		} 
	}
	
	if (res > 1){
		cout << res << endl;
		for (int i = 0; i < vvs[idxres].size(); i++){
			cout << vvs[idxres][i] << endl;
		}
	} else {
		cout << "TIDAK ADA" << endl;
	}
	
	
	return 0;
}
