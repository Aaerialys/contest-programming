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

const int N=1000010,M=MOD,L=21;
int n,a,b,pre[N],post[N],mark[N];
ll dep[N],ca[N],cb[N],ans;
vector<int> node;
vector<pll> gr[N],aux[N];
stack<int> stk;
struct SparseTable{
    int st[L][N*2];
    int comb(int x,int y){return dep[x]<dep[y]? x: y;}
    void init(vector<int> arr){
        fori(0,sz(arr)) st[0][i]=arr[i];
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
    pre[v]=sz(node); node.pb(v);
    for(auto i:gr[v]) if(i.pf!=p){
        dep[i.pf]=dep[v]+i.ps;
        dfs(i.pf,v);
        node.pb(v);
    }
    post[v]=sz(node)-1;
}
bool cmp(int x,int y){
    return pre[x]<pre[y];
}
void dfs2(int v){
    if(mark[v]==1) ca[v]=0;
    if(mark[v]==2) cb[v]=0;
    for(auto i:aux[v]){
        dfs2(i.pf);
        ca[v]=min(ca[v],ca[i.pf]+i.ps); cb[v]=min(cb[v],cb[i.pf]+i.ps);
    }
    ans=min(ans,ca[v]+cb[v]);
}
void Init(int _N,int* A,int* B,int *D){
    n=_N;
    fori(0,n-1){
        gr[A[i]].eb(B[i],D[i]); gr[B[i]].eb(A[i],D[i]);
    }
    dfs(0); st.init(node); node.clear(); seto(ca,inf); seto(cb,inf);
}
long long Query(int S,int* X,int T,int* Y){
    ans=INF;
    fori(0,S){
        node.pb(X[i]); mark[X[i]]=1;
    }
    fori(0,T){
        node.pb(Y[i]); mark[Y[i]]=2;
    }
    sort(all(node),cmp); n=sz(node);
    fori(1,n) node.pb(st.lca(node[i],node[i-1]));
    sort(all(node)); node.erase(unique(all(node)),node.end()); sort(all(node),cmp);
    for(auto i:node){
        while(sz(stk)&&post[stk.top()]<post[i]) stk.pop();
        if(sz(stk)) aux[stk.top()].eb(i,dep[i]-dep[stk.top()]);
        stk.push(i);
    }
    dfs2(node[0]);
    for(auto i:node){
        ca[i]=cb[i]=INF; mark[i]=0;
        aux[i].clear();
    }
    node.clear();
    while(sz(stk)) stk.pop();
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("03-01.txt", "r", stdin); //freopen("", "w", stdout);
    int _n,q,A[N],B[N],C[N],S,T,X[N],Y[N]; ll _ans[N],xx;
    cin>>_n>>q;
    fori(0,_n-1){
        cin>>A[i]>>B[i]>>C[i];
    }
    Init(_n,A,B,C);
    fori(0,q){
        cin>>S>>T;
        forj(0,S) cin>>X[j];
        forj(0,T) cin>>Y[j];
        ans=inf;
        if(i==5) forj(0,S) fork(0,T){
            ans=min(ans,dep[X[j]]+dep[Y[k]]-2*dep[st.lca(X[j],Y[k])]);
        }
        _ans[i]=Query(S,X,T,Y);
    }
    freopen("03-01 (2).txt", "r", stdin);
    fori(0,q){
        cin>>xx;
        if(xx!=_ans[i]) cout<<i<<" "<<_ans[i]<<" "<<xx<<nl;
    }
    return 0;
}
/**

*/