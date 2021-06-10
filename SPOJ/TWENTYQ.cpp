#include <stdio.h>
#include <string.h>
#define LIMIT 1 << 12

int m,n;
char codes[130][13];
int memo[LIMIT][LIMIT];
int mask[130];

int min(int a,int b){
	return (a < b)?a:b;
}

int max(int a,int b){
	return (a > b)?a:b;
}

int tsp(int maskQ,int maskA){
	
	if(maskQ == ((1<<m)-1))return memo[maskQ][maskA] = 0;
	if(memo[maskQ][maskA]!=-1)return memo[maskQ][maskA];
	
	int count = 0;
	for(int i = 0;i < n;i++){
		if((mask[i] & maskQ) == maskA)count++;
		if(count >1)break;
	}
	if(count == 1)	return memo[maskQ][maskA] = 0;
	int ans = 1<<30;
	for(int i = 0;i < m;i++){
		if((maskQ & (1 << i)) == 0){
			ans = min(ans, max(tsp((maskQ | (1 << i)), maskA)
					, tsp((maskQ | (1<<i)) ,maskA | (1 << i))) + 1);
		}
	}
	return memo[maskQ][maskA] = ans;
}

int main(){
	
	while(scanf("%d %d",&m,&n)){
		if(m==0&&n==0)break;
		getchar();
		for(int i = 0;i < n;i++){
			scanf("%s",codes[i]);getchar();
		}
		for(int i = 0; i< 130;i++){
			mask[i] = 0;
		}
		for(int i = 0;i< (1 <<(m+1));i++){
			for(int j = 0;j<(1 << (m+1));j++){
				memo[i][j] = -1;
			}
		}
		
		int output = 0;
		if(n > 1){
			//convert string to bitshift
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if(codes[i][j] == '1'){
						mask[i] = (mask[i] | (1<<j));
					}
				}
			}
			output = tsp(0,0);
		}
		printf("%d\n",output);
		
	}
	
	
	
	return 0;
}

