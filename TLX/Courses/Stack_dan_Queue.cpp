#include <iostream>
using namespace std;

int main (){
	int n;
	cin >> n;
	int staque[30000], head, tail;
	head = 10000;
	tail = 9999;
	while (n--){
		string command;
		int num;
		cin >> command;
		if ((command == "push_front") || (command == "push_back")){
			cin >> num;
		}
		
		if (command == "push_front"){
			head--;
			staque[head] = num;
		} else if (command == "push_back"){
			tail++;
			staque[tail] = num;
		} else if (command == "pop_front"){
			head++;
		} else if (command == "pop_back"){
			tail--;
		}
	}
	for (int a = head; a <= tail; a++){
		cout << staque[a] << endl;
	}
	return 0;
}
