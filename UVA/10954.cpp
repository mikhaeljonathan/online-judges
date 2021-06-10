#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main (){
	int n;
	while (cin >> n){
		if (n == 0) break;
		priority_queue<int, vector<int>, greater <int> > pq;
		while (n--){
			int x;
			cin >> x;
			pq.push(x);
		}
		
		long long res = 0;
		while (pq.size() != 1){
			long long temp = pq.top();
			pq.pop();
			temp += pq.top();
			pq.pop();
			
			res += temp;
			pq.push(temp);
		}
		
		cout << res << endl;
	}
	return 0;
}
