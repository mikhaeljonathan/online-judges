#include <iostream>
using namespace std;

int main (){
	int in;
	while (cin >> in && in != 0){
		int temp = in;
		bool factors[in + 1];
		for (int i = 0; i <= in; i++) factors[i] = 0;
		int count = 0;
		for (int i = 2; i <= temp; i++){
			while (temp % i == 0){
				if (factors[i] == 0) count++;
				factors[i] = 1;
				temp /= i;
			}
		}
		cout << in << " : " << count << endl;
	}
	return 0;
}
