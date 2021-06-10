#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		bool days[n + 1];
		for (int i = 0; i <= n; i++){
			days[i] = false;
		}
		int p;
		scanf("%d", &p);
		while (p--){
			int h;
			scanf("%d", &h);
			for (int j = h; j <= n; j+=h){
				if (j % 7 != 6 && j % 7 != 0) days[j] = true;
			}
		}
		
		int counter = 0;
		
		for (int i = 1; i <= n; i++){
			if (days[i]) counter++;
		}
		
		printf("%d\n", counter);
	}
	return 0;
}
