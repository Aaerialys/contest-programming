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

const int N=5010,M=MOD;
int n,m,out[N],v;
vector<int> gr[N],rg[N];
bitset<N> prop,fuel,ans,temp;
bitset<N> acc(bitset<N> to,bool p){
    queue<int> toV;
    fori(0,n) out[i]=sz(gr[i]);
    fori(0,n) if(!ans[i]){
        out[i]=to[i]=0;
        for(auto j:rg[i]) if(out[j]) out[j]--;
    }
    fori(0,n) if(to[i]) toV.push(i),out[i]=0;
    while(sz(toV)){
        v=toV.front(); toV.pop();
        to[v]=1;
        for(auto i:rg[v]) if(out[i]){
            if(prop[i]==p) out[i]=0,toV.push(i);
            else if(!--out[i]) toV.push(i);
        }
    }
    return to;
}

vector<int> who_wins(vector<int> _a,vector<int> _r,vector<int> _u,vector<int> _v){
    n=sz(_a); m=sz(_u); ans.set();
    fori(0,n) prop[i]=_a[i];
    fori(0,n) fuel[i]=_r[i];
    fori(0,m) gr[_u[i]].pb(_v[i]),rg[_v[i]].pb(_u[i]);
    while(1){
        temp=acc(fuel,1).flip();
        if(!(ans&temp).any()) break;
        ans&=acc(temp,0).flip();
    }
    vector<int> ret; ret.resize(n);
    fori(0,n) ret[i]=ans[i];
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("2-08.in", "r", stdin); //freopen("", "w", stdout);
    int n,m,a,b; vector<int> own,r,u,v,ans;
    cin>>n>>m; own.resize(n); r.resize(n); u.resize(m); v.resize(m);
    fori(0,n) cin>>own[i];
    fori(0,n) cin>>r[i];
    fori(0,m) cin>>u[i]>>v[i];
    ans=who_wins(own,r,u,v);
    fori(0,n) cout<<ans[i]<<nl;
    return 0;
}
/**
15 65
0 1 1 1 0 1 1 1 1 0 1 1 1 1 1
0 0 1 0 1 1 0 1 0 0 0 0 0 0 0
9 2
0 9
4 4
13 10
1 5
7 4
12 11
4 7
6 4
4 2
13 6
1 8
12 2
12 5
12 12
0 6
10 4
2 3
14 14
14 8
13 7
13 13
11 12
2 14
14 11
6 7
9 1
3 4
9 10
13 1
5 7
6 0
10 9
2 11
10 8
10 1
10 10
2 8
4 8
11 14
1 6
12 14
0 12
4 11
0 10
5 9
1 9
4 1
2 2
10 13
11 6
4 14
11 11
14 1
9 6
14 2
3 7
7 8
11 1
8 8
5 6
1 7
3 8
0 5
6 9


*/