#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef pair<ll, int> pi;
const int MM = 1e5+10, B=300, SZ=400;
int N, Q, cnt, lft[SZ], rit[SZ]; pi p[MM]; ll x, a[MM], pg[SZ], px[SZ];
void updBlk(int b){
    pg[b] = px[b] = a[lft[b]]; p[lft[b]] = {px[b], lft[b]};
    for(int i=lft[b]+1; i<=rit[b]; i++){
        pg[b] = __gcd(pg[b], a[i]);
        px[b] = px[b] ^ a[i];
        p[i] = {px[b], i};
    }
    sort(p+lft[b], p+rit[b]+1);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &N); cnt = (N+B-1)/B;
    for(int i=1; i<=cnt; i++){
        lft[i] = (i-1)*B+1; rit[i] = min(N, i*B);
        for(int j=lft[i]; j<=rit[i]; j++) scanf("%lld", &a[j]);
        updBlk(i);
    }
    scanf("%d", &Q);
    for(int t=1, op, pos; t<=Q; t++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %lld", &pos, &x);
            pos++; a[pos] = x; updBlk((pos+B-1)/B);
        }else{
            scanf("%lld", &x);
            ll gcd = a[1], xx=0; bool done = false;
            for(int i=1; i<=cnt; i++){
                if(__gcd(pg[i], gcd) == gcd){
                    if(x % gcd == 0){
                        ll target = x / gcd ^ xx;
                        int id = lower_bound(p+lft[i], p+rit[i]+1, make_pair(target, 0)) - p;
                        if(p[id].f == target) { printf("%d\n", p[id].s-1); done=true; break; }
                    }
                    gcd = __gcd(gcd, pg[i]); xx ^= px[i];
                }else{
                    for(int j=lft[i]; j<=rit[i]; j++){
                        gcd = __gcd(gcd, a[j]); xx ^= a[j];
                        if(gcd * xx == x){ printf("%d\n", j-1); done=true; break;}
                    }
                }
            }
            if(!done) printf("-1\n");
        }
    }
}