#include <stdio.h>
#include <string.h>

int main () {
	int t;
	scanf("%d", &t);
	getchar();
	int key[300];
	for (char i = 'a'; i <= 'o'; i++){
		key[i] = (i - 'a') % 3 + 1;
	}
	
	key['p'] = 1;
	key['q'] = 2;
	key['r'] = 3;
	key['s'] = 4;
	
	key['t'] = 1;
	key['u'] = 2;
	key['v'] = 3;
	
	key['w'] = 1;
	key['x'] = 2;
	key['y'] = 3;
	key['z'] = 4;
	
	key[' '] = 1;
	
	for (int i = 1; i <= t; i++){
		char x[105];
		gets(x);
		long long res = 0;
		int len = strlen(x);
		for (int j = 0; j < len; j++){
			res += key[x[j]];
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}
