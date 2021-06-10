#include <stdio.h>
using namespace std;

int main ()
{
	long int n;
	scanf("%ld",&n);
	int digit=0;
	if (n==0)
		digit=1;
	else
	{
		while (n!=0)
		{
			n/=10;
			digit++;
		}
	}
	printf("%d\n",digit);
}
