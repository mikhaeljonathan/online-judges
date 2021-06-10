#include <stdio.h>
#include <math.h>
using namespace std;

int main ()
{
	long long int a,b,n;
	scanf("%lld",&n);
	double res = sqrt((double)n+1.0);
	long long int temp = floor(res);
	a = (temp-1)*(temp-1)+2*(temp-1);
	if (n==a)
		b=a;
	else
		b = temp*temp+2*temp;
	printf("%lld %lld\n",a,b);
}
