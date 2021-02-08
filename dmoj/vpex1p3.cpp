#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i--)
#define ford(i,a,b) for(__typeof(a) i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define pow2(x) (1LL<<(x))
using namespace std;
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
mt19937 randgen(time(0)); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=100001;
ll a,b,w,h,x,y,x0,Y0,z;
double t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //string test="15";
    //string in="in"+test+".txt"; freopen(in.c_str(), "r", stdin);
    //in="out"+test+".txt"; freopen(in.c_str(), "w", stdout);
    cin>>w>>h>>a>>b>>x0>>Y0>>x>>y;
    assert(1<=a&&a<w&&w<=N);
    assert(1<=b&&b<h&&h<=N);
    assert(1<=a+x0&&a+x0<=w);
    assert(1<=b+Y0&&b+Y0<=h);
    assert(-N<=x&&-N<=y&&x<=N&&y<=N);
    assert(x!=0||y!=0);
    w-=a; h-=b; w*=2; h*=2;
    if(x==0)
        z=w*1000000;
    else if(y==0)
        z=h*1000000;
    else
    {
        t=1.0*w*y*h*x/gcd(w*y,h*x);
        z=sqrt(t/x*t/x+t/y*t/y)*1000000;
    }
    string out=to_string(z);
    cout<<out.substr(0,6);
    return 0;
}