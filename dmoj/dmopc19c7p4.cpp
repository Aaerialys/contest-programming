#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,fma,mmx,popcnt,tune=native" //#pragma GCC optimize "prefetch-loop-arrays"

using namespace std; using namespace __gnu_pbds;
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
#define nl "\n";

const ll N=300010,M=MOD;
struct frac{ll a,b,c,d;};
ll n,q,l,r,a[N];
frac ans[N];
frac f[N],v[N];
vector<frac> que;
frac comb(frac a,frac b){
    return {(a.a*b.a+a.b*b.c)%M,(a.a*b.b+a.b*b.d)%M,(a.c*b.a+a.d*b.c)%M,(a.c*b.b+a.d*b.d)%M};
}
void go(int l,int r,vector<frac> que){
    if(!sz(que)) return;
    int mid=(l+r)/2; vector<frac> ql,qr;
    f[mid]=v[mid]; f[mid+1]=v[mid+1];
    ford(i,mid-1,l) f[i]=comb(v[i],f[i+1]);
    fori(mid+2,r+1) f[i]=comb(f[i-1],v[i]);
    for(auto i:que){
        if(i.a<=mid&&i.b>mid) ans[i.c]=comb(f[i.a],f[i.b]);
        else if(i.b==mid) ans[i.c]=f[i.a];
        else if(i.b<mid) ql.pb(i);
        else if(i.a>mid) qr.pb(i);
    }
    if(l==r) return;
    go(l,mid,ql); go(mid+1,r,qr);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(1,n+1){
        cin>>a[i]; v[i]={a[i],1,1,0};
    }
    fori(0,q){
        cin>>l>>r; que.pb({l,r,i,0});
    }
    go(1,n,que);
    fori(0,q) cout<<ans[i].a<<" "<<ans[i].c<<nl;
    return 0;
}
/**
x
(ax+1)/x
(b(ax+1)+x)/(ax+1)=(abx+b+x)/(ax+1)
(c(abx+b+x)+(ax+1))/(abx+b+x)=abcx+bc+cx+ax+1

(a(Ax+B)/(Cx+D)+b)/(c(Ax+B)/(Cx+D)+d)
=(aAx+bCx+aB+bD)/(cAx+dCx+cB+dD)
a'=aA+bC
b'=aB+bD
c'=cA+dC
d'=cB+dD

v+1/x
(vx+1)/(1x+0)
(v,1,1,0)

(0,inf,0,1)
(0,inf,0,inf)
a/c

=


*/