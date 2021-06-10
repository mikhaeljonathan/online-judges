#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int a=1; a<=t; a++){
		int n;
		scanf("%d",&n);
		long long res=0;
		if (n%2==0)
			res = pow((floor(n/2)-1),2);
		else 
			res = floor(n/2)*(floor(n/2)-1);
		printf("Kasus #%d: %lld\n",a,res);
	}
	return 0;
}
