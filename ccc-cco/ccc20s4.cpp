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

const int N=1000010;
int n,A[N],B[N],C[N],a,b,c,t,ans;
string in;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>in; n=in.size(); ans=inf;
    fori(1,n+1){
        if(in[i-1]=='A')
            A[i]++;
        if(in[i-1]=='B')
            B[i]++;
        if(in[i-1]=='C')
            C[i]++;
        A[i]+=A[i-1]; B[i]+=B[i-1]; C[i]+=C[i-1];
    }
    a=A[n]; b=B[n]; c=C[n];
    fori(0,n)
    {
        if(i>a+b)
        {
            ans=min(ans,a-A[i]+A[i-a]+b-B[i-a]+B[i-a-b]-min(B[i]-B[i-a],A[i-a]-A[i-a-b]));
            ans=min(ans,b-B[i]+B[i-b]+a-A[i-b]+A[i-b-a]-min(A[i]-A[i-b],B[i-b]-B[i-b-a]));
        }
        if(i>a+c)
        {
            ans=min(ans,a-A[i]+A[i-a]+c-C[i-a]+C[i-a-c]-min(C[i]-C[i-a],A[i-a]-A[i-a-c]));
            ans=min(ans,c-C[i]+C[i-c]+a-A[i-c]+A[i-c-a]-min(A[i]-A[i-c],C[i-c]-C[i-c-a]));
        }
        if(i>b+c)
        {
            ans=min(ans,c-C[i]+C[i-c]+b-B[i-c]+B[i-c-b]-min(B[i]-B[i-c],C[i-c]-C[i-c-b]));
            ans=min(ans,b-B[i]+B[i-b]+c-C[i-b]+C[i-b-c] -min(C[i]-C[i-b],B[i-b]-B[i-b-c]));
        }
    }
    cout<<ans;
    return 0;
}
/**
AAABBBAAB
*/