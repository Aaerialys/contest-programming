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

const int M=1e9+1;
ll N,n,a,b,c,A,B,C,dp[20][2054],p[20]={1},t,ans=1;
bool pos;
double EPS=1e-8;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    fori(1,20)
        p[i]=p[i-1]*2;
    cin>>N;
    foru(ii,1,N+1)
    {
        if(ii%3==0||ii%2==0)
            continue;
        seto(dp,0);
        fori(0,2024)
            dp[0][i]=1;
        n=N/ii; t=0;
        A=log2(n)+1+EPS;
        fori(0,A)
        {
            B=log2(n/p[i])/log2(3)+1+EPS;
            forj(0,p[B])
            {
                if((j&(j<<1))||(j&(j>>1)))
                    continue;
                if(i==A-1)
                {
                    t+=dp[i][j];
                    continue;
                }
                vector<int> on;
                fork(0,B)
                    if(!(j&p[k]))
                        on.pb(k);
                C=on.size();
                fork(0,p[C])
                {
                    a=0;
                    foru(l,0,C)
                        if(k&p[l])
                            a+=p[on[l]];
                    dp[i+1][a]=(dp[i+1][a]+dp[i][j])%M;
                }
            }
        }
        ans=ans*t%M;
    }
    cout<<ans;
    return 0;
}
/**
100 481840513 120908651
9616*114*49*33*12*8*8*8*8*5*5*3*3*3
*/