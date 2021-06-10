#include <stdio.h>

int main (){
	int n;
	scanf("%d",&n);
	getchar();
	int x = 0;
	while (n--){
		char temp[5];
		gets(temp);
		if (temp[0] == '+' || temp[2] == '+') x++;
		else x--;
	}
	printf("%d\n", x);
	return 0;
}
