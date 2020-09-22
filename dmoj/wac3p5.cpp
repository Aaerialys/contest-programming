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
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=5010;
ll n,dp[N][N],x,t,k;
pii rod[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(1,n+1)
    {
        cin>>rod[i].pf>>rod[i].ps;
        t+=rod[i].ps;
    }
    sort(rod,rod+n+1); dp[1][0]=rod[1].ps;
    fori(1,n+1)
        forj(0,i)
        {
            k=upper_bound(rod,rod+n+1,(pii){rod[i].pf-rod[j].pf,inf})-rod-1; k=min(k,j-1LL);
            dp[i][j]=max(dp[i][j],dp[j][k]+rod[i].ps);
            if(j)
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            x=max(x,dp[i][j]);
        }
    cout<<t-x;
    return 0;
}
/**

a,b,c,d,e,
1 2 3 5
j> dp[i][j]

5
1 1
3 5
5 3
7 9
9 2

10
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
*/