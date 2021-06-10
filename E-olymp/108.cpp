#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int maximum = max(max(a,b),max(b,c));
	int minimum = min(min(a,b),min(b,c));
	if ((a!=maximum)&&(a!=minimum))
		printf("%d",a);
	else if ((b!=maximum)&&(b!=minimum))
		printf("%d",b);
	else
		printf("%d",c);
	printf("\n");
	return 0;
}
