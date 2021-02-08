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
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.ps);}
};

const int N=20010;
ll n,m,K,q,a,b,c,hub[N],dist[200][N],t=0,cnt=0;
vector<pii> gr[N];
priority_queue<pii> toV;

void dfs()
{
    int v=toV.top().ps; toV.pop();
    for(auto i:gr[v])
    {
        if(dist[a][i.pf]>dist[a][v]+i.ps)
        {
            dist[a][i.pf]=dist[a][v]+i.ps;
            toV.push({-dist[a][i.pf],i.pf});
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>K>>q;
    fori(0,N)
        hub[i]=-1;
    fori(0,200)
        forj(0,N)
            dist[i][j]=INF;
    fori(0,m)
    {
        cin>>a>>b>>c;
        a--;b--;
        gr[a].pb({b,c});
    }
    fori(0,K)
    {
        cin>>a; a--;
        hub[a]=i;
        dist[i][a]=0;
        toV.push({0,a}); a=i;
        while(!toV.empty())
            dfs();
    }
    fori(0,q)
    {
        cin>>a>>b;
        a--;b--;
        c=INF;
        if(hub[a]==-1)
            for(auto j:gr[a])
                c=min(c,j.ps+dist[hub[j.pf]][b]);
        else
            c=dist[hub[a]][b];
        if(c!=INF)
        {
            t+=c;
            cnt++;
        }
    }
    cout<<cnt<<"\n"<<t;
    return 0;
}