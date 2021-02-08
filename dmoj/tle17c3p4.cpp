#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define hashmap gp_hash_table
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
#define P2(x) (1LL<<(x))
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(int x) const { return x ^ SEED; }};

const int N=1010,M=1e9+7;
int n,K,x;
double dp[N][N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>K>>x;
    dp[1][1]=1;
    fori(2,N)
        forj(1,i+1)
            dp[i][j]=(dp[i-1][j-1]*((i+K)/i*(j-1)+min((i+K)%i,j-1))+dp[i-1][j]*((i+K)/i*(i-j)+max(0,(i+K)%i-j)))/(i+K);
    if(n>1000){
        if(K==0) printf("%.7g",1.0/n);
        else if(K==1) printf("%.7g",2.0*x/n/(n+1));
        else printf("%.7g",2.0*max(3,x+1)/(n+1)/(n+2));
    }
    else printf("%.7g",dp[n][x]);
}
/**

dp[i][j]=dp[i-1][j-1]*((i+K)/i*(j-1)+min((i+K)%i,j-1))+dp[i-1][j]+(i+K/n*(n-j)+min((i+K)%i-j,

(i+2x)/x


                                                                                   1
0.5 0.5
0.3333333 0.3333333 0.3333333
0.25 0.25 0.25 0.25
0.2 0.2 0.2 0.2 0.2
0.1666667 0.1666667 0.1666667 0.1666667 0.1666667 0.1666667
0.1428571 0.1428571 0.1428571 0.1428571 0.1428571 0.1428571 0.1428571
0.125 0.125 0.125 0.125 0.125 0.125 0.125 0.125
0.1111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111

1
0.3333333 0.6666667
0.1666667 0.3333333 0.5
0.1 0.2 0.3 0.4
0.06666667 0.1333333 0.2 0.2666667 0.3333333
0.04761905 0.0952381 0.1428571 0.1904762 0.2380952 0.2857143
0.03571429 0.07142857 0.1071429 0.1428571 0.1785714 0.2142857 0.25
0.02777778 0.05555556 0.08333333 0.1111111 0.1388889 0.1666667 0.1944444 0.2222222
0.02222222 0.04444444 0.06666667 0.08888889 0.1111111 0.1333333 0.1555556 0.1777778 0.2

1
0.5 0.5
0.3 0.3 0.4
0.2 0.2 0.2666667 0.3333333
0.1428571 0.1428571 0.1904762 0.2380952 0.2857143
0.1071429 0.1071429 0.1428571 0.1785714 0.2142857 0.25
0.08333333 0.08333333 0.1111111 0.1388889 0.1666667 0.1944444 0.2222222
0.06666667 0.06666667 0.08888889 0.1111111 0.1333333 0.1555556 0.1777778 0.2
0.05454545 0.05454545 0.07272727 0.09090909 0.1090909 0.1272727 0.1454545 0.1636364 0.1818182

1
1/2 1/2
1/3 1/3 1/3
1/4 1/4 1/4 1/4
...

1
1/3 2/3
1/6 2/6 3/6
1/10 2/10 3/10
1/15 2/15 3/15 4/15
1/21 2/21 3/21 4/21 5/21
... 2k/n(n+1)

3/3
3/6 3/6
3/10 3/10 4/10
3/15 3/15 4/15 5/15
3/21 3/21 4/21 5/21 6/21
3/28
3/36
3/55


max(3,k+1)*2
/(n+1)(n+2)
*/