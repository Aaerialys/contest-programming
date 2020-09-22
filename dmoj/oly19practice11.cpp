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
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
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
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};

const int N=P2(21),M=1e9+7;

struct segTree1{
    int seg[2*N];
    segTree1(){
        seto(seg,inf);
    }
    void pull(int num){
        seg[num]=min(seg[2*num],seg[2*num+1]);
    }
    void upd(int pos,int val){
        seg[pos+=N]=val;
        for(pos/=2;pos;pos/=2) pull(pos);
    }
    int query(int l,int r){
        int ret1,ret2; ret1=ret2=inf;
        for(l+=N,r+=N+1;l<r;l/=2,r/=2){
            if(l&1) ret1=min(ret1,seg[l++]);
            if(r&1) ret2=min(seg[--r],ret2);
        }
        return min(ret1,ret2);
    }
};
struct segTree2{
    int seg[2*N];
    void pull(int num){
        seg[num]=max(seg[2*num],seg[2*num+1]);
    }
    void upd(int pos,int val){
        seg[pos+=N]=val;
        for(pos/=2;pos;pos/=2) pull(pos);
    }
    int query(int l,int r){
        int ret1,ret2; ret1=ret2=-inf;
        for(l+=N,r+=N+1;l<r;l/=2,r/=2){
            if(l&1) ret1=max(ret1,seg[l++]);
            if(r&1) ret2=max(seg[--r],ret2);
        }
        return max(ret1,ret2);
    }
};
segTree1 st1;
segTree2 st2;
ll n,l[N],r[N],x[N],a,b,ans;
vector<ll> poi;
gp_hash_table<ll,int,chash> cord;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n){
        cin>>x[i]>>b; l[i]=x[i]-b; r[i]=x[i]+b; poi.pb(l[i]); poi.pb(r[i]); poi.pb(x[i]);
    }
    sort(all(poi)); a=0;
    for(auto i:poi) cord[i]=a++;
    fori(0,n){
        x[i]=cord[x[i]]; l[i]=cord[l[i]]; r[i]=cord[r[i]];
        st1.upd(x[i],l[i]); st2.upd(x[i],r[i]);
    }
    forj(0,2){
        fori(0,n){
            l[i]=st1.query(l[i],r[i]);
            st1.upd(x[i],l[i]);
        }
        ford(i,n-1,0){
            r[i]=st2.query(l[i],r[i]);
            st2.upd(x[i],r[i]);
        }
    }
    fori(0,n) ans+=(upper_bound(x,x+n,r[i])-lower_bound(x,x+n,l[i]))*(i+1)%M;
    cout<<ans%M;
    return 0;
}

/**

*/