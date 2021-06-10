#include <cstdio>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int m,n,o,p;
		scanf("%d %d %d %d",&m,&n,&o,&p);
		for (int a=0; a<m; a++){
			for (int b=0; b<n; b++)
				if ((a==o-1)||(b==p-1))
					printf("*");
				else
					printf(".");
			printf("\n");
		}
	}
	return 0;
}
