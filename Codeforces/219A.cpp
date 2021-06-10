#include <stdio.h>
#include <string.h>

bool test(int key[], int k){
	for (int i = 0; i < 300; i++) if (key[i] % k != 0) return false;
	return true;
}

int main () {
	int k;
	scanf("%d", &k);
	getchar();
	char s[1005];
	gets(s);
	int key[300];
	for (int i = 0; i < 300; i++){
		key[i] = 0;
	}
	int len = strlen(s);
	for (int i = 0; i < len; i++){
		key[s[i]]++;
	}
	
	if (test(key, k)) 
		for (int i = 0; i < k; i++) 
			for (char j = 'a'; j <= 'z'; j++) 
				for (int l = 1; l <= key[j]/k; l++)
					printf("%c", j);
	else printf("-1");
	printf("\n");
	return 0;
}
