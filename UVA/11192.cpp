#include <stdio.h>
#include <string.h>

int main (){
	int g;
	scanf("%d", &g);
	getchar();
	while (g != 0){
		char string[200];
		gets(string);
		int len = strlen(string);
		g = len / g;
		char ans[len + 1];
		int head = 0;
		for (int tail = g - 1; tail <= len - 1; tail += g, head += g){
			int temphead = head;
			int temptail = tail;
			while (temptail >= head){
				ans[temphead] = string[temptail];
				temphead++;
				temptail--;
			}
		}
		ans[len] = '\0';
		printf("%s\n", ans);
		scanf("%d", &g);
		getchar();
	}
	return 0;
}
