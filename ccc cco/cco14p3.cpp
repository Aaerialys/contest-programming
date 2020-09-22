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

const int N=210,M=1e9+7;
ll n,m,W,a,b,c,dp[N][N][2],ans[N];
vector<pii> gr[N];
bool vis[N];
char ch;

void dfs(int v)
{
    vis[v]=true; dp[v][0][0]=dp[v][1][1]=1; ll temp[N][2]={0};
    for(auto i:gr[v])
    {
        dfs(i.pf);
        forj(0,N)
            ford(k,j,0)
                temp[j][0]+=dp[v][j-k][0]*(dp[i.pf][k][0]+dp[i.pf][k][1])%M;
        if(i.ps==1)
            forj(0,N)
                ford(k,j,0)
                    temp[j][1]+=dp[v][j-k][1]*dp[i.pf][k][1]%M;
        if(i.ps==-1)
            forj(0,N)
                ford(k,j,0)
                    temp[j][1]+=dp[v][j-k][1]*dp[i.pf][k][0]%M;
        forj(0,N)
        {
            dp[v][j][0]=temp[j][0]%M;
            dp[v][j][1]=temp[j][1]%M;
            temp[j][0]=temp[j][1]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("werewolf-1-1.in", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>W>>m; ans[0]=1;
    fori(0,m)
    {
        cin>>ch>>a>>b; a--; b--;
        if(ch=='A')
            c=-1;
        if(ch=='D')
            c=1;
        gr[a].pb({b,c});
    }
    fori(0,n)
    {
        if(vis[i])
            continue;
        dfs(i);
        ll temp[N]={0};
        forj(0,N)
            fork(0,j+1)
                temp[j]+=ans[j-k]*(dp[i][k][0]+dp[i][k][1])%M;
        forj(0,n)
            ans[j]=temp[j]%M;
    }
    cout<<ans[W];
    return 0;
}
/**

*/