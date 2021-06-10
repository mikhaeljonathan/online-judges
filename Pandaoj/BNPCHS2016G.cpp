#include <cstdio>
#include <cmath>
#define MOD 1000000007
using namespace std;
long long a[2000001];
//use vandermonde theorem

long long modex(long long a, long long b, long long c){
    long long x=1, ans = a % c;
    while (b>0){
        if (b & 1 == 1){
            x = (x * ans) % c;
        }
        ans = (ans * ans) % c;
        b >>= 1;
    }
    return x;
}

int main(){
    a[1] = 1;
    for (long long i=2; i<=2000000; i++){
        a[i] = (a[i-1] * (i % MOD)) % MOD;
    }
    int t,x=1;
    long long ans,n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        long long temp = (a[n+1]*a[n-1])%MOD, penyebut = modex(temp,MOD-2,MOD);
        long long pembilang = a[2*n] % MOD;
        ans = (pembilang*penyebut) % MOD;
        printf("Kasus #%d: %lld\n",x,ans);
        x = x+1;
    }
    return 0;
}
