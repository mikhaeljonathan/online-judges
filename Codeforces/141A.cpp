#include <stdio.h>
#include <string.h>

bool same(int key1[], int key2[]){
	for (char i = 'A'; i <= 'Z'; i++)
		if (key1[i] != key2[i]) return false;
	return true;
}

int main (){
	char guest[105];
	char host[105];
	char pile[105];
	gets(guest);
	gets(host);
	gets(pile);
	int key1[300], key2[300];
	for (int i = 0; i < 300; i++){
		key1[i] = 0;
		key2[i] = 0;
	} 
	
	int len = strlen(guest);
	for (int i = 0; i < len; i++) key1[guest[i]]++; 
	
	len = strlen(host);
	for (int i = 0; i < len; i++) key1[host[i]]++;
	
	len = strlen(pile);
	for (int i = 0; i < len; i++) key2[pile[i]]++;
	
	printf("%s\n", (same(key1, key2)) ? "YES" : "NO");
	return 0;
}
