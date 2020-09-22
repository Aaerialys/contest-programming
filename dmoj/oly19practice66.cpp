#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i++)
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
#else
    typedef long long i128; typedef long long ui128;
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

const int N=100010;
int n,a,b,g,h,c,d,e,f,v[N],t,x[N],y[N];
set<pii> xs[N],ys[N];
vector<int> poi;
unordered_map<int,int> xcord,ycord;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n)
        cin>>x[i]>>y[i]>>v[i];
    fori(0,n)
        poi.pb(x[i]);
    sort(poi.begin(),poi.end());
    fori(0,n)
        xcord[poi[i]]=i+1;
    poi.clear();
    fori(0,n)
        poi.pb(y[i]);
    sort(poi.begin(),poi.end());
    fori(0,n)
        ycord[poi[i]]=i+1;
    fori(0,n)
    {
        x[i]=xcord[x[i]]; y[i]=ycord[y[i]];
        xs[x[i]].insert({y[i],i}); xs[x[i]].insert({0,n});  xs[x[i]].insert({inf,n});
        ys[y[i]].insert({x[i],i}); ys[y[i]].insert({0,n});  ys[y[i]].insert({inf,n});
        a=(*--xs[x[i]].find({y[i],i})).ps;
        b=(*++xs[x[i]].find({y[i],i})).ps;
        if(a!=n)
        {
            c=v[(*--xs[x[a]].find({y[a],a})).ps];
            d=v[b];
            t-=max(c,d);
            t+=max(c,v[i]);
        }
        if(b!=n)
        {
            c=v[(*++xs[x[b]].find({y[b],b})).ps];
            d=v[a];
            t-=max(c,d);
            t+=max(c,v[i]);
        }
        t+=max(v[a],v[b]);
        a=(*--ys[y[i]].find({x[i],i})).ps;
        b=(*++ys[y[i]].find({x[i],i})).ps;
        if(a!=n)
        {
            c=v[(*--ys[y[a]].find({x[a],a})).ps];
            d=v[b];
            t-=max(c,d);
            t+=max(c,v[i]);
        }
        if(b!=n)
        {
            c=v[(*++ys[y[b]].find({x[b],b})).ps];
            d=v[a];
            t-=max(c,d);
            t+=max(c,v[i]);
        }
        t+=max(v[a],v[b]);
        cout<<t<<"\n";
    }
    return 0;
}
/**

*/
