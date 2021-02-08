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

const int N=200010,M=MOD;
ll n,n2,m,a,b,c,dfn[N],low[N],dep[N],dep2[N],ans[N],ans2[N];
vector<pii> gr[N];
vector<pair<int,pll>> gr2[N];
stack<int> scc;
void tarjan(int v,int p=0){
    dfn[v]=low[v]=a++; scc.push(v);
    for(auto i:gr[v]) if(i.pf!=p){
        if(!dfn[i.pf]){
            dep[i.pf]=dep[v]+i.ps; tarjan(i.pf,v);
            if(low[i.pf]>=dfn[v]){
                n2++;
                for(;low[scc.top()]>=dfn[v]&&scc.top()!=v;scc.pop()){
                    int x=scc.top();
                    gr2[n2].eb(x,pll(min(dep[x]-dep[v],dep2[v]-dep[x]),max(dep[x]-dep[v],dep2[v]-dep[x]))); gr2[scc.top()].eb(n2,pll(min(dep[x]-dep[v],dep2[v]-dep[x]),max(dep[x]-dep[v],dep2[v]-dep[x])));
                }
                if(low[i.pf]==dfn[v]){
                    gr2[n2].eb(v,pll(0,0)); gr2[v].eb(n2,pll(0,0));
                }
                else{
                    gr2[v].eb(i.pf,pll(i.ps,1e11)); gr2[i.pf].eb(v,pll(i.ps,1e11));
                }
            }
            low[v]=min(low[v],low[i.pf]);
        }
        else{
            low[v]=min(low[v],dfn[i.pf]); dep2[i.pf]=dep[v]+i.ps;
        }
    }
}
void dfs(int v,int p=0){
    if(dep2[v]<1e11) tie(ans[v],ans2[v])=pll(2,dep[v]+dep2[v]);
    else tie(ans[v],ans2[v])=pll(1,dep[v]);
    for(auto i:gr2[v]) if(i.pf!=p){
        dep[i.pf]=dep[v]+i.ps.pf; dep2[i.pf]=dep2[v]+i.ps.ps;
        dfs(i.pf,v);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m; n2=n;
    fori(0,m){
        cin>>a>>b>>c;
        gr[a].eb(b,c); gr[b].eb(a,c);
    }
    gr[0].eb(1,0); tarjan(0); dep[1]=dep2[1]=0; dfs(1);
    fori(2,n+1) cout<<ans[i]<<" "<<ans2[i]<<nl;
    return 0;
}
/**
4 3
1 2 1
2 3 1
3 4 1
*/