#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 3e5+5, MN = MM*2, INF = 0x3f3f3f3f;
int N, last, tot, a[MM], len[MN], pa[MN], sz[MN], mx[MN], mi[MN], g[MN][26];
ll cnt[MM], dp[MM]; char s[MM]; vector<int> adj[MN];
void extend(int c, int val){
    int np = ++tot, p=last; len[np] = len[p] + 1;
    sz[np] = 1; mx[np] = mi[np] = val;
    for( ;p!=-1 && !g[p][c]; p=pa[p]) g[p][c] = np;
    if(p == -1) pa[np] = 0;
    else {
        int q = g[p][c];
        if(len[q] == len[p] + 1) pa[np] = q;
        else {
            int clone = ++tot; mx[clone] = -INF; mi[clone] = INF;
            len[clone] = len[p] + 1; pa[clone] = pa[q];
            memcpy(g[clone], g[q], sizeof(g[q]));
            for(; p!=-1 && g[p][c]==q; p=pa[p]) g[p][c] = clone;
            pa[q] = pa[np] = clone;
        }
    }
    last = np;
}
void dfs(int u){
    int t = len[u]; // len[pa[u]]+1... len[u]   len[u] - len[pa[u]]
    for(int v: adj[u]){
        dfs(v);
        cnt[t] += 1LL*sz[u]*sz[v]; sz[u] += sz[v];
        if(mx[u] != -INF) dp[t] = max(dp[t], 1LL*mx[u]*mx[v]);
        if(mi[u] != INF) dp[t] = max(dp[t], 1LL*mi[u]*mi[v]);
        mx[u] = max(mx[u], mx[v]); mi[u] = min(mi[u], mi[v]);
    }
}
int main(){
    //freopen("test.txt", "r", stdin);
    pa[0] = -1; mx[0] = -INF; mi[0] = INF;
    scanf("%d %s", &N, s+1);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    for(int i=N; i; i--) extend(s[i]-'a', a[i]);
    for(int i=1; i<=tot; i++) adj[pa[i]].push_back(i);
    memset(dp, -0x3f, sizeof(dp)); dfs(0);
    for(int i=N-1; i>=0; i--){
        cnt[i-1] += cnt[i]; dp[i-1] = max(dp[i-1], dp[i]);
    }
    for(int i=0; i<N; i++) printf("%lld %lld\n", cnt[i], cnt[i]? dp[i]: 0);
}