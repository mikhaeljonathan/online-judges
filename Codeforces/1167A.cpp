#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		getchar();
		char s[n + 5];
		gets(s);
		int index = -1;
		for (int i = 0; i < n; i++){
			if (s[i] == '8'){
				index = i;
				break;
			}
		}
		if (index == -1){
			printf("NO\n");
		} else {
			index = n - index;
			if (index >= 11) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
