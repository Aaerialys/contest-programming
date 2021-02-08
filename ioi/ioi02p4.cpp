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

const int N=10010,M=MOD;
int n,S,t[N],f[N],dp[N],w;
int calc(int j,int k){
    return ceil((0.0+dp[j]+(S-t[j])*(f[n]-f[j])-dp[k]-(S-t[k])*(f[n]-f[k]))/(f[j]-f[k]));
}
deque<int> pre;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>S;
    fori(1,n+1){
        cin>>t[i]>>f[i]; t[i]+=t[i-1]; f[i]+=f[i-1];
    }
    seto(dp,inf); dp[0]=0; pre.pb(0);
    fori(1,n+1) forj(w,i) if(dp[j]+(t[i]-t[j]+S)*(f[n]-f[j])<dp[i]){
        dp[i]=dp[j]+(t[i]-t[j]+S)*(f[n]-f[j]);
        w=j;
    }
    fori(1,n+1){
        while(sz(pre)>1&&t[i]>=calc(pre[0],pre[1])) pre.pop_front();
        dp[i]=dp[pre[0]]+(t[i]-t[pre[0]]+S)*(f[n]-f[pre[0]]);
        while(sz(pre)>1&&calc(pre[sz(pre)-2],pre[sz(pre)-1])>=calc(pre[sz(pre)-1],i)) pre.pop_back();
        pre.pb(i);
    }
    cout<<dp[n];
    return 0;
}
/**
dp[i]=dp[j]+(t[i]-t[j]+S)*(f[n]-f[j]);

dp[k]+(t[i]-t[k]+S)*(f[n]-f[k])<dp[j]+(t[i]-t[j]+S)*(f[n]-f[j])
dp[k]+t[i]*(f[n]-f[k])-(t[k]-S)*(f[n]-f[k])
t[i]*(f[n]-f[k])-t[i]*(f[n]-f[j])<dp[j]-(t[j]-S)*(f[n]-f[j])-dp[k]+(t[k]-S)*(f[n]-f[k])
t[i]*(f[k]-f[j])>dp[j]-(t[j]-S)*(f[n]-f[j])-dp[k]+(t[k]-S)*(f[n]-f[k])
t[i]>(dp[j]-(t[j]-S)*(f[n]-f[j])-dp[k]+(t[k]-S)*(f[n]-f[k]))/(f[k]-f[j]);
*/