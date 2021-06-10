#include <stdio.h>
#include <string.h>

long long int key[100000];

int main (){
	int n;
	scanf("%d", &n);
	while (n--){
		int k;
		scanf("%d", &k); getchar();
		for (int i = 0; i < 100000; i++) key[i] = 0;
		while (k--){
			char temp[10];
			gets(temp);
			char in;
			long long int val;
			sscanf(temp, "%c %lld", &in, &val);
			key[(int)in + 128] = val;
		}
		int m;
		scanf("%d", &m); getchar();
		char in[10005];
		long long int ans = 0;
		while (m--){
			gets(in);
			int len = strlen(in);
			for (int i = 0; i < len ;i++){
				ans += key[(int)in[i] + 128];
			}
		}
		double final = ans * 1.0 / 100.0;
		printf("%.2lf$\n", final);
	}
	
	return 0;
}
