#include<bits/stdc++.h>
using namespace std;
int arr[15][15];

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	int total=1;
	int now=0;
	
	for(int i=0;i<n;i++){
		total = 1;
		now = arr[0][i];
		for(int j=1;j<n;j++){
			if(arr[j][i] > now){
				now = arr[j][i];
				total++;
			}
		}
		if(i!=0) printf(" ");
		printf("%d", total);
	}
	printf("\n");
	
	for(int i=0;i<n;i++){
		total = 1;
		now = arr[i][0];
		for(int j=1;j<n;j++){
			if(arr[i][j] > now){
				now = arr[i][j];
				total++;
			}
		}
		
		printf("%d\n", total);
	}
	
	return 0;
}
