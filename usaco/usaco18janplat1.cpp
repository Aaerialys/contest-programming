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

const int N=100010,KK=101;
int n,K,dp[KK][N][2],last[KK][N],a,b,c;
pii coww[N];
vector<pii>cow;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>K;
    fori(0,n)
        cin>>coww[i].pf>>coww[i].ps;
    sort(coww,coww+n); cow.pb({0,0});
    fori(0,n)
    {
        if(coww[i+1].pf!=coww[i].pf&&coww[i].ps>a)
            cow.pb(coww[i]);
        else
            K--;
        a=max(a,coww[i].ps);
    }
    n=cow.size(); seto(dp,-inf); dp[0][0][1]=0;
    fori(1,n)
        dp[0][i][1]=dp[0][i-1][1]+cow[i].ps-max(cow[i].pf,cow[i-1].ps);
    fori(1,K+1)
        forj(1,n)
        {
            dp[i][j][0]=max(dp[i-1][j-1][0],dp[i-1][j-1][1]);
            last[i][j]=0;
            if(dp[i-1][j-1][1]>dp[i-1][j-1][0])
                last[i][j]=j-1;
            dp[i][j][1]=max(dp[i][j-1][1]+cow[j].ps-max(cow[j].pf,cow[j-1].ps),dp[i][j-1][0]+cow[j].ps-max(cow[j].pf,cow[last[i][j-1]].ps));
        }
    cout<<max(dp[K][n-1][0],dp[K][n-1][1]);
    return 0;
}
/**

*/