#include <cstdio>
using namespace std;
/*

"/"
column+row MOD sizex2 == size+1
column+row MOD sizex2 == 3xsize+1

"\"
column-row MOD sizex2 == size
row-column MOD sizex2 == size

"*"
case first half (row<=size):
column MOD sizex2 < size+row  AND  column MOD sizex2 > size-row+1

case second half (row>=size):
column MOD sizex2 < 3xsize-row+1  AND  column MOD sizex2 > row-size

--------------------------------------------------------------------------
all start by 1

*/

int main (){
	int t;
	scanf("%d",&t);
	while (t--){
		int r,c,s;
		scanf("%d %d %d",&r,&c,&s);
		for (int a=1; a<=r; a++){
			for (int b=1; b<=s*2; b++){
				for (int d=1; d<=c*s*2; d++){
					if (((s+1==(b+d)%(s*2))||(3*s+1==(b+d)%(s*2)))||(s==1&&(b+d)%2==0))
						printf("/");
					else if ((s==(d-b)%(s*2))||(s==(b-d)%(s*2)))
						printf("\\");
					else if (((b<=s)&&(d%(s*2)<s+b&&d%(s*2)>s-b+1))||((b>=s)&&(d%(s*2)<3*s-b+1&&d%(s*2)>b-s)))
						printf("*");
					else
						printf(".");
				}
				printf("\n");	
			}
		}
	}
	return 0;
}
