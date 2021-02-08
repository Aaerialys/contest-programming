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

const int N=200010,L=17;
int n,m,q,a,b,c,dep[N],pre[N],par[N],st[L][N*2],sum[N],l,r,mid;
vector<int> gr[N],etour;
pii que[N];
bool pos,ee[N];
void pdfs(int v,int p)
{
    pre[v]=etour.size(); etour.pb(v);
    for(auto i:gr[v])
        if(i!=p)
        {
            dep[i]=dep[v]+1;
            pdfs(i,v);
            etour.pb(v);
        }
}
int lca(int u,int v)
{
    u=pre[u]; v=pre[v];
    if(u>v)
        swap(u,v);
    int z=31-__builtin_clz(v-u+1); //!63-__builtin_clzll(r-l+1) for long long
    return (dep[st[z][u]]<dep[st[z][v-(1<<z)+1]]? st[z][u]: st[z][v-(1<<z)+1]);
}
void dfs(int v,int p)
{
    for(auto i:gr[v])
        if(i!=p)
        {
            dfs(i,v);
            sum[v]+=sum[i];
        }
    if(sum[v]>1&&ee[v])
        pos=false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q; c=n+1;
    fori(1,n)
    {
        cin>>a>>b;
        gr[a].pb(c); gr[b].pb(c); gr[c].pb(a); gr[c].pb(b);
        ee[c]=true; c++;
    }
    pdfs(1,0); m=etour.size(); r=q+1;
    fori(0,m)
        st[0][i]=etour[i];
    fori(1,L)
        forj(0,m-(1<<i)+1)
            st[i][j]=(dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]])?st[i-1][j]:st[i-1][j+(1<<(i-1))];
    fori(0,q)
        cin>>que[i].pf>>que[i].ps;
    while(l<r)
    {
        mid=(l+r)/2; seto(sum,0); pos=true;
        fori(0,mid)
        {
            sum[que[i].pf]++; sum[que[i].ps]++;
            sum[lca(que[i].pf,que[i].ps)]-=2;
        }
        dfs(1,0);
        if(pos)
            l=mid+1;
        else
            r=mid;
    }
    cout<<l-1;
    return 0;
}
/**
5 2
1 2
2 3
3 4
3 5
1 2
2 4
*/