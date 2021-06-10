#include <cstdio>
using namespace std;

int digits(long long n){
	int d=0;
	while (n>0){
		n/=10;
		d++;
	}
	return d;
}

bool palindrome(long long k){
	int d = digits(k);
	int num[d];
	for (int a=d-1; a>=0; a--){
		num[a] = k%10;
		k/=10;
	}
	int left=0, right=d-1;
	while (left<=right){
		if (num[left]!=num[right])
			return false;
		left++;
		right--;
	}
	return true;
}

int main (){
	long long t;
	scanf("%lld",&t);
	while (t--){
		long long k;
		scanf("%lld",&k);
		bool palin=false;
		while (!palin){
			k++;
			if(palindrome(k))
				palin=true;
		}
		printf("%lld\n",k);
	}
	return 0;
}
