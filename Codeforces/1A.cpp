#include <stdio.h>

int main () {
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	long long row = a / c;
	long long column = b / c;
	int addition = 0;
	int temp = 0;
	if (a % c != 0) //row
	{
		addition += column;
		temp++;
	}
	if (b % c != 0){ //column
		addition += row;
		temp++;
	}
	if (temp == 2){
		addition++;
	}
	long long res = row * column;
	res += addition;
	printf("%lld\n", res);
	return 0;
}

