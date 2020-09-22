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

struct query
{
    int l,r,t,i;
};
const int N=10010,M=101,Q=100010;
int n,q,a,b,c,w[N],v[N],dp[N][M],ans[Q];
ll t;

void go(int l,int r,vector<query> que)
{
    if(l>r||que.empty())
        return;
    int m=(l+r)/2;
    fori(w[m],M)
        dp[m][i]=v[m];
    if(l==r)
    {
        for(auto i:que)
            ans[i.i]=dp[m][i.t];
        return;
    }
    ford(i,m-1,l)
    {
        forj(0,M)
            dp[i][j]=dp[i+1][j];
        forj(w[i],M)
            dp[i][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
    }
    fori(w[m+1],M)
        dp[m+1][i]=v[m+1];
    fori(m+2,r+1)
    {
        forj(0,M)
            dp[i][j]=dp[i-1][j];
        forj(w[i],M)
            dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
    }
    vector<query> lv,rv;
    for(auto i:que)
    {
        if(i.l>m+1)
            rv.pb(i);
        else if(i.r<m)
            lv.pb(i);
        if(i.l<=m+1&&i.r>=m)
        {
            if(i.l==m+1)
                ans[i.i]=dp[i.r][i.t];
            else if(i.r==m)
                ans[i.i]=dp[i.l][i.t];
            else
                forj(0,i.t+1)
                    ans[i.i]=max(ans[i.i],dp[i.l][j]+dp[i.r][i.t-j]);
        }
    }
    fori(l,r+1)
        forj(0,M)
            dp[i][j]=0;
    go(l,m,lv);
    go(m+1,r,rv);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in1.txt", "r", stdin); //freopen("", "w", stdout);
    vector<query> que; seto(ans,-inf);
    cin>>n;
    fori(1,n+1)
        cin>>w[i]>>v[i];
    cin>>q;
    fori(0,q)
    {
        cin>>a>>b>>c;
        que.pb({a,b,c,i});
    }
    go(1,n,que);
    fori(0,q)
        t+=ans[i];
    //fori(0,q)
        //cout<<ans[i]<<"\n";
    cout<<t;
    return 0;
}
/**

*/
