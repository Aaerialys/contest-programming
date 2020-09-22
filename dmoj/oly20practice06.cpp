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

const int N=1000010;
int n,m,a,b,roid,sz[N],head[N],sum[N],ans,K;
vector<int> gr[N],tr;
void dfs(int v,int p){
    sz[v]=1; head[v]=a;
    for(auto i:gr[v])
        if(i!=p){
            dfs(i,v);
            sz[v]+=sz[i];
        }
}
int getcentroid(int v,int p){
    for(auto i:gr[v]) if(i!=p&&sz[i]*2>n) return getcentroid(i,v);
    return v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(1,n){
        cin>>a>>b;
        gr[a].pb(b); gr[b].pb(a);
    }
    dfs(1,0);
    roid=getcentroid(1,0);
    for(auto i:gr[roid]){
        a=i;
        dfs(i,roid);
        tr.pb(sz[i]); sz[roid]+=sz[i];
    }
    tr.pb(inf); sort(tr.begin(),tr.end()); reverse(tr.begin(),tr.end()); m=tr.size(); tr.pb(0);
    fori(1,m) sum[i]=sum[i-1]+tr[i];
    fori(1,n+1){
        K=lower_bound(sum,sum+m,(n-sz[i]*2+1)/2)-sum; ans=inf;
        if(tr[K+1]>=sz[head[i]]) ans=K;
        else{
            K=lower_bound(sum,sum+m,(n+1)/2)-sum;
            ans=min(ans,K);
            K=lower_bound(sum,sum+m,(n+sz[head[i]]*2-sz[i]*2+1)/2)-sum-1;
            ans=min(ans,K);
        }
        if(sz[i]*2>=n) ans=0;
        cout<<ans<<"\n";
    }
    return 0;
}
/**
before: a now: b
k<a<b: sum k + sz[i]  //sum[k]*2+sz*2>=n, sum[k]*2>=n-sz*2, sum[k]>=(n-sz*2+1)/2
a<b<k: sum k          //sum[k]*2>=n sum[k]>=(n+1)/2
a<k<b: sum[k+1]-a+sz[i]     //sum[k+1]*2>=n+a*2;   sum[k+1]>=(n+a*2-sz[i]*2+1)/2;

dfs, find centroid
dfs from centroid
n-sz<=n/2
sz
5
1 2
2 3
3 4
4 5
*/