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

const int N=19;
ll n,m,num[N][N],R,C,rd[N],l,r,mid,ans;
bool go=true;

void next_combination()
{
    rd[R-1]++;
    ford(i,R-1,0)
    {
        if(rd[i]==n-R+i+1)
        {
            if(!i)
                go=false;
            rd[i-1]++;
            forj(i,R)
                rd[j]=rd[j-1]+1;
        }
    }
}
ll sum (int x1,int y1,int x2,int y2)
{
    return num[x1][y1]+num[x2][y2]-num[x1][y2]-num[x2][y1];
}
ll pos(ll x)
{
    ll a,b,t; a=b=t=0;
    fori(1,m+1)
    {
        b=max(sum(0,a,rd[0],i),sum(rd[R-1],a,n,i));
        forj(1,R)
            b=max(b,sum(rd[j-1],a,rd[j],i));
        if(b>x)
        {
            if(i==a+1)
                return inf;
            t++;
            a=i-1;
            b=max(sum(0,a,rd[0],i),sum(rd[R-1],a,n,i));
            forj(1,R)
                b=max(b,sum(rd[j-1],a,rd[j],i));
            if(b>x)
                return inf;
        }
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>R>>C; ans=INF;
    fori(1,n+1)
        forj(1,m+1)
            cin>>num[i][j];
    fori(1,n+1)
        forj(1,m+1)
            num[i][j]+=num[i][j-1]+num[i-1][j]-num[i-1][j-1];
    fori(0,R)
        rd[i]=i+1;
    while(go)
    {
        l=0; r=inf;
        while(l<r)
        {
            mid=(l+r)/2;
            if(pos(mid)<=C)
                r=mid;
            else
                l=mid+1;
        }
        ans=min(ans,r);
        next_combination();
    }
    cout<<ans;
    return 0;
}
/**

*/