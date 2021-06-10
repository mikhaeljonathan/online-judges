#include <stdio.h>
#include <string.h>

int main (){
	int n;
	scanf("%d", &n);
	int res = 0;
	while (n--){
		char s[100];
		scanf("%s", s);
		if (!strcmp(s, "Tetrahedron")) res += 4;
		else if (!strcmp(s, "Cube")) res += 6;
		else if (!strcmp(s, "Octahedron")) res += 8;
		else if (!strcmp(s, "Dodecahedron")) res += 12;
		else if (!strcmp(s, "Icosahedron")) res += 20;
	}
	printf("%d\n", res);
	return 0;
}
