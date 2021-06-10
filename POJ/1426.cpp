#include <iostream>
#include <vector>
using namespace std;

long long find (int x){
	long long ret = 1;
	vector<long long> v;
	v.push_back(1);
	while (true){
		ret = ret * 10;
		if (ret % x == 0) return ret;
		
		v.push_back(ret);
		int size = v.size();
		for (int i = 0; i < size - 1; i++){
			long long temp = ret + v.at(i);
			if (temp % x == 0) return temp;
			v.push_back(temp);
		}
	}
}

int main (){
	int x;
	while (cin >> x){
		if (x == 0) break;
		cout << find(x) << endl;
	}
	return 0;
}
