#include <stdio.h>
#include <string.h>

bool available(int key[]){
	if (key['B'] > 0 && key['u'] > 1 && key['l'] > 0 && key['b'] > 0 && key['a'] > 1 && key['s'] > 0 && key['r'] > 0){
		key['B']--;
		key['u']-=2;
		key['l']--;
		key['b']--;
		key['a']-=2;
		key['s']--;
		key['r']--;
		return true;
	}
	return false;
}

int main (){
	char s[100005];
	gets(s);
	int len = strlen(s);
	int key[300];
	for (int i = 0; i < 300; i++) key[i] = 0;
	for (int i = 0; i < len; i++) key[s[i]]++;
	int res = 0;
	while (available(key)) res++;
	printf("%d\n", res);
	return 0;
}
