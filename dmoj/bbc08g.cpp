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
const int inf=0x3f3f3f3f,MOD=1e9+13; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
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
pii to[N],last;
int n,m,a,b,c,x,y,cnt,dist[N],dist2[N],pre[N],ans;
priority_queue<tuple<int,int,int,int,int>> nxt;
vector<pii> gr[N];
vector<int> path;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m;
    fori(0,m){
        cin>>a>>b>>c; gr[a].eb(b,c); gr[b].eb(a,c);
    }
    nxt.emplace(1,1,0,0,0); seto(dist,inf);
    while(sz(nxt)){
        tie(x,b,c,a,y)=nxt.top(); nxt.pop();
        if(dist[a]<inf) continue;
        to[a]=pii(y,-b);
        if(last!=pii(b,c)) cnt++;
        last={b,c};
        dist[a]=cnt;
        for(auto i:gr[a]) if(dist[i.pf]==inf){
            nxt.emplace(x-1,-i.ps,-dist[a],i.pf,a);
        }
    }
    seto(dist2,inf); dist2[n-1]=0; nxt.emplace(0,n-1,0,0,0);
    while(sz(nxt)){
        tie(b,a,ignore,ignore,ignore)=nxt.top(); nxt.pop();
        for(auto i:gr[a]) if(!i.ps&&dist2[i.pf]>dist2[a]+1){
            dist2[i.pf]=dist2[a]+1;
            nxt.emplace(-dist[i.pf],i.pf,0,0,0);
            pre[i.pf]=a;
        }
    }
    ans=n;
    fori(0,n) if(dist2[i]<inf&&pii(dist[i],dist2[i])<pii(dist[ans],dist2[ans])) ans=i;
    for(a=ans;a!=n-1;a=pre[a]){
        path.pb(a);
    }
    path.pb(n-1); reverse(all(path));
    for(a=ans;a;a=to[a].pf){
        cout<<to[a].ps;
        if(a!=ans) path.pb(a);
    }
    if(ans) path.pb(0); reverse(all(path));
    if(!ans) cout<<0;
    cout<<nl<<sz(path)<<nl;
    for(auto i:path) cout<<i<<" ";
    return 0;
}
/**
1000000000
1020000000
*/