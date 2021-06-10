#include <stdio.h>

int main (){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x1,y1,x2,y2,x3,y3;
	int intervals[105];
	for (int i = 0; i < 105; i++) intervals[i] = 0;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	for (int i = x1; i < y1; i++) intervals[i]++;
	for (int i = x2; i < y2; i++) intervals[i]++;
	for (int i = x3; i < y3; i++) intervals[i]++;
	int res = 0;
	for (int i = 0; i < 105; i++){
		if (intervals[i] == 0) continue;
		if (intervals[i] == 1) res += a;
		else if (intervals[i] == 2) res += b * 2;
		else if (intervals[i] == 3) res += c * 3;
	}
	printf("%d\n", res);
	return 0;
}
