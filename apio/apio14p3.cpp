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

const int N=200010;
int n,a,b,c,t,dp[N][4]; //! up1 up2 down1 down2
vector<pii> gr[N];
void dfs(int v,int p,int d)
{
    int m1,n1,m0,m3,n3; m0=0; m1=n1=m3=n3=0;
    for(auto i:gr[v])
    {
        if(i.pf==p)
            continue;
        dfs(i.pf,v,i.ps);
        dp[v][3]+=dp[i.pf][2];
        if(dp[i.pf][1]-dp[i.pf][2]>dp[m1][1]-dp[m1][2])
        {
            n1=m1;
            m1=i.pf;
        }
        else if(dp[i.pf][1]-dp[i.pf][2]>dp[n1][1]-dp[n1][2])
            n1=i.pf;
        if(dp[i.pf][3]-dp[i.pf][2]>dp[m3][3]-dp[m3][2])
        {
            n3=m3;
            m3=i.pf;
        }
        else if(dp[i.pf][3]-dp[i.pf][2]>dp[n3][3]-dp[n3][2])
            n3=i.pf;
        m0=max(m0,dp[i.pf][0]-dp[i.pf][2]);
    }
    if(m1==m3)
    {
        dp[v][1]=max(dp[v][3]+d,dp[v][3]+m0+d,dp[v][3]+max(dp[m1][1]-dp[m1][2]+dp[n3][3]-dp[n3][2],dp[n1][1]-dp[n1][2]+dp[m3][3]-dp[m3][2])+d);
        dp[v][0]=max(dp[v][3],dp[v][3]+dp[m1][1]-dp[m1][2]+d,dp[v][3]+m0,dp[v][3]+max(dp[m1][1]-dp[m1][2]+dp[n3][3]-dp[n3][2],dp[n1][1]-dp[n1][2]+dp[m3][3]-dp[m3][2]));
    }
    else
    {
        dp[v][1]=max(dp[v][3]+d,dp[v][3]+m0+d,dp[v][3]+dp[m1][1]-dp[m1][2]+dp[m3][3]-dp[m3][2]+d);
        dp[v][0]=max(dp[v][3],dp[v][3]+dp[m1][1]-dp[m1][2]+d,dp[v][3]+m0,dp[v][3]+dp[m1][1]-dp[m1][2]+dp[m3][3]-dp[m3][2]);
    }
    dp[v][2]=max(dp[v][3],dp[v][3]+dp[m3][3]-dp[m3][2]+d);
    dp[v][3]+=d;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("13", "r", stdin); //freopen("", "w", stdout);
    cin>>n; dp[0][2]=inf;
    fori(1,n)
    {
        cin>>a>>b>>c;
        gr[a].pb({b,c});
        gr[b].pb({a,c});
    }
    dfs(1,-1,0);
    cout<<dp[1][1];
    return 0;
}
/**

0: 21d,2,20, 213
1: 2d,20d, 213d
2: 23d,2
3: 2d

0
0
0
0
0
0
0
0
0
0
16
24
26
40
0
0
4
0
0
0
3
14
0
0
17
0
0
0
0
0
9
0
0
0
0
32
0
0
0
0
0
0
0
0
0
9
35
0
0
13
0
0
0
12
0
25
104
219
0
0
10
17
0
0
0
0
8
0
0
11
30
45
0
0
0
0
0
0
0
0
0
8
43
0
0
0
68
87
395
0
0
7
0
0
0
11
426
430
438
441
441
*/