#include <stdio.h>

int main (){
	int k;
	scanf("%d", &k);
	while (k != 0){
		int s[k];
		for (int i = 0; i < k; i++){
			scanf("%d", &s[i]);
		}
		
		for (int i = 0; i < k - 5; i++)
			for (int j = i + 1; j < k - 4; j++)
				for (int l = j + 1; l < k - 3; l++)
					for (int m = l + 1; m < k - 2; m++)
						for (int n = m + 1; n < k - 1; n++)
							for (int o = n + 1; o < k; o++)
								printf("%d %d %d %d %d %d\n", s[i], s[j], s[l], s[m], s[n], s[o]);
		
		scanf("%d", &k);	
		if (k != 0)	puts("");	
	}
	
	return 0;
}
