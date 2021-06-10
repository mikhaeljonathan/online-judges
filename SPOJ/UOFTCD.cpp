#include <cstdio>
using namespace std;

long long int func(long long int d, int close, int m, long long int h, long long int l, long long int t[],long long int f[]){
	long long int level=0;
	long long int active;
	bool activebool=false;
	long long int res=0;
	for (int a=0; a<m; a++){
		if (a==close)
			continue;
		level+=f[a];
		if (level<0)
			level=0;
		if ((level>=h)&&(level<l)&&!activebool){
			activebool=true;
			active=t[a];
		} else if ((level<h)&&activebool){
			res+=t[a]-active;
			activebool=false;
		} else if ((level>=l)&&activebool){
			res+=t[a]-active;
			return res;
		} else if (level>=l)
			return res;
	}
	if (activebool)
		res+=d-active;
	return res;
}

int main () {
	int n;
	scanf("%d",&n);
	while (n--){
		long long int d,h,l;
		int m; 
		scanf("%lld %d %lld %lld",&d,&m,&h,&l);
		long long int t[m],f[m];
		for (int a=0; a<m; a++)
			scanf("%lld %lld",&t[a],&f[a]);
		long long int min=func(d,-1,m,h,l,t,f);
		for (int b=0; b<m; b++){
			long long int temp=func(d,b,m,h,l,t,f);
			if (min>temp)
				min=temp;
		}
		printf("%lld\n",min);
		printf("\n");
	}

	return 0;
}
