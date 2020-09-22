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
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=17;
int n,x1,Y1,x2,y2,a,b,c,d,dp[N][N][N][N],t=inf;
priority_queue<pair<int,pair<pii,pii>>> toV;

void dfs()
{
    int x,y,xx,yy;
    x=toV.top().ps.pf.pf; y=toV.top().ps.pf.ps; xx=toV.top().ps.ps.pf; yy=toV.top().ps.ps.ps;
    toV.pop();
    if(x==0||x>n||y==0||y>n||xx==0||xx>n||yy==0||yy>n||xx==x&&yy==y)
        return;
    if(dp[x][y][xx][yy-1]>dp[x][y][xx][yy]+1)
    {
        dp[x][y][xx][yy-1]=dp[x][y][xx][yy]+1;
        toV.push({-dp[x][y][xx][yy-1],{{x,y},{xx,yy-1}}});
    }
    if(dp[x][y][xx][yy+1]>dp[x][y][xx][yy]+1)
    {
        dp[x][y][xx][yy+1]=dp[x][y][xx][yy]+1;
        toV.push({-dp[x][y][xx][yy+1],{{x,y},{xx,yy+1}}});
    }
    if(dp[x][y][xx-1][yy]>dp[x][y][xx][yy]+1)
    {
        dp[x][y][xx-1][yy]=dp[x][y][xx][yy]+1;
        toV.push({-dp[x][y][xx-1][yy],{{x,y},{xx-1,yy}}});
    }
    if(dp[x][y][xx+1][yy]>dp[x][y][xx][yy]+1)
    {
        dp[x][y][xx+1][yy]=dp[x][y][xx][yy]+1;
        toV.push({-dp[x][y][xx+1][yy],{{x,y},{xx+1,yy}}});
    }
    if(x==xx&&abs(y-yy)==1&&dp[xx][yy][x][y]>dp[x][y][xx][yy]+1)
    {
        dp[xx][yy][x][y]=dp[x][y][xx][yy]+1;
        toV.push({-dp[xx][yy][x][y],{{xx,yy},{x,y}}});
    }
    if(y==yy&&abs(x-xx)==1&&dp[xx][yy][x][y]>dp[x][y][xx][yy]+1)
    {
        dp[xx][yy][x][y]=dp[x][y][xx][yy]+1;
        toV.push({-dp[xx][yy][x][y],{{xx,yy},{x,y}}});
    }
    if(x==x2&&y==y2&&(x==xx&&abs(y-yy)==1||y==yy&&abs(x-xx)==1))
        t=min(t,dp[x][y][xx][yy]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>x1>>Y1>>x2>>y2>>a>>b>>c>>d;
    seto(dp,inf);
    if(a==x1&&b==Y1)
    {
        a=c;
        b=d;
    }
    dp[x1][Y1][a][b]=0; toV.push({0,{{x1,Y1},{a,b}}});
    while(!toV.empty())
        dfs();
    cout<<t;
    return 0;
}
/**

*/