#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int m,n,o,p;
		scanf("%d %d %d %d",&m,&n,&o,&p);
		for (int a=1; a<=m; a++){
			for (int b=1; b<=n; b++)
				if ((b==p-o+a)||(b==p+o-a))
					printf("*");
				else
					printf(".");
			printf("\n");
		}
	}
	return 0;
}
