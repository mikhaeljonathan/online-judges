#include<stdio.h>

int main () {
	int h, m;
	scanf("%d %d", &h, &m);
	bool changeMinute = false;
	if ( m - 45 < 0 ){
		changeMinute = true;
		m = 60 - ( 45 - m );
	} else {
		m -= 45;
	}
	if (changeMinute){
		if (h == 0){
			h = 23;
		} else {
			h--;
		}
	}
	printf("%d %d\n", h, m);
	return 0;
}
