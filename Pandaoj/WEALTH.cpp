#include <cstdio>
using namespace std;

int main (){
	int n;
	scanf("%d",&n);
	long long max=0;
	for (int a=0; a<n; a++){
		long long num;
		scanf("%lld",&num);
		if (num>max)
			max=num;
	}
	printf("%lld\n",max);
	return 0;
}
