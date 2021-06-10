#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	for (int tc=1; tc<=t; tc++){
		int n;
		scanf("%d",&n);
		int sum=0,sum2=0,sum3=0;
		for (int a=0; a<n; a++){
			char c[20];
			cin>>c;
			if (strlen(c)==4)
				sum++;
			else if (strlen(c)==5)
				sum2++;
			else if (strlen(c)==6)
				sum3++;
		}
		printf("Case #%d: %d %d %d\n",tc,sum,sum2,sum3);
	}
	return 0;
}
