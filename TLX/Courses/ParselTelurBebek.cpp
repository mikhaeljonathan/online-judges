#include<bits/stdc++.h>
using namespace std;

vector<long long> v;

long long calculate(long long x){
	long long res = 0;
	for (int i = 0; i < v.size(); i++){
		res += x / v[i];
	}
	return res;
}

int main (){
	long long n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		long long a;
		cin >> a;
		v.push_back(a);
	}
	long long l = 0;
	long long r = 2 << 20;
	long long hasil = 0;
	long long res = 0;
	while (l <= r && hasil == 0){
		long long mid = (l + r) / 2;
		if (m > calculate(mid)){
			l = mid + 1;
		} else if (m < calculate(mid)){
			r = mid - 1;
		} else {
			hasil = mid;
			res = 1;
			long long temp = hasil - 1;
			while (m == calculate(temp)){
				res++;
				temp--;
			}
			
			temp = hasil + 1;
			while (m == calculate(temp)){
				res++;
				temp++;
			}
		}
	}
	
	cout << res << endl;
	return 0;
}
