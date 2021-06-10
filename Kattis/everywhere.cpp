#include <stdio.h>
#include <string.h>

char cities[100][30];

bool exist (char city[], int index){
	for (int i = 0; i < index; i++) if (!strcmp(city, cities[i])) return true;
	return false;
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		int res = 0;
		for (int i = 0; i < n; i++){
			char city[30];
			getchar();
			scanf("%s", city);
			strcpy(cities[i], city);
			if (!exist(city, i)) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
