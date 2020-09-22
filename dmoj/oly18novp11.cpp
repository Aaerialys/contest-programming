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

const int N=400010,M=MOD,L=19;
int n,m,q,a,b,c,d,e,in[N],out[N],ans[N],p[L][N],dep[N],x[N];
vector<int> gr[N];
vector<array<int,6>> ev;
struct BITree{
    int bit[N];
    void upd(int x,int v){
        for(;x<N;x+=x&-x) bit[x]+=v;
    }
    int query(int x){
        int ret=0;
        for(;x;x-=x&-x) ret+=bit[x];
        return ret;
    }
    void upd(int l,int r,int v){
        upd(l,v); upd(r+1,-v);
    }
} bit;
void dfs(int v,int par=0){
    in[v]=++a; dep[v]=dep[par]+1; p[0][v]=par;
    for(auto i:gr[v]) if(i!=par) dfs(i,v);
    out[v]=a;
}
void go(int l,int r,vector<array<int,6>> ev){
    if(!sz(ev)) return;
    int mid=(l+r)/2;
    for(auto i:ev){
        if(i[5]){
            if(i[4]<=mid) bit.upd(i[2],i[3],i[5]);
        }
        else x[i[4]]+=bit.query(i[2]);
    }
    if(l==r) return;
    vector<array<int,6>> ql,qr;
    for(auto i:ev){
        if(i[5]){
            if(i[4]<=mid) ql.pb(i);
            else qr.pb(i);
        }
        else{
            if(x[i[4]]>=i[3]){
                ans[i[4]]=min(ans[i[4]],mid);
                ql.pb(i);
            }
            else{
                i[3]-=x[i[4]];
                qr.pb(i);
            }
        }
    }
    for(auto i:ev) if(!i[5]) x[i[4]]=0;
    go(l,mid,ql); go(mid+1,r,qr);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>q; seto(ans,inf);
    fori(1,n){
        cin>>a>>b; gr[a].pb(b); gr[b].pb(a);
    }
    a=0; dfs(1);
    fori(1,L) forj(1,n+1) p[i][j]=p[i-1][p[i-1][j]];
    fori(0,m){
        cin>>a>>b>>c;
        if(in[a]>in[b]) swap(a,b);
        if(out[a]>=out[b]){
            d=b;
            ford(j,L-1,0) if(dep[p[j][d]]>dep[a]) d=p[j][d];
            a=d;
            ev.pb({1,0,in[b],out[b],c,1});
            ev.pb({in[a],0,in[b],out[b],c,-1});
            ev.pb({out[a]+1,0,in[b],out[b],c,1});
            ev.pb({inf,0,in[b],out[b],c,-1});
        }
        else{
            ev.pb({in[a],0,in[b],out[b],c,1});
            ev.pb({out[a]+1,0,in[b],out[b],c,-1});
        }
    }
    fori(0,q){
        cin>>a>>b>>c; ev.pb({in[a],1,in[b],c,i,0}); ev.pb({in[b],1,in[a],c,i,0});
    }
    sort(all(ev));
    go(0,inf,ev); //!inf
    fori(0,q) cout<<ans[i]<<nl;
    return 0;
}
/**

*/