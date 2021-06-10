#include <cstdio>
using namespace std;

int main (){
	long long n=1000000;
	long long max=0;
	long long temp;
	while (n>0)
	{
		long long term=0;
		long long nt=n;
		while (nt!=1)
		{
			if (nt%2==0){
				nt/=2;
			}
			else {
				nt = 3*nt+1;
			}
			term++;
		}
		term--;
		if (term>max) {
			max = term;
			temp = n;
		}
		n--;
	}
	printf("%lld",temp);
	return 0;
}
