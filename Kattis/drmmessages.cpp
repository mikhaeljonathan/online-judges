#include <stdio.h>
#include <string.h>

int main () {
	char x[15005];
	gets(x);
	int size = strlen(x);
	char temp1[size / 2];
	char temp2[size / 2];
	
	//divide
	for (int i = 0; i < size / 2; i++){
		temp1[i] = x[i];
	}
	for (int i = 0; i < size / 2; i++){
		temp2[i] = x[i + size / 2];
	}
	
	//rotate
	long long rotation = 0;
	for (int i = 0; i < size / 2; i++){
		rotation += temp1[i] - 'A';
	}
	for (int i = 0; i < size / 2; i++){
		temp1[i] = ((temp1[i] - 'A') + rotation) % 26 + 'A';
	}
	rotation = 0;
	for (int i = 0; i < size / 2; i++){
		rotation += temp2[i] - 'A';
	}
	for (int i = 0; i < size / 2; i++){
		temp2[i] = ((temp2[i] - 'A') + rotation) % 26 + 'A';
	}
	
	//merge
	for (int i = 0; i < size / 2; i++){
		temp1[i] = ((temp1[i] - 'A') + (temp2[i] - 'A')) % 26 + 'A';
	}
	printf("%s\n", temp1);
	
	return 0;
}
