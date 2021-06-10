#include <iostream>
using namespace std;

int main (){
	string in;
	int index = 1;
	while (1){
		cin >> in;
		if (in.compare("*") == 0) break;
		printf("Case %d: %s\n", index++, (in.compare("Hajj") == 0) ? "Hajj-e-Akbar" : "Hajj-e-Asghar");
	}
}
