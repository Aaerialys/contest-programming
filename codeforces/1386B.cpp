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
#define nl endl

const int N=10000,M=MOD;
int n,a,b,c,p1,p2,p3;
vector<tuple<int,int,int>> bot;
lld x0,y0,x,y,z,EPS=1e-13;
multiset<lld> ang;
char ch;
bool eq(lld a,lld b){
    return abs(a-b)<EPS;
}
lld rnd(lld a){
    return round(a*1e14)*1.0/1e14;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("mixture.i10", "r", stdin); //freopen("", "w", stdout);
    cin>>a>>b>>c; x0=1.0*a/(a+b+c); y0=1.0*b/(a+b+c);
    cin>>n;
    foru(cnt,0,n){
        cin>>ch;
        if(ch=='A'){
            cin>>a>>b>>c; bot.eb(a,b,c); x=1.0*a/(a+b+c)-x0; y=1.0*b/(a+b+c)-y0; z=atan2(y,x);
            p1+=eq(x,0)&eq(y,0);
            p2+=ang.count(rnd(z+PI));
            ang.insert(rnd(z)); ang.insert(rnd(z+2*PI)); ang.insert(rnd(z-2*PI));
            if(sz(ang)<=6) p3=1+(p2>0);
            else{
                x=*prev(ang.find(rnd(z))); y=*next(ang.find(rnd(z)));
                if(y-x>=PI-EPS) p3--;
                if(z-x>=PI-EPS) p3++;
                if(y-z>=PI-EPS) p3++;
            }
        }
        else if(ch=='R'){
            cin>>a; a--; tie(a,b,c)=bot[a]; x=1.0*a/(a+b+c)-x0; y=1.0*b/(a+b+c)-y0; z=atan2(y,x);
            p1-=eq(x,0)&eq(y,0);
            p2-=ang.count(rnd(z+PI));
            if(sz(ang)<=9) p3=1+(p2>0);
            else{
                x=*prev(ang.find(rnd(z))); y=*next(ang.find(rnd(z)));
                if(y-x>=PI-EPS) p3++;
                if(z-x>=PI-EPS) p3--;
                if(y-z>=PI-EPS) p3--;
            }
            ang.erase(ang.find(rnd(z))); ang.erase(ang.find(rnd(z+2*PI))); ang.erase(ang.find(rnd(z-2*PI)));
        }
        if(p1) cout<<1<<nl;
        else if(p2) cout<<2<<nl;
        else if(!p3) cout<<3<<nl;
        else cout<<0<<nl;
    }
    return 0;
}
/**
3 3 4
13
A 0 5 5 -0.3 0.2
R 1
A 1 3 6 -0.2 0
A 0 6 4 -0.3 0.3
R 2

A 5 3 2 0.2 0
R 3
A 1 3 6 -0.2 0
A 7 2 1 0.4 -0.1
A 2 1 7 -0.1 -0.2
R 4
A 6 4 0 0.3 0.1
R 5

0
0
0
0
0

0
0
2
2
2
3
0
3
*/
