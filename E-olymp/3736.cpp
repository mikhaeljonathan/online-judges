#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sack{
	public:
		int v;
		int w;
		double val;
};

bool operator<(Sack const &a, Sack const &b){
	return (a.val > b.val);
}

int main (){
	int n, w;
	cin >> n >> w;
	vector<Sack> v;
	
	for (int i = 0; i < n; i++){
		Sack s;
		cin >> s.v >> s.w;
		s.val = (double)s.v / (double)s.w;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end());
	
	double res = 0.0;
	
	for (int i = 0; i < v.size(); i++){
		
		if (v.at(i).w <= w){
			res += v.at(i).v;
			w -= v.at(i).w;
		} else {
			res += ((double)v.at(i).val * (double)w);
			break;
		}
	}
	
	printf("%.3lf\n", res);
	return 0;
}
