#include <cstdio>
using namespace std;

int main ()
{
	long long int res=0;
	for (int n=1; n<1000; n++)
	{
		if ((n%3==0)||(n%5==0))
		{
			res+=n;
		}
	}
	printf("%ld",res);
	return 0;
}
