#include <cstdio>
#include <cmath>
using namespace std;

int main (){
	int a,b;
	a=1;b=2;
	long long res;
	long long temp;
	long long finalres;
	bool ifoundyou=false;
	while ((a<=500)&&(!ifoundyou))
	{
		while ((b<=500)&&(!ifoundyou))
		{
			res = pow(a,2)+pow(b,2);
			double temp2 = sqrt(res);
			temp = floor(temp2);
			if ((temp2-temp==0.0)&&(a+b+temp==1000))
			{
				ifoundyou=true;
				finalres=a*b*temp;
				printf ("%d %d %lld\n",a,b,temp);
			}
			b++;
		}
		a++;
		b=a+1;
	}
	printf("%lld",finalres);
}
