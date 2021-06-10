#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	string in;
	cin >> in;
	int counta = 0;
	int temp = 0;
	for (int i = 0; i < in.length(); i++){
		if (in[i] == 'a'){
			temp++;
			counta = max(counta, temp);
		} else {
			temp = 0;
		}
	}
	for (int i = 0; i < counta + 1; i++) {
		cout <<"a";
	}
	cout << endl;
	return 0;
}
