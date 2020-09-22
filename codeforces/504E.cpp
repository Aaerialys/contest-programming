#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a);i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}
};
#define nl "\n"

const int N=600010,M=MOD,B=randint(300,M-1);
int n,a,b,c,d,q,sz[N],rt[N],par[N],in[N],rin[N],x,y,li,ri,l1,l2,l,ans,d1,d2;
ll hnum[N],p[N]={1};
vector<int> gr[N];
vector<pii> que1,que2,temp;
string s;
void szDfs(int v,int p=-1){
    sz[v]=1; par[v]=p;
    for(auto& i:gr[v]) if(i!=p){
        szDfs(i,v); sz[v]+=sz[i];
        if(gr[v][0]==p||sz[i]>sz[gr[v][0]]) swap(i,gr[v][0]);
    }
}
void hldDfs(int v,int p=-1){
    in[v]=++a; hnum[a]=(hnum[a-1]*B+s[v])%M; rin[in[v]]=v;
    for(auto i:gr[v]) if(i!=p){
        rt[i]=i==gr[v][0]? rt[v]: i;
        hldDfs(i,v);
    }
}
void query(int u,int v){
    while(rt[u]!=rt[v]){
        if(in[rt[u]]<in[rt[v]]){
            temp.eb(in[rt[v]],in[v]); v=par[rt[v]];
        }
        else{
            que1.eb(N-in[u],N-in[rt[u]]); u=par[rt[u]];
        }
    }
    if(in[u]>in[v]) que1.eb(N-in[u],N-in[v]);
    else que1.eb(in[u],in[v]);
}
int hsh(int l,int r){
    return (hnum[r]-hnum[l-1]*p[r-l+1]%M+M)%M;
}
int lcp(int x,int y,int r){
    int l=0,mid;
    while(l<r){
        mid=(l+r)/2;
        if(hsh(x,x+mid)==hsh(y,y+mid)) l=mid+1;
        else r=mid;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    fori(1,N) p[i]=p[i-1]*B%M;
    cin>>n>>s; s="."+s;
    fori(1,n){
        cin>>a>>b; gr[a].pb(b); gr[b].pb(a);
    }
    a=0; szDfs(1); rt[1]=1; hldDfs(1);
    ford(i,n,1) hnum[N-i]=(hnum[N-i-1]*B+s[rin[i]])%M;
    cin>>q;
    while(q--){
        cin>>a>>b>>c>>d; ans=0;
        query(a,b); reverse(all(temp)); for(auto i:temp) que1.pb(i); temp.clear(); swap(que1,que2);
        query(c,d); reverse(all(temp)); for(auto i:temp) que1.pb(i); temp.clear();
        for(li=ri=0;li<sz(que1)&&ri<sz(que2);){
            l1=que1[li].ps-que1[li].pf+1; l2=que2[ri].ps-que2[ri].pf+1; l=min(l1,l2);
            ans+=x=lcp(que1[li].pf,que2[ri].pf,l);
            if(l!=x) break;
            if(l==l1) li++;
            else que1[li].pf+=x;
            if(l==l2) ri++;
            else que2[ri].pf+=x;
        }
        cout<<ans<<nl; que1.clear(); que2.clear();
    }
    return 0;
}
/**

*/
