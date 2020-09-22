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
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl "\n"

const int N=P2(21),L=21,M=1e9+7;
struct BITree{
    ll bit[N];
    void upd(int x,ll v){
        for(;x<N;x+=x&-x) bit[x]+=v;
    }
    ll query(int x){
        ll ret=0;
        for(;x;x-=x&-x) ret+=bit[x];
        return ret;
    }
};
struct BITrange{
    BITree bit[2];
    void upd(int x,ll v){
        bit[1].upd(1,v); bit[1].upd(x+1,-v);
        bit[0].upd(x+1,x*v);
    }
    void upd(int l,int r,ll v){
        upd(l-1,-v); upd(r,v);
    }
    ll query(int x){
        return bit[1].query(x)*x+bit[0].query(x);
    }
};
struct SparseTable{
    int dep[N],st[L][N],in[N];
    int comb(int a,int b){
        return dep[a]<dep[b]? a:b;
    }
    void init(){
        fori(1,L) forj(0,N-P2(i)+1) st[i][j]=comb(st[i-1][j],st[i-1][j+P2(i-1)]);
    }
    int query(int a,int b){
        a=in[a]; b=in[b]; if(a>b) swap(a,b);
        int lvl=31-clz(b-a+1);
        return comb(st[lvl][a],st[lvl][b-P2(lvl)+1]);
    }
};
BITrange biti,bito;
SparseTable st;
int n,q,rt,arr[N],in[N],out[N],sz[N],par[N],a,b,c;
vector<int> gr[N];
int dfs(int v,int p=0){
    sz[v]=1; in[v]=a++; par[v]=p; st.dep[v]=st.dep[p]+1; st.in[v]=c; st.st[0][c++]=v;
    for(auto i:gr[v]) if(i!=p){
        sz[v]+=dfs(i,v); st.st[0][c++]=v;
    }
    out[v]=b++;
    return sz[v];
}
ll query(int v){
    return biti.query(in[v])-bito.query(out[v]-sz[v]);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q>>rt;
    fori(1,n+1) cin>>arr[i];
    fori(1,n){
        cin>>a>>b;
        gr[a].pb(b); gr[b].pb(a);
    }
    a=b=c=1;
    dfs(rt);
    fori(1,n+1) biti.upd(in[i],in[i],arr[i]);
    fori(1,n+1) bito.upd(out[i],out[i],arr[i]);
    st.init();
    while(q--){
        cin>>a>>b>>c;
        if(a==1){
            biti.upd(in[b],in[b],c); bito.upd(out[b],out[b],c);
        }
        else if(a==2){
            biti.upd(in[b],in[b]+sz[b]-1,c); bito.upd(out[b]-sz[b]+1,out[b],c);
        }
        else if(a==3) cout<<query(b)+query(c)-query(st.query(b,c))-query(par[st.query(b,c)])<<nl;
    }
    return 0;
}
/**
11 31864
3 26943
7 26706 25131 0
9 25738 6798 0
1 19919
9 5126 136 0
2 26544 18807 432
1 5041
10 17616 31035 432
3 31807
4 32187
1 4838
3 16420
11 10309
*/