#include <stdio.h>
#include <string.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		long long n;
		scanf("%lld", &n);
		n *= 567;
		n /= 9;
		n += 7492;
		n *= 235;
		n /= 47;
		n -= 498;
		char res[20];
		sprintf(res, "%lld", n);
		int length = strlen(res);
		printf("%c\n", res[length - 2]);
	}
	return 0;
}
