#include <stdio.h>
#include <string.h>

int main (){
	int n, t;
	scanf("%d %d", &n, &t);
	char in[n + 1];
	scanf("%s", in);
	int len = strlen(in);
	int boysIndexes[n + 1];
	
	
	while (t--){
		int idx = 0;
		for (int i = 0; i < len; i++){
			if (in[i] == 'B' && i + 1 < len && in[i + 1] == 'G') {
				boysIndexes[idx++] = i;
			}
		}
		for (int i = 0; i < idx; i++){
			in[boysIndexes[i]] = 'G';
			in[boysIndexes[i] + 1] = 'B';
		}
	}
	printf("%s\n", in);
	return 0;
}
