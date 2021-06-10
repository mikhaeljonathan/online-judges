#include <cstdio>
using namespace std;

int main (){
	int n;
	scanf("%d",&n);
	int s[n];
	for (int a=0; a<n; a++)
		scanf("%d",&s[a]);
	bool asc=false,des=false;
	int b;
	for (b=0; b<n-1; b++){
		if ((s[b]<=s[b+1])&&(!des))
			des=true;
		else if ((s[b]>=s[b+1])&&(!asc)&&(des))
			asc=true;
		else if (des&&asc)
			break;
	}
	
	if ((b!=n-1)||(asc))
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}
