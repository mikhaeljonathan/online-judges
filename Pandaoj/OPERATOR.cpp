#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int k=1; k<=t; k++){
		long a,b,c;
		scanf("%ld %ld %ld",&a,&b,&c);
		double z= (double)a/(double)b;
		if (a+b==c)
			printf("Kasus #%d: +",k);
		else if (a*b==c)
			printf("Kasus #%d: *",k);
		else if (a-b==c)
			printf("Kasus #%d: -",k);
		else if (z==c)
			printf("Kasus #%d: /",k);	
		else
			printf("Kasus #%d: TIDAK ADA SOLUSI",k);
		printf("\n");
	}	
	return 0;
}
