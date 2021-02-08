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
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
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
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};

const int N=100010,M=1e9+7;
gp_hash_table<pii,int,pair_hash> mp;
gp_hash_table<int,int,chash> nf[N];
int n,a,b,c,val[N],f[N],ans;
vector<int> gr[N];
struct DSU{
    int p[N];
    DSU(){fill(all(p),-1);}
    int head(int x){return p[x]<0? x: p[x]=head(p[x]);}
    bool link(int x,int y){
        x=head(x); y=head(y);
        if(x==y) return 0;
        if(p[x]>p[y]) swap(x,y);
        p[x]+=p[y]; p[y]=x;
        for(auto i:nf[y]) nf[x][i.pf]+=i.ps;
        return 1;
    }
};
DSU dsu;
void dfs(int v,int p){
    nf[v][val[v]]=1;
    for(auto i:gr[v]) if(i!=p){
        dfs(i,v);
        dsu.link(v,i);
    }
    for(auto i:nf[dsu.head(v)]) if(i.ps!=f[i.pf]) return;
    ans++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n-2){
        cin>>a>>b>>c>>val[i]; f[val[i]]++;
        if(b<c) swap(b,c);
        if(a<b) swap(a,b);
        if(b<c) swap(b,c);
        if(mp.find({a,b})==mp.end()) mp[{a,b}]=i;
        else{
            gr[i].pb(mp[{a,b}]);
            gr[mp[{a,b}]].pb(i);
        }
        if(mp.find({a,c})==mp.end()) mp[{a,c}]=i;
        else{
            gr[i].pb(mp[{a,c}]);
            gr[mp[{a,c}]].pb(i);
        }
        if(mp.find({b,c})==mp.end()) mp[{b,c}]=i;
        else{
            gr[i].pb(mp[{b,c}]);
            gr[mp[{b,c}]].pb(i);
        }
    }
    dfs(0,-1);
    cout<<ans-1<<"\n";
    return 0;
}
/**

*/