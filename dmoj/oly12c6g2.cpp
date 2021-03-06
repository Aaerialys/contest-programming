#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i++)
#define ford(i,a,b) for(__typeof(a) i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1> using ordered_set=tree<T1,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(int x) const { return x ^ SEED; }};

const int N=100010,M=1e9+7;
int n,a,b,c,sz[N],tot;
ll ans;
vector<pii> gr[N];
hashmap<ll,ll> dist[2],cdist[2],ddist;
bool block[N];

void szdfs(int v,int p){
    sz[v]=1;
    for(auto i:gr[v])
        if(!block[i.pf]&&i.pf!=p){
            szdfs(i.pf,v);
            sz[v]+=sz[i.pf];
        }
}
int getcentroid(int v,int p){
    for(auto i:gr[v]) if(!block[i.pf]&&i.pf!=p&&sz[i.pf]*2>tot) return getcentroid(i.pf,v);
    return v;
}
void dfs(int v,int p,int d){
    if(!ddist[d]) cdist[1][d]++;
    else cdist[0][d]++;
    ddist[d]++;
    for(auto i:gr[v]) if(!block[i.pf]&&i.pf!=p) dfs(i.pf,v,d+i.ps);
    ddist[d]--;
}
void go(int v){
    szdfs(v,-1); tot=sz[v]; v=getcentroid(v,-1); block[v]=true;
    dist[0].clear(); dist[1].clear();
    for(auto i:gr[v])
        if(!block[i.pf]){
            cdist[0].clear(); cdist[1].clear(); ddist.clear();
            dfs(i.pf,v,i.ps);
            for(auto j:cdist[0]) if(j.pf)
                ans+=j.ps*(dist[0][-j.pf]+dist[1][-j.pf]);
            for(auto j:cdist[1]) if(j.pf)
                ans+=j.ps*dist[0][-j.pf];
            ans+=(dist[0][0]+dist[1][0])*cdist[1][0]+(dist[0][0]+dist[1][0]+1)*cdist[0][0];
            for(auto j:cdist[0])
                dist[0][j.pf]+=j.ps;
            for(auto j:cdist[1])
                dist[1][j.pf]+=j.ps;
        }
    for(auto i:gr[v]) if(!block[i.pf]) go(i.pf);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(1,n){
        cin>>a>>b>>c;
        gr[a].pb({b,c? 1:-1}); gr[b].pb({a,c? 1:-1});
    }
    go(1);
    cout<<ans;
    return 0;
}
/**

2 4
4 6
2 6
3 5
1 5
3 7
1 7


*/