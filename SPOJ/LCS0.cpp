#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long memo[23000][23000];

long f(char a[],char b[],long m, long n){
	if (m<23000&n<23000){
		if (memo[m][n]!='\0')
			return memo[m][n];
	}
	long res;
	if (m==0||n==0)
		return 0;
	else if (a[m-1]==b[n-1])
		res = 1+f(a,b,m-1,n-1);
	else {
		long temp1 = f(a,b,m,n-1);
		long temp2 = f(a,b,m-1,n);
		res = max(temp1,temp2);
	}
	if (m<23000&&n<23000)
		memo[m][n]=res;
	return res;
}

int main (){
	char a[50005];
	char b[50005];
	cin>>a;
	cin>>b;
	long m=strlen(a);
	long n=strlen(b);
	cout<<f(a,b,m,n);
	return 0;
}
