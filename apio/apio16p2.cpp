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
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl endl

const int N=300010,M=MOD;
ll n,m,a,b,pl[N],rt[N],ans;
vector<int> gr[N];
priority_queue<ll> poi[N];
void dfs(int v){
    rt[v]=v;
    if(v>n){
        poi[v].push(pl[v]); poi[v].push(pl[v]);
        return;
    }
    for(auto i:gr[v]){
        dfs(i);
        if(sz(poi[rt[i]])>sz(poi[rt[v]])) rt[v]=rt[i];
    }
    for(auto i:gr[v]) if(rt[i]!=rt[v]){
        while(sz(poi[rt[i]])){
            poi[rt[v]].push(poi[rt[i]].top()); poi[rt[i]].pop();
        }
    }
    fori(1,sz(gr[v])) poi[rt[v]].pop();
    a=poi[rt[v]].top(); poi[rt[v]].pop(); b=poi[rt[v]].top(); poi[rt[v]].pop();
    a+=pl[v]; b+=pl[v]; poi[rt[v]].push(b); poi[rt[v]].push(a);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("3_01.in", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m; m+=n;
    fori(2,m+1){
        cin>>a>>b;
        gr[a].pb(i);
        pl[i]=b; ans+=b;
    }
    dfs(1);
    poi[rt[1]].pop(); a=poi[rt[1]].top(); poi[rt[1]].push(0); b=0;
    while(sz(poi[rt[1]])){
        ans-=(a-poi[rt[1]].top())*b++;
        a=poi[rt[1]].top(); poi[rt[1]].pop();
    }
    cout<<ans;
    return 0;
}
/**

*/