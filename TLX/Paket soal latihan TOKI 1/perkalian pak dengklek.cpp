#include <stdio.h>
#include <string.h>
int main (){
	char a[15], b[15];
	scanf("%s %s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b);
	long long res = 0;
	for (int i = 0; i < lena; i++){
		for (int j = 0; j < lenb; j++){
			res += (int)(a[i] - '0') * (int)(b[j] - '0');
		}
	}
	printf("%lld\n",res);
	return 0;
}
