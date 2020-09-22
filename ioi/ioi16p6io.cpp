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
#define nl "\n"

const int N=1000100;
ll a,b,pn[N],x,y,l,r=1e12,mid,dp[N],cons[N];
pll seg[N];
deque<int> best;

ll sq(ll x){
    return x*x;
}
ll f(int j,int k){
    return (cons[k]-cons[j]+sq(seg[k+1].pf-1)-sq(seg[j+1].pf-1))/(seg[k+1].pf-seg[j+1].pf)/2;
}
bool cmp(pll xx,pll yy){
    if(xx.pf==yy.pf)
        return xx.ps>yy.ps;
    return xx.pf<yy.pf;
}

long long take_photos(int n,int m,int K,int* px,int* py){
    seg[0]={-1,-1};
    fori(1,n+1)
        seg[i]={min(px[i-1],py[i-1]),max(px[i-1],py[i-1])};
    sort(seg,seg+n+1,cmp);
    fori(0,n+1){
        if(seg[i].pf>=a&&seg[i].ps<=b) seg[i].pf=inf;
        else tie(a,b)=seg[i];
    }
    sort(seg,seg+n+1);
    n=lower_bound(seg,seg+n+1,(pll){inf,0})-seg-1; K=min(n,K); l=P2(40);
    ford(i,39,0){
        r=l-P2(i);
        best.clear(); best.pb(0);
        fori(1,n+1){
            while(best.size()>1&&f(best[0],best[1])<seg[i].ps) best.pop_front();
            int j=best[0];
            dp[i]=cons[j]+sq(seg[i].ps-seg[j+1].pf+1)+r; cons[i]=dp[i]-sq(max(0,seg[i].ps-seg[i+1].pf+1));
            pn[i]=pn[j]+1;
            while(best.size()>1&&f(best[best.size()-1],i)<f(best[best.size()-2],best[best.size()-1])) best.pop_back();
            best.pb(i);
        }
        if(pn[n]<=K){
            x=dp[n]; l=r;
            if(pn[n]==K) break;
        }
    }
    return x-l*K;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    int n,m,K,px[N],py[N];
    cin>>n>>m>>K;
    fori(0,n) cin>>px[i]>>py[i];
    cout<<take_photos(n,m,K,px,py);
    return 0;
}
/**
dp[i]=dp[k]+(r[i]-l[k+1]+1)^2-(r[k]-l[k+1]+1)^2
dp[i]=dp[k]-(r[k]-l[k+1]+1)^2+(r[i]-l[k+1]+1)^2
*/