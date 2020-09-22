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

const int N=2510,M=100010;
class biTree
{
    public:
    int tree[M];
    void add(int x,int v)
    {
        if(x==0)
            return;
        while(x<M)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    int addto(int x)
    {
        x=min(x,M-1);
        int sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};
biTree bit;
int n,K,m,q,a,b,c,d,s,t,sum[N][N],x[4],y[4];
set<pii> tot[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>K>>m;
    fori(0,m)
    {
        cin>>q;
        forj(0,q)
            cin>>x[j]>>y[j];
        forj(1,pow2(q))
        {
            s=0; a=c=1; b=d=n;
            fork(0,q)
                if(j&pow2(k))
                {
                    s++;
                    a=max(a,x[k]-K+1); b=min(b,x[k]); c=max(c,y[k]-K+1); d=min(d,y[k]);
                }
            if(a<=b&&c<=d)
            {
                s=s%2*2-1; b++; d++;
                sum[a][c]+=s; sum[b][c]-=s; sum[a][d]-=s; sum[b][d]+=s;
            }
        }
    }
    fori(1,n+1)
        forj(1,n+1)
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    fori(1,n-K+2)
        forj(1,n-K+2)
        {
            tot[i].insert((pii){j,sum[i][j]});
            bit.add(sum[i][j],1);
        }
    cin>>q;
    fori(0,q)
    {
        cin>>m;
        if(m==1)
        {
            cin>>a>>c;
            b=min(n-K+1,a); a=max(1,a-K+1);
            d=min(n-K+1,c); c=max(1,c-K+1);
            forj(a,b+1)
            {
                for(auto k=tot[j].lower_bound((pii){c,0}),ENDK=tot[j].upper_bound((pii){d,inf});k!=ENDK;k++)
                    bit.add(k->ps,-1);
                tot[j].erase(tot[j].lower_bound((pii){c,0}),tot[j].upper_bound((pii){d,inf}));
            }
        }
        if(m==2)
        {
            cin>>a;
            printf("%.6f\n",1.0*(bit.addto(M-1)-bit.addto(a-1))/(n-K+1)/(n-K+1));
        }
    }
    return 0;
}
/**

*/