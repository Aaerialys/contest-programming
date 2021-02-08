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
typedef pair<ll,ll> pii;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
mt19937 randgen(time(0)); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=200010;
ll n,M,t,a,b,c,d[N],l,r,mid,sh;
pii g[N],x,temp;
set<pii> fre;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>M; r=n+1;
    fori(0,n)
    {
        cin>>a>>b;
        g[i].pf=(M-b+a)%M; g[i].ps=(M-b)%M;
    }
    fre.insert({(g[0].pf+M-1)%M,0}); fre.insert({-1,INF});
    fori(1,n)
    {
        cin>>d[i]; sh=(sh+d[i])%M; t+=d[i];
        g[i].pf=(g[i].pf-sh+M)%M; g[i].ps=(g[i].ps-sh+M)%M;
        fre.insert({(g[i].pf+M-1)%M,0});
    }
    fori(0,n)
    {
        x={g[i].ps,INF};
        if(g[i].pf<g[i].ps)
        {
            while(prev(fre.upper_bound({g[i].ps,INF}))->pf>=g[i].pf)
            {
                x.ps=min(x.ps,prev(fre.upper_bound({g[i].ps,INF}))->ps+(g[i].ps-prev(fre.upper_bound({g[i].ps,INF}))->pf+M)%M);
                fre.erase(prev(fre.upper_bound({g[i].ps,INF})));
            }
        }
        else
        {
            while(prev(fre.upper_bound({g[i].ps,INF}))->pf>=0)
            {
                x.ps=min(x.ps,prev(fre.upper_bound({g[i].ps,INF}))->ps+(g[i].ps-prev(fre.upper_bound({g[i].ps,INF}))->pf+M)%M);
                fre.erase(prev(fre.upper_bound({g[i].ps,INF})));
            }
            while(prev(fre.end())->pf>=g[i].pf)
            {
                temp=*prev(fre.end());
                x.ps=min(x.ps,prev(fre.end())->ps+(g[i].ps-prev(fre.end())->pf+M)%M);
                fre.erase(prev(fre.end()));
            }
        }
        if(x.ps!=INF)
            fre.insert(x);
    }
    a=INF;
    for(auto i:fre)
        a=min(a,i.ps);
    cout<<t+a;
    return 0;
}
/**
6 2
1 1
1 1
1 0
1 1
1 1
1 0
1 1 1 1 1
*/