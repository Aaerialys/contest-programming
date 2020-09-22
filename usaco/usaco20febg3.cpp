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

const int N=100010;
int n,k,a,b,sz[N],op;
vector<int> gr[N];
bool pos[N];
void dfs(int v,int p)
{
    map<int,int> clen; int cnt=0;
    for(auto i:gr[v])
        if(i!=p)
        {
            dfs(i,v);
            if(!pos[k])
                return;
            if(sz[i]*2==k)
                clen[sz[i]]^=1;
            else if(sz[i])
            {
                clen[sz[i]]++; clen[k-sz[i]]--;
            }
            sz[v]+=sz[i];
        }
    sz[v]++; sz[v]%=k;
    for(auto i:clen)
        if(i.ps>0)
            cnt+=i.ps;
    if(cnt>1)
        pos[k]=false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(1,n)
    {
        cin>>a>>b;
        gr[a].pb(b); gr[b].pb(a);
    }
    fori(1,n+1)
        if(gr[i].size()>2)
            op++;
    fori(1,n)
        if((n-1)%i==0)
        {
            if(i>12&&(!pos[5]&&i%5==0||!pos[7]&&i%7==0||!pos[11]&&i%11==0)) continue;
            k=i; pos[k]=true; seto(sz,0);
            dfs(1,1);
        }
    fori(1,n)
        cout<<pos[i];
    return 0;
}
/**
*/