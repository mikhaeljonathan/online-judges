#include <cstdio>
#include <algorithm>
using namespace std;

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int n;
		scanf("%d",&n);
			
		int arr[n][3];
		for (int b=0; b<n; b++)
			scanf("%d %d %d",&arr[b][0],&arr[b][1],&arr[b][2]);
		
		for (int c=1; c<n; c++)
			for (int d=0; d<3; d++)
				if (d==0)
					arr[c][d]+=min(arr[c-1][1],arr[c-1][2]);
				else if (d==1)
					arr[c][d]+=min(arr[c-1][0],arr[c-1][2]);
				else
					arr[c][d]+=min(arr[c-1][0],arr[c-1][1]);
		int res=arr[n-1][0];
		for (int e=1; e<3; e++)
			if (res>arr[n-1][e])
				res=arr[n-1][e];
		printf("%d\n",res);
	}
	return 0;
}
