#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, d[20], n; ll L, R, dp[20][2522][1<<8];
ll fun(int pos, int rem, int mask, bool limit){
    if(pos == 0){
        for(int i=2; i<=9; i++)
            if( (mask & (1<<(i-2))) && rem % i != 0) return 0;
        return 1;
    }
    if(!limit && dp[pos][rem][mask] != -1) return dp[pos][rem][mask];
    int up = limit? d[pos]:9; ll ret = 0;
    for(int i=0; i<=up; i++){
        int nmask = (i>=2)? mask|(1<<(i-2)):mask;
        ret += fun(pos-1, (rem*10 + i)%2520, nmask, limit && i==d[pos] );
    }
    if(!limit) dp[pos][rem][mask] = ret;
    return ret;
}
ll solve(ll x){
    n = 0;
    for(; x>0; x/=10) { n++; d[n] = x % 10; }
    return fun(n, 0, 0, 1);
}
int main(){
    scanf("%d", &T); memset(dp, -1, sizeof(dp));
    for(int k=1; k<=T; k++){
        scanf("%lld %lld", &L, &R);
        printf("%lld\n", solve(R) - solve(L-1));
    }
}