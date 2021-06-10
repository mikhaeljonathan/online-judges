#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		char c[600];
		cin>>c;
		long sum=0;
		for (int a=0; a<strlen(c); a++)
			sum+=c[a]-48;
	printf("%ld\n",sum);
	}
	
	return 0;
}

