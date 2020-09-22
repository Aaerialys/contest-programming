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

const int N=P2(17),M=MOD;
struct SegTree{
    set<pii> seg[N*2];
    void insert(int x,int y,int v){
        for(x+=N;x;x/=2) seg[x].emplace(y,v);
    }
    void erase(int x,int y,int v){
        for(x+=N;x;x/=2) seg[x].erase(pii(y,v));
    }
    vector<int> query(int xl,int xr,int yl,int yr){
        vector<int> ret;
        for(xl+=N,xr+=N+1;xl<xr;xl/=2,xr/=2){
            if(xl&1){
                for(auto i=seg[xl].lower_bound(pii(yl,0));i!=seg[xl].lower_bound(pii(yr,inf));i++) ret.pb(i->ps);
                xl++;
            }
            if(xr&1){
                --xr;
                for(auto i=seg[xr].lower_bound(pii(yl,0));i!=seg[xr].lower_bound(pii(yr,inf));i++) ret.pb(i->ps);
            }
        }
        return ret;
    }
} st;
int n,m,a,b,c,d,e,f,x[N],y[N],dist[N];
vector<int> cur;
vector<tuple<int,int,int,int,int>> gr[N];
priority_queue<tuple<int,int,int,int,int>> toV;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>x[0]>>y[0];
    fori(1,n+1){
        cin>>x[i]>>y[i]; st.insert(x[i],y[i],i);
    }
    fori(0,m){
        cin>>f>>a>>b>>c>>d>>e;
        gr[f].eb(-a,b,c,d,e);
    }
    toV.emplace(0,x[1],x[1],y[1],y[1]);
    while(sz(toV)){
        tie(a,b,c,d,e)=toV.top(); toV.pop();
        cur=st.query(b,c,d,e);
        for(auto i:cur){
            dist[i]=a; st.erase(x[i],y[i],i);
            for(auto j:gr[i]){
                get<0>(j)+=dist[i];
                toV.emplace(j);
            }
        }
    }
    fori(2,n+1) cout<<-dist[i]<<nl;
    return 0;
}
/**

*/