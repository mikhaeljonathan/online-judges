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

int main (){
	int k;
	string s;
	while (cin >> k >> s){
		if (k == -1 && !s.compare("*")) break;
		
		int strlength = s.length();
		
		if (k < strlength) {
			cout << "0" << endl;
			continue;
		}
		
		for (int i = 0; i < SIZE; i++) f[i] = 0;
		
		calculatePrefix(s);
		
		int res = (k - f[strlength - 1]) / (strlength - f[strlength - 1]);
		cout << res << endl;
	}
	return 0;
}
