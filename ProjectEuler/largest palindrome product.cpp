#include <cstdio>
using namespace std;

bool palindrome (long long int n)
{
	int digit=0;
	long long int ns=n;
	while (ns!=0)
	{
		ns/=10;
		digit++;
	}
	int num[digit];
	for (int temp=digit-1; temp>=0; temp--)
	{
		num[temp]=n%10;
		n/=10;
	}
	int a=0;
	int b=digit-1;
	bool pal=true;
	while ((a<=b)&&(pal))
	{
		if (num[a]!=num[b])
		{
			pal=false;
		}
		a++;
		b--;
	}
	return pal;
}

int main ()
{
	long long int res,max;
	max=0;
	for (long int a=100; a<=999; a++)
	{
		for (long int b=100; b<=999; b++)
		{
			res=a*b;
			if ((palindrome(res))&&(res>=max))
			{
				max=res;
			}

		}
	}
	printf("%lld",max);
}
