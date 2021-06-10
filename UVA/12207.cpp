#include <iostream>
#include <deque>
using namespace std;

int main (){
	int p, c;
	int cases = 1;
	while (cin >> p >> c){
		if (p == 0 && c == 0) break;
		deque<int> q;
		for (int i = 1; i <= p; i++){
			q.push_back(i);
			if (i == 1005) break;
		}
			
		cout << "Case " << cases++ << ":" << endl;
		 
		while (c--){
			char com;
			cin >> com;
			if (com == 'N'){
				cout << q.front() << endl;
				int temp = q.front();
				q.pop_front();
				q.push_back(temp);
			} else {
				int x;
				cin >> x;
				deque<int>::iterator it;
				int found = 0;
				for (it = q.begin(); it != q.end(); ++it){
					if (*it == x) {
						found = 1;
						break;
					}
				}
				
				if (found) q.erase(it);
				q.push_front(x);
			}
			
		}
	}
	return 0;
}
