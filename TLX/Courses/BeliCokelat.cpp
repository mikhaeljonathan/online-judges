#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool operator<(const pair<unsigned long long, unsigned long long> &a, const pair<unsigned long long, unsigned long long> &b){
	return (a.first < b.first);
}

int	main (){
	unsigned long long n, d;
	cin >> n >> d;
	vector< pair<unsigned long long, unsigned long long> > v;
	while (n--){
		unsigned long long h, b;
		cin >> h >> b;
		v.push_back(make_pair(h, b));
	}
	sort(v.begin(), v.end());
	
	unsigned long long res = 0;
	unsigned long long idx = 0;
	while (d > 0 && idx < v.size()){
		unsigned long long temp = v[idx].first * v[idx].second;
		if (temp <= d){
			res += v[idx].second;
			d -= temp;
		} else {
			for (unsigned long long _ = 0; _ < v[idx].second; _++){
				if (v[idx].first <= d){
					d -= v[idx].first;
					res++;
				} else {
					break;
				}
			}
		}
		idx++;
	}
	
	cout << res << endl;
	return 0;
}
