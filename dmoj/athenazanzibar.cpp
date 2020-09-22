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
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=1000010;
ll n,x,y,a,b,l,r,t,arr[N];
unordered_map<int,int> us;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n; t=INF;
    fori(0,n)
    {
        cin>>arr[i];
        if(us.count(arr[i])&&abs(arr[i])*2<t)
        {
            t=abs(arr[i])*2;
            x=us[arr[i]]; y=i;
        }
        if(us.count(arr[i])&&abs(arr[i])*2==t&&us[arr[i]]*1e7+i<x*1e7+y)
        {
            x=us[arr[i]]; y=i;
        }
        if(!us.count(arr[i]))
            us[arr[i]]=i;
    }
    sort(arr,arr+n);
    l=0; r=n-1;
    while(l<r)
    {
        if(abs(arr[l]+arr[r])<t)
        {
            t=abs(arr[l]+arr[r]);
            x=y=inf;
        }
        if(arr[l]+arr[r]>=0)
            r--;
        else
            l++;
    }
    for(auto i:us)
    {
        t=-t;
        if(i.pf*2!=t&&us.count(t-i.pf))
        {
            l=i.ps; r=us[t-i.pf];
            a=min(l,r); b=max(l,r);
            if(1e7*x+y>1e7*a+b)
            {
                x=a;
                y=b;
            }
        }
        t=-t;
        if(i.pf*2!=t&&us.count(t-i.pf))
        {
            l=i.ps; r=us[t-i.pf];
            a=min(l,r); b=max(l,r);
            if(1e7*x+y>1e7*a+b)
            {
                x=a;
                y=b;
            }
        }
    }

    cout<<t<<"\n"<<x+1<<" "<<y+1;
    return 0;
}
/**1595249123

*/