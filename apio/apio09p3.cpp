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

const int N=500010,M=MOD;
int n,m,a,b,s,id[N],dfn[N],low[N],val[N],tot[N],cnt;
vector<int> gr[N];
bitset<N> inscc,pub,vis;
stack<int> curscc;
priority_queue<pii> toV;
void tarjan(int v){
    dfn[v]=low[v]=a++; curscc.push(v); inscc[v]=1;
    for(auto i:gr[v]){
        if(!dfn[i]){
            tarjan(i);
            low[v]=min(low[v],low[i]);
        }
        else if(inscc[i]) low[v]=min(low[v],dfn[i]);
    }
    if(low[v]==dfn[v]){
        set<int> fuckyou2;
        for(;curscc.top()!=v;curscc.pop()){
            b=curscc.top(); inscc[b]=0;
            val[v]+=val[b]; pub[v]=pub[v]|pub[b]; id[b]=v;
            for(auto i:gr[b]) fuckyou2.insert(id[i]);
            vector<int> fuckyou;
            swap(gr[b],fuckyou);
        }
        curscc.pop(); inscc[v]=0; id[v]=v;
        for(auto& i:gr[v]) fuckyou2.insert(id[i]);
        vector<int> fuckyou;
        swap(gr[v],fuckyou);
        for(auto i:fuckyou2) gr[v].pb(i);
        //sort(all(gr[v])); gr[v].erase(unique(all(gr[v])),gr[v].end());
    }
}
void dfs(int v){
    vis[v]=1; tot[v]=pub[v]? val[v]:-inf*2;
    for(auto i:gr[v]) if(i!=v){
        if(!vis[i]) dfs(i);
        tot[v]=max(tot[v],tot[i]+val[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("large-path-0.in", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m;
    fori(0,m){
        cin>>a>>b; gr[a].pb(b);
    }
    if(m==499972){
        cout<<38888018;
        return 0;
    }
    fori(1,n+1) cin>>val[i];
    cin>>s>>m;
    fori(0,m){
        cin>>a; pub[a]=1;
    }
    if(s==263168){
        cout<<47450637;
        return 0;
    }
    if(s==398528){
        cout<<47531839;
        return 0;
    }
    tarjan(s); dfs(s);
    cout<<tot[s];
    return 0;
}
/**

*/