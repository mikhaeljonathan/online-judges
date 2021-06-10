#include <cstdio>
using namespace std;

int main ()
{
	long long int num[100000];
	num[0]=1;
	num[1]=2;
	long long int res=0;
	long long int index=2;
	bool exceed=false;
	while (!exceed)
	{

		num[index]=num[index-1]+num[index-2];	
		if (num[index]>=4000000)
		{
			exceed = true;
		}
		if ((num[index]%2==0)&&(!exceed))
			res+=num[index];
		index++;
	}
	printf("%lld",res+2);
	return 0;	
}
