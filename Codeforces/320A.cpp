#include <stdio.h>
#include <string.h>

int right;

bool test(char n[], int left){
	if (left == right){
		return 1;
	}
	
	bool temp1 = 0, temp2 = 0, temp3 = 0;
	if (n[left] == '1') temp1 = test(n, left + 1);
	
	if (n[left] == '1' && n[left + 1] == '4') temp2 = test(n, left + 2);
	
	if (n[left] == '1' && n[left + 1] == '4' && n[left + 2] == '4') temp3 = test(n, left + 3);
	
	return (temp1 || temp2 || temp3);

}

int main (){
	char n[105];
	gets(n);
	right = strlen(n);
	printf("%s\n", (test(n, 0)) ? "YES" : "NO");
	return 0;
}
