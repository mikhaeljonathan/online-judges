#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	long long int res1,res2,res3;
	res1=0;res2=0;
	for (int a=1; a<=100; a++){
		res1+=pow(a,2);
	}
	for (int b=1; b<=100; b++)
	{
		res2+=b;
	}
	res2 = pow(res2,2);
	res3 = max(res1,res2)-min(res1,res2);
	printf("%lld",res3);
	return 0;
}
