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

const int N=200010;
ll n,m,x,tr[N],h[N],l,r=1e9,mid;
ll t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m;
    fori(0,n)
        cin>>tr[i];
    sort(tr,tr+n);
    while(l<r)
    {
        mid=(l+r)/2; x=mid*2;
        fori(1,n)
            x+=min(tr[i]-tr[i-1]-1,mid*2);
        if(x<m)
            l=mid+1;
        else
            r=mid;
    }
    r--; x=0;
    t=r*(r+1);
    fori(tr[0]-r,tr[0])
        h[x++]=i;
    fori(tr[n-1]+1,tr[n-1]+r+1)
        h[x++]=i;
    fori(1,n)
    {
        l=tr[i]-tr[i-1]-1;
        if(l>r*2)
        {
            t+=r*(r+1);
            forj(tr[i-1]+1,tr[i-1]+r+1)
                h[x++]=j;
            forj(tr[i]-r,tr[i])
                h[x++]=j;
        }
        else
        {
            t+=l/2*(l/2+1)/2;
            l++;
            t+=l/2*(l/2+1)/2;
            forj(tr[i-1]+1,tr[i])
                h[x++]=j;
        }
    }
    r++;
    fori(0,n)
    {
        if(x<m)
            if(i==0||tr[i]-tr[i-1]>r*2-1)
            {
                t+=r;
                h[x++]=tr[i]-r;
            }
        if(x<m)
            if(i==n-1||tr[i+1]-tr[i]>r*2)
            {
                t+=r;
                h[x++]=tr[i]+r;
            }
    }
    cout<<t<<"\n";
    fori(0,m)
        cout<<h[i]<<" ";
    return 0;
}
/**

*/
