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
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=300010,L=19;
ll n,m,q,sum[N],st[L][N],l,r,x,cnt;
pii ans[N];
pair<pii,int> que[N];
deque<ll> brw,bri;
ll mi(int l,int r)
{
    int z=31-__builtin_clz(r-l+1); //!63-__builtin_clzll(r-l+1) for long long
    return min(st[z][l],st[z][r-(1<<z)+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>q; n++; seto(st,inf);
    fori(1,n)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
        st[0][i]=sum[i];
    }
    fori(1,L)
        forj(0,n-(1<<i)+1)
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    fori(0,q)
    {
        cin>>l>>r; que[i].pf.pf=l; que[i].pf.ps=r; que[i].ps=i;
        ans[i].pf=sum[r]-sum[l-1]+m-min(0LL,mi(l-1,r)-sum[l-1]+m);
    }
    sort(que,que+q); reverse(que,que+q); x=n-1;
    for(auto i:que)
    {
        if(++cnt>q)
            break;
        for(;x>=i.pf.pf;x--)
        {
            while(!brw.empty()&&-brw[0]>=sum[x])
            {
                brw.pop_front();
                bri.pop_front();
            }
            brw.push_front(-sum[x]);
            bri.push_front(x);
        }
        l=upper_bound(bri.begin(),bri.end(),i.pf.ps)-bri.begin();
        r=upper_bound(brw.begin(),brw.end(),-(sum[i.pf.pf-1]-m))-brw.begin();
        ans[i.ps].ps=max(0LL,l-r);
    }
    fori(0,q)
        cout<<ans[i].pf<<" "<<ans[i].ps<<"\n";
    return 0;
}
/**

*/