#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int a=1; a<=t; a++){
		int n;
		scanf("%d",&n);
		printf("Kasus #%d: ",a);
		if (n%2==0)
			printf("TIDAK CINTA\n");
		else
			printf("CINTA\n");
	}
	return 0;
}
