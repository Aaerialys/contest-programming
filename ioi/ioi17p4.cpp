//big cheese

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

const int N=200010,M=473;
int n,lol,ans,qans[N][2];
bitset<N> done,ps;

int prizes[N],cnt;/*
vector<int> ask(int x){
    vector<int> ret; ret.resize(2); cnt++;
    fori(0,x) if(prizes[i]<prizes[x]) ret[0]++;
    fori(x+1,n) if(prizes[i]<prizes[x]) ret[1]++;
    return ret;
}//*/
vector<int> ask(int x);
void query(int x){
    if(done[x]) return;
    auto ret=ask(x); qans[x][0]=ret[0]; qans[x][1]=ret[0]+ret[1]; done[x]=1; cnt++;
    if(!qans[x][1]) ans=x;
    lol=max(lol,qans[x][1]);
}
bool go(int l,int r,int v){
    if(ans!=-1||l>r) return 0;
    int mid=(l+r)/2; query(mid);
    if(qans[mid][1]<lol){
        if(ps[mid]) return go(mid+1,r,v);
        if(!go(l,mid-1,v)){
            ps[mid]=1; return 1;
        }
    }
    if(qans[mid][0]>v) return go(l,mid-1,v);
    if(qans[mid][0]<=v) return go(mid+1,r,v);
}
void init(int l,int r,int d){
    if(d>=9||l>r) return;
    int mid=(l+r)/2; query(mid);
    init(l,mid-1,d+1); init(mid+1,r,d+1);
}
int find_best(int _n){
    n=_n; ans=-1;
    init(0,n-1,0);
    fori(0,lol) go(0,n-1,i);
    //assert(cnt<=5010);
    //assert(ans!=-1);
    return ans;
}
/*
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("2-86.in", "r", stdin); //freopen("", "w", stdout);
    int n;
    vector<int> arr;
    cin>>n;
    fori(0,n) cin>>prizes[i];
    cout<<find_best(n)<<endl;
    cout<<cnt;
    return 0;
}
/**
8
2 2 2 2 2 2 2 1
*/