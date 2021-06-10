#include<iostream>
using namespace std;

int main (){
	long long int n;
	cin>>n;
	bool eliminated[1000000];
	long long int prime[100000];
	long long int index=1;
	for (long long int a=2; a<=1000000; a++){
		if (!eliminated[a]){
			prime[index]=a;
			long long int b=a*a;
			while (b<=1000000){
				eliminated[b]=true;
				b+=a;
			}
			index++;
		}
	}
	
	while (n--){
		long long int k;
		cin>>k;
		cout<<prime[k]<<endl;
	}

	return 0;
}
