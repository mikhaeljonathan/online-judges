#include <iostream>
#include <cstring>
using namespace std;

int main (){
	int n;
	cin>>n;
	char word[n];
	cin>>word;
	int m;
	cin>>m;
	for (int a=-1; a<m; a++){
		char sentence[1000];
		gets(sentence);
		for (int b=0; b<strlen(sentence); b++){
			for (int c=0; c<n; c++){
				if (sentence[b]==word[c]){
					if (c!=n-1)
						sentence[b]=word[c+1];
					else
						sentence[b]=word[0];
					break;
				}
			}
		}
		for (int d=0; d<strlen(sentence); d++){
			cout<<sentence[d];
		}
		if (a!=-1)
			cout<<endl;
	}
	return 0;
}
