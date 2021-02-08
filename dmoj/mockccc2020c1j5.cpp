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
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=100000,D=12;
ll d,n,ans,a,b,c,da,db,pw[D]={1};
bool prime[N];
vector<ll> p;
bool isprime(ll x)
{
    for(auto i:p)
        if(i<x&&x%i==0)
            return false;
    return true;
}
ll nextprime(ll x)
{
    for(x=max(x,2LL);;x++)
        if(isprime(x))
            return x;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    fori(2,N)
        if(!prime[i])
        {
            p.pb(i);
            for(int j=i;j<N;j+=i)
                prime[j]=true;
        }
    fori(1,12)
        pw[i]=pw[i-1]*10;
    cin>>d>>n; ans=INF;
    fori(d,D)
        forj(d,D)
        {
            if(i+j>=D)
                continue;
            c=pw[j]; a=n/c; b=n%c; da=pw[i-1]; db=pw[j-1];
            if(nextprime(max(b,db))<db*10)
                ans=min(ans,nextprime(max(a,da))*c+nextprime(max(b,db)));
            ans=min(ans,nextprime(max(a+1,da))*c+nextprime(db));
        }
    cout<<ans<<"\n";
    return 0;
}
/**

*/