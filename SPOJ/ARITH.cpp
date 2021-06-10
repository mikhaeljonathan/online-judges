#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

void f(){
	char c[1005];
	cin>>c;
	int a=0;
	while ((c[a]!='+')&&(c[a]!='-')&&(c[a]!='*')) //detect the operator
		a++;
	int indexnum2=a+1; //divide between the two numbers
	int temp = strlen(c)-a-1;
	char num1[a],num2[temp]; //make two arrays for two numbers
	for (int b=0; b<a; b++){
		num1[b]=c[b];
	}
	for (int d=0; d<temp; d++){
		num2[d]=c[indexnum2];
		indexnum2++;
	}
	cout<<num1<<" "<<num2<<endl;
/*	switch(c[a]){
		case '+':{
			int temp2=max(a,temp)+1;
			int res[temp2]; //make arrays for result
			for (int e=temp2-1; e>=0; e++){
				res[e] = num1[a-1]+num2[temp-1];
			}
			break;
		}
		case '-':{
			
			break;
		}
		case '*':{
			
			break;
		}
	}*/
}

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		f();
	}
	return 0;
}
