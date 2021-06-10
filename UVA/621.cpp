#include <bits/stdc++.h>
using namespace std;

int main (){
	int t;
	cin >> t;
	while (t--){
		string in;
		cin >> in;
		int len = in.length();
		if (in.compare("1") == 0 || in.compare("4") == 0 || in.compare("78") == 0) puts("+");
		else if (in[len - 1] == '5' && in[len - 2] == '3') puts("-");
		else if (in[0] == '9' && in[len - 1] == '4') puts("*");
		else puts("?");
	}
	return 0;
}
