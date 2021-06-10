#include <iostream>
using namespace std;

int main (){
	int n;
	cin >> n;
	while (n--){
		string in;
		cin >> in;
		if (in.length() == 5) puts("3");
		else {
			int one = 0;
			int two = 0;
			string test[2] = {"one", "two"};
			for (int i = 0; i < 3; i++){
				if (test[0][i] != in[i]) one++;
				if (test[1][i] != in[i]) two++;
			}
			if (one <= 1) puts("1");
			if (two <= 1) puts("2");
		}
	}
	return 0;
}
