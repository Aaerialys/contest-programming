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
#define nl "\n"

const int N=100010,M=MOD;
int n,q,m,a,b,pre[N],sz[N],dep[N],par[N],top[N],rt,K;
ll dp[301],ans;
bitset<N> mark;
vector<int> gr[N],aux[N],node;
stack<int> stk;
void dfs(int v,int p=0){
    sz[v]=1; pre[v]=++a; dep[v]=dep[p]+1; par[v]=p;
    for(auto i:gr[v]) if(i!=p){
        dfs(i,v); sz[v]+=sz[i];
    }
}
void dfs0(int v,int p=0){
    int hc=0;
    for(auto i:gr[v]) if(i!=p&&sz[i]>sz[hc]) hc=i;
    for(auto i:gr[v]) if(i!=p){
        top[i]=i==hc? top[v]:i;
        dfs0(i,v);
    }
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]) swap(u,v);
        v=par[top[v]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    return u;
}
bool cmp(int a,int b){
    return pre[a]<pre[b];
}
void dfs2(int v,int p=0){
    if(mark[v]){
        ford(i,K,1) dp[i]=(dp[i-1]+dp[i]*(i-a))%M;
        dp[0]=0;
    }
    a+=mark[v];
    for(auto i:aux[v]) if(i!=p) dfs2(i,v);
    a-=mark[v];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(1,n){
        cin>>a>>b; gr[a].pb(b); gr[b].pb(a);
    }
    a=0; dfs(1); dfs0(1);
    while(q--){
        cin>>m>>K>>rt; node.pb(rt);
        fori(0,m){
            cin>>a; node.pb(a); mark[a]=1;
        }
        sort(all(node),cmp);
        fori(1,m+1) node.pb(lca(node[i],node[i-1]));
        sort(all(node)); node.erase(unique(all(node)),node.end());
        sort(all(node),cmp);
        for(auto i:node){
            while(sz(stk)&&pre[i]>=pre[stk.top()]+sz[stk.top()]) stk.pop();
            if(sz(stk)){
                aux[stk.top()].pb(i); aux[i].pb(stk.top());
            }
            stk.push(i);
        }
        a=0; dp[0]=1; dfs2(rt);
        fori(0,K+1) ans+=dp[i];
        cout<<ans%M<<nl;
        for(auto i:node){
            aux[i].clear();
            mark[i]=0;
        }
        node.clear(); seto(dp,0); ans=0;
        while(sz(stk)) stk.pop();
    }
    return 0;
}
/**

*/
