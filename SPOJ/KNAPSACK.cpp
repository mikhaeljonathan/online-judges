#include <cstdio>
#include <algorithm>
using namespace std;
long long arr[2005][2005];
long long result;

long long knapsack (int size[],long long val[], int n, int s){
	if (arr[n][s]!=NULL)
		return arr[n][s];
	if ((n==0)||(s==0))
		result=0;
	else if (size[n]>s)
		result=knapsack(size,val,n-1,s);
	else {
		long long temp1 = knapsack(size,val,n-1,s);
		long long temp2 = val[n]+knapsack(size,val,n-1,s-size[n]);
		result = max(temp1,temp2);
	}
	arr[n][s]=result;
	return result;
}

int main (){
	int s,n;
	scanf("%d %d",&s,&n);
	int size[n+1];
	long long val[n+1];
	for (int a=1; a<n+1; a++)
		scanf("%d %lld",&size[a],&val[a]);
	long long res = knapsack(size,val,n,s);
	printf("%lld\n",res);
	return 0;
}
