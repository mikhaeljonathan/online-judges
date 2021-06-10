#include<iostream>
#include<vector>
using namespace std;

vector<string> strings;
string pat;

void printans(string temp, int len){
	if (len == pat.length()){
		cout << temp << endl;
		return;
	}
	
	if (pat[len] == '#'){
		int stringssize = strings.size();
		for (int i = 0; i < stringssize; i++){
			printans(temp + strings[i], len + 1);
		}
	} else {
		for (int i = 0; i < 10; i++){
			char _ = '0';
			_ += i;
			printans(temp + _, len + 1);
		}
	}
}

int main (){
	int n;
	while (cin >> n){
		strings.clear();
		while (n--){
			string in;
			cin >> in;
			strings.push_back(in);
		}
		int m;
		cin >> m;
		cout << "--" << endl;
		while (m--){
			cin >> pat;
			string temp = "";
			printans(temp, 0);
		}
	}
	return 0;
}
