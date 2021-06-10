#include <stdio.h>

bool distinct(int y){
	bool ever[10];
	for (int i = 0; i <= 9; i++){
		ever[i] = false;
	}
	while (y > 0){
		if (!ever[y % 10]){
			ever[y % 10] = true;
		} else{
			return false;
		}
		y /= 10;
	}
	return true;
}

int main () {
	int y;
	scanf("%d", &y);
	y++;
	while (!distinct(y)){
		y++;
	}
	printf("%d\n", y);
	return 0;
}
