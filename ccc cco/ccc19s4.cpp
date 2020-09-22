#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(ll i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(ll j=a,ENDJ=b;j<ENDJ;j++)
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

const int N=1000100;
long long l,n,k,dp[N],dp2[N],st[21][N],day[N];
deque<int> dq,dq2;

long long rmq(int a,int b)
{
    l=31-__builtin_clz(b-a+1);
    return max(st[l][a],st[l][b-(1<<l)+1]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>k;
    l=32-__builtin_clz(n);
    fori(1,n+1)
    {
        cin>>st[0][i];
        day[i]=(i+k-1)/k;
    }
    fori(1,l+1)
        forj(1,n+1)
            if(j+(1<<(i))-1<=n)
                st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    for(int i=1;i<=n;i++)
    {
        if(day[i]!=day[i-1])
        {
            forj(max(0LL,i-k),i)
            {
                while(dq.size()&&dp[dq.back()]+rmq(dq.back()+1,i)<dp[j]+rmq(j+1,i))
                    dq.pop_back();
                dq.pb(j);
                while(dq2.size()&&dp[dq2.back()]<dp[j])
                    dq2.pop_back();
                dq2.pb(j);
            }
        }
        while(dq.front()<i-k)
            dq.pop_front();
        while(dq2.front()<i-k)
            dq2.pop_front();
        dp[i]=max(dp[dq.front()]+rmq(dq.front()+1,i),dp[dq2.front()]+rmq(dq2.front()+1,i));
    }
    cout<<dp[n];
    return 0;
}
/**

*/