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

const int N=100010,M=1e9+7;
ll dp[N][101][4],a,b,c;
int n,K,d[N],sz[N];
vector<int> gr[N];
bool pos=true;

void dfs(int v,int p)
{
    dp[v][0][0]=dp[v][0][1]=dp[v][1][2]=dp[v][1][3]=1; sz[v]=1;
    ll temp[101][4];
    if(d[v]>201)
        pos=false;
    if(!pos)
        return;
    for(auto i:gr[v])
    {
        seto(temp,0);
        if(i!=p)
        {
            d[i]=d[v]+1;
            dfs(i,v);
            sz[v]+=sz[i];
            forj(0,min(sz[v],K)+1)
            {
                fork(0,min(j,sz[i])+1)
                {
                    temp[j][0]+=dp[v][j-k][0]*dp[i][k][1]%M;
                    temp[j][1]+=dp[v][j-k][1]*(dp[i][k][1]+dp[i][k][3])%M;
                    if(k<j+1)
                    {
                        temp[j][2]+=dp[v][j-k][2]*(dp[i][k][0]+dp[i][k][1])%M;
                        temp[j][3]+=dp[v][j-k][3]*(dp[i][k][0]+dp[i][k][1]+dp[i][k][2]+dp[i][k][3])%M;
                    }
                }
            }
            fori(0,K+1)
            {
                dp[v][i][0]=temp[i][0]%M;
                dp[v][i][2]=temp[i][2]%M;
                dp[v][i][1]=temp[i][1]%M;
                dp[v][i][3]=temp[i][3]%M;
            }
        }
    }
    fori(0,K+1)
    {

        dp[v][i][1]=(dp[v][i][1]-dp[v][i][0]+M)%M;
        dp[v][i][3]=(dp[v][i][3]-dp[v][i][2]+M)%M;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in1.txt", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>K;
    fori(1,n)
    {
        cin>>a>>b;
        gr[a].pb(b); gr[b].pb(a);
    }
    dfs(1,-1);
    cout<<(dp[1][K][1]+dp[1][K][3])%M;
    return 0;
}
/**

*/
