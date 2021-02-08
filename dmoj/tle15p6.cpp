#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a);i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}
};
#define nl endl

const int N=5010,M=MOD;
int n,m,q,a,b,s,id[N],dfn[N],low[N],sz[N],ans[N][N];
vector<int> gr[N];
bitset<N> vis;
stack<int> curscc;
void tarjan(int v){
    dfn[v]=low[v]=a++; curscc.push(v); vis[v]=1;
    for(auto i:gr[v]){
        if(!dfn[i]){
            tarjan(i);
            low[v]=min(low[v],low[i]);
        }
        else if(vis[i]) low[v]=min(low[v],dfn[i]);
    }
    if(low[v]==dfn[v]){
        for(;curscc.top()!=v;curscc.pop()){
            b=curscc.top(); vis[b]=0;
            sz[v]++; id[b]=v;
            for(auto i:gr[b]) gr[v].pb(i);
        }
        curscc.pop(); vis[v]=0; id[v]=v; sz[v]++;
        for(auto& i:gr[v]) i=id[i];
        sort(all(gr[v])); gr[v].erase(unique(all(gr[v])),gr[v].end());
    }
}
void dfs(int v){
    vis[v]=1;
    for(auto i:gr[v]) if(i!=v){
        if(!vis[i]) dfs(i);
        ans[v][i]=max(ans[v][i],0);
        forj(1,n+1) if(id[j]==j) ans[v][j]=max(ans[v][j],ans[i][j]+sz[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("large-path-0.in", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>q;
    fori(0,m){
        cin>>a>>b; gr[a].pb(b);
    }
    fori(1,n+1) if(!dfn[i]) tarjan(i);
    seto(ans,-inf);
    fori(1,n+1) if(id[i]==i&&!vis[i]) dfs(i);
    while(q--){
        cin>>a>>b;
        if(ans[id[a]][id[b]]<0) swap(a,b);
        if(ans[id[a]][id[b]]<0) cout<<"Indeterminate"<<nl;
        else cout<<a<<" "<<ans[id[a]][id[b]]<<nl;
    }
    return 0;
}
/**
10 38 20
2 10
8 2
5 10
3 7
9 2
9 4
5 4
3 8
7 2
1 6
7 9
5 6
9 3
8 5
1 4
1 2
7 4
9 8
1 10
3 5
4 6
4 2
8 6
1 5
8 10
4 10
1 8
5 2
9 10
3 6
6 2
4 8
7 5
3 1
9 1
7 8
7 1
10 6

8 20 15
3 4
8 4
4 1
5 3
7 6
8 6
3 7
5 6
7 5
6 2
8 1
3 6
7 2
3 1
7 1
8 2
4 6
5 4
2 1
1 6
*/