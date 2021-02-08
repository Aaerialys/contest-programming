#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i--)
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
typedef pair<double,int> pii;
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

const int N=4010;
double PI=asin(1)*2,EPS=1e-8;
int n,x[N],y[N],g[N],a,b,t,ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 
    //freopen("hares.32.in", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n)
    {
        cin>>x[i]>>y[i]>>g[i];
        b+=g[i];
    }
    fori(0,n)
    {
        vector<pii> div; a=0; t=g[i];
        forj(0,n)
            if(j!=i)
                div.pb({atan2(y[j]-y[i],x[j]-x[i]),g[j]});
        sort(div.begin(),div.end());
        forj(0,n-1)
            div.pb({div[j].pf+PI*2,div[j].ps});
        forj(0,n*2-2)
        {
            t+=div[j].ps;
            for(;div[j].pf-div[a].pf>PI;a++)
                t-=div[a].ps;
            if(a>0)
            {
                ans=max(ans,t);
                if(j==div.size()-1||div[j+1].pf>div[j].pf)
                    ans=max(ans,b-t+g[i]);

            }
        }
    }
    cout<<ans;
    return 0;
}
/**

*/