#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	while (n--){
		double b;
		double p;
		scanf("%lf %lf", &b, &p);
		double temp = 60.0 / p;
		printf("%.4lf %.4lf %.4lf\n", temp * (b - 1.0), temp * b, temp * (b + 1.0));
	}
	return 0;
}
