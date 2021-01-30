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

const int N=1000010,M=MOD,L=20;
int n,q,m,a,b,pre[N],dep[N],post[N],ans;
bitset<N> has;
vector<int> gr[N],etour,node;
vector<pii> aux[N];
stack<int> stk;
struct SparseTable{
    int st[L][N],num[N];
    int comb(int x,int y){assert(x<=N); assert(y<=N); return num[x]<num[y]? x: y;}
    void init(vector<int> arr){
        fori(0,sz(arr)){
            num[arr[i]]=dep[arr[i]];
            st[0][i]=arr[i];
        }
        fori(1,L) forj(0,N-P2(i)+1) st[i][j]=comb(st[i-1][j],st[i-1][j+P2(i-1)]);
    }
    int lca(int x,int y){
        x=pre[x]; y=pre[y];
        if(x>y) swap(x,y);
        int lvl=31-clz(y-x+1);
        return comb(st[lvl][x],st[lvl][y-P2(lvl)+1]);
    }
} st;
void dfs(int v,int p=0){
    pre[v]=sz(etour); etour.pb(v);
    for(auto i:gr[v]) if(i!=p){
        dep[i]=dep[v]+1;
        dfs(i,v);
        etour.pb(v);
    }
    post[v]=sz(etour)-1;
}
bool cmp(int x,int y){
    return pre[x]<pre[y];
}
void dfs2(int v,int p=0){
    int cnum=0;
    for(auto i:aux[v]) if(i.pf!=p){
        dfs2(i.pf,v); cnum+=has[i.pf];
        if(has[v]&has[i.pf]&&i.ps==1) ans=inf;
    }
    if(has[v]) ans+=cnum;
    else if(cnum>=2||cnum==1&&has[p]) ans++;
    else if(cnum==1) has[v]=1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(1,n){
        cin>>a>>b; gr[a].pb(b); gr[b].pb(a);
    }
    dfs(1); st.init(etour);
    cin>>q;
    while(q--){
        cin>>m;
        fori(0,m){
            cin>>a; has[a]=1;
            node.pb(a);
        }
        sort(all(node),cmp);
        fori(1,m) node.pb(st.lca(node[i],node[i-1]));
        sort(all(node)); node.erase(unique(all(node)),node.end());
        sort(all(node),cmp); a=node[0];
        for(auto i:node){
            while(sz(stk)&&post[stk.top()]<post[i])
                stk.pop();
            if(sz(stk))
                aux[stk.top()].eb(i,dep[i]-dep[stk.top()]);
            stk.push(i);
        }
        dfs2(a);
        cout<<(ans<inf? ans: -1)<<nl;
        has.reset();
        for(auto i:node) aux[i].clear();
        node.clear(); ans=0;
        while(sz(stk)) stk.pop();
    }
    return 0;
}
/**

*/