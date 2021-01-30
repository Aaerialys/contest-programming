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

const int N=1000010,M=MOD,L=20;
int n,q,ans,a,b,c,x,y,p[L][N],rt,im,dep[N],mi[L][N];
vector<int> gr[N];
bool vis[N];
void dfs(int v,int par=0){
    p[0][v]=par; dep[v]=dep[par]+1; mi[0][v]=v;
    for(auto i:gr[v]) if(i!=par) dfs(i,v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(1,n){
        cin>>a>>b; gr[a].pb(b); gr[b].pb(a);
    }
    dfs(1);
    fori(1,L) forj(1,n+1) p[i][j]=p[i-1][p[i-1][j]],mi[i][j]=min(mi[i-1][j],mi[i-1][p[i-1][j]]);
    im=inf;
    while(q--){
        cin>>x>>y; y=(y+ans)%n+1;
        if(x==1){
            a=y; b=p[0][rt];
            if(!rt) rt=a=b=y;
            while(1){
                if(dep[a]>dep[b]) swap(a,b);
                if(vis[b]) break;
                if(dep[b]<dep[rt]) rt=b;
                vis[b]=1; im=min(im,b); b=p[0][b];
            }
        }
        else if(x==2){
            a=y; b=rt; ans=im;
            if(dep[a]>dep[b]) swap(a,b);
            ford(i,L-1,0) if(dep[p[i][b]]>=dep[a]) ans=min(ans,mi[i][b]),b=p[i][b];
            ford(i,L-1,0) if(p[i][a]!=p[i][b]) ans=min(ans,mi[i][a],mi[i][b]),a=p[i][a],b=p[i][b];
            if(a!=b) ans=min(ans,a,b),a=b=p[0][a];
            ans=min(ans,a);
            cout<<ans<<nl;
        }
    }
    return 0;
}
/**

*/