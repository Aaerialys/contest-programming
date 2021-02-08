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
int n,a,b,l,r=N,mid,K,dp[N];
vector<int> gr[N];
bool pos;
void dfs(int v,int p){
    multiset<int> len1; vector<int> len2; int x,y=0;
    for(auto i:gr[v])
        if(i!=p){
            dfs(i,v);
            if(!pos)
                return;
            len1.insert(dp[i]);
        }
    while(len1.size())
    {
        x=*len1.begin(); len1.erase(len1.begin());
        if(x>=K){
            len2.pb(x);
        }
        else{
            if(len1.lower_bound(K-x)!=len1.end())
            {
                if(*len1.lower_bound(K-x)>=K)
                    y=max(y,x);
                len1.erase(len1.lower_bound(K-x));
            }
            else
                len2.pb(x);
        }
    }
    x=0;
    for(auto i:len2)
        dp[v]=max(dp[v],i);
    for(auto i:len2)
        if(i<K){
            dp[v]=i;
            x++;
        }
    if(dp[v]==0)
        dp[v]=y;
    dp[v]++;
    if(x>1)
        pos=false;
    if(v==1&&x)
        pos=false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(1,n){
        cin>>a>>b;
        gr[a].pb(b); gr[b].pb(a);
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    while(l<r){
        mid=(l+r)/2;
        K=mid; pos=true; seto(dp,0);
        dfs(1,1);
        if(pos)
            l=mid+1;
        else
            r=mid;
    }
    a=l-1;
    cout<<l-1;
    return 0;
}
/**
*/