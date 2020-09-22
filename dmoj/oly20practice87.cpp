#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") #pragma GCC optimize "unroll-loops" #pragma GCC optimize "prefetch-loop-arrays" #pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
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
typedef pair<int,ll> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%MOD*a%MOD; return t*t%MOD;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{ll operator()(ll x) const{x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl "\n"

const int N=41,M=4500007;
int n,arr[N],mi,ma,z;
ll a,b,c,y,w;
pii ans[N];
struct hashmap{
    ll key[M];
    pii val[M];
    int to[M],nxt[M],vis[M],sz,null=1;
    void clear(){
        sz=0; null++;
    }
    pii upd(ll x,pii v){
        int cur=x%M;
        if(vis[cur]!=null){vis[cur]=null; to[cur]=-1;}
        for(cur=to[cur];cur!=-1;cur=nxt[cur]) if(key[cur]==x){
            if(v.pf<val[cur].pf) val[cur]=v;
            else if(v.pf==val[cur].pf) val[cur].ps+=v.ps;
            return val[cur];
        }
        cur=x%M; nxt[sz]=to[cur]; to[cur]=sz; val[sz]=v; key[sz]=x;
        return val[sz++];
    }
} mp[2];
hashmap *pre=&mp[0],*cur=&mp[1];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("des2a.in", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n) cin>>arr[i];
    cur->upd(0,{0,1});
    fori(0,n){
        //cout<<i<<" "<<cur.sz<<nl;
        swap(cur,pre); cur->clear();
        a=b=c=mi=0; ma=n+1;
        forj(i+1,n){
            if(arr[j]<arr[i]) mi=max(mi,arr[j]);
            if(arr[j]>arr[i]) ma=min(ma,arr[j]);
        }
        forj(0,n+1){
             if(j>=arr[i]) a|=P2(j);
             if(mi<=j&&j<arr[i]) b|=P2(j);
             if(arr[i]<=j&&j<ma) c|=P2(j);
        }
        fork(0,pre->sz){
            auto j=make_pair(pre->key[k],pre->val[k]);
            y=j.pf&c; z=popcountll(j.pf&b)+mi;
            w=j.pf^y|(y>>arr[i]-z);
            cur->upd(w,j.ps);
            w|=P2(z+popcountll(y)); j.ps.pf+=popcountll(j.pf&a);
            cur->upd(w,j.ps);
        }
    }
    fori(0,cur->sz) ans[popcountll(cur->key[i])]=cur->val[i];
    fori(1,n+1) cout<<ans[i].pf<<" "<<ans[i].ps<<nl;
    return 0;
}
/**
1 5 513 517
*/