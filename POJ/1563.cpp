#include <stdio.h>

int main (){
	double h, u, d, f;
	scanf("%lf %lf %lf %lf", &h, &u, &d, &f);
	while (h != 0.0){
		double height = 0.0;
		double distance = u;
		bool success = false;
		bool failure = false;
		int day = 1;
		double fatiguefactor = u * (f/100.0);
		while (1){
			if (distance >= 0) height += distance;
			if (height > h){
				success = true;
				break;
			}
			height -= d;
			if (height < 0){
				failure = true;
				break;
			}
			distance = distance - fatiguefactor;
			day++;
		}
		printf("%s on day %d\n", (success)? "success" : "failure", day);
		
		scanf("%lf %lf %lf %lf", &h, &u, &d, &f);
		
	}
	return 0;
}
