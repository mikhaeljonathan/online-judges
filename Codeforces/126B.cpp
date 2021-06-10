#include <iostream>
#define SIZE 1000005
using namespace std;

int f[SIZE];

void calculatePrefix(string s){
	
	int len = 0;
	f[len] = 0;
	int i = 1;
	
	int strlength = s.length();
	
	while (i < strlength){
		if (s[i] == s[len]){
			len++;
			f[i] = len;
			i++;
		} else {
			if (len != 0){
				len = f[len - 1];
			} else {
				f[i] = 0;
				i++;
			}
		}
	}
	
}

bool check(string x){
	int len = x.length();
	int prefixsuffixlen = f[len - 1];
	if (prefixsuffixlen == 0) return false;
	
	int idx = f[f[len - 1] - 1];
	
	for (int i = 0; i < len - 1; i++){
		if (f[i] == prefixsuffixlen){
			idx = f[i];
		}
	}
	
	if (idx == 0) return false;
	for (int i = 0; i < idx; i++){
		cout << x[i];
	}
	cout << endl;
	
	return true;
}

int main () {
	string x;
	cin >> x;
	
	calculatePrefix(x);
	
	int len = x.length() - 1;
	bool mid = false;
	for (int i = len - 1; i >= 0; i--){
		if (f[i] == f[len]){
			mid = true;
			break;
		}
	}

	if (!check(x)){
		cout << "Just a legend" << endl;
	}
	
	return 0;
}
