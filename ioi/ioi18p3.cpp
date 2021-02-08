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

const int N=P2(18),M=MOD,L=18;
struct SegTree{
    int seg[2*N];
    void pull(int x){seg[x]=max(seg[2*x],seg[2*x+1]);}
    void upd(int x,int v){
        seg[x+=N]=v;
        for(x/=2;x;x/=2) pull(x);
    }
    int query(int l,int r){
        int ret=-inf;
        for(l+=N,r+=N+1;l<r;l/=2,r/=2){
            if(l&1) ret=max(ret,seg[l++]);
            if(r&1) ret=max(seg[--r],ret);
        }
        return ret;
    }
} st;
int n,m,q,a,b,c,d,x,y,in1[N],ou1[N],in2[N],ou2[N],p1[L][N],p2[L][N];
vector<int> gr1[N],gr2[N],ans;
vector<pii> node,e;
vector<tuple<int,int,int,int,int>> que;
struct DSU{
    int p[N];
    DSU(){reset();}
    void reset(){seto(p,-1);}
    int head(int x){return p[x]<0?x:p[x]=head(p[x]);}
    bool link(int x,int y,function<bool(int,int)> cmp){
        x=head(x); y=head(y);
        if(x==y) return 0;
        if(cmp(x,y)) swap(x,y);
        p[y]=x; gr2[x].pb(y);
        return 1;
    }
} dsu;
void dfs(int v){
    in2[v]=++a;
    for(auto i:gr2[v]) dfs(i),p2[0][i]=v;
    ou2[v]=a;
}

vector<int> check_validity(int _n,vector<int> _x,vector<int> _y,vector<int> _s, vector<int>_e, vector<int>_l,vector<int> _r){
    n=_n; m=sz(_x); q=sz(_s); ans.resize(q);
    fori(0,m){
        if(_x[i]>_y[i]) swap(_x[i],_y[i]);
        e.eb(_x[i],_y[i]);
    }
    sort(all(e)); reverse(all(e));
    for(auto i:e) dsu.link(i.pf,i.ps,greater<int>());
    a=0; dfs(0);
    fori(1,L) forj(0,n) p2[i][j]=p2[i-1][p2[i-1][j]];
    for(auto& i:e) swap(i.pf,i.ps);
    sort(all(e)); swap(gr2,gr1); swap(in1,in2); swap(ou1,ou2); dsu.reset(); swap(p1,p2);
    for(auto i:e) dsu.link(i.pf,i.ps,less<int>());
    a=0; dfs(n-1); p2[0][n-1]=n-1;
    fori(1,L) forj(0,n) p2[i][j]=p2[i-1][p2[i-1][j]];
    fori(0,n) node.eb(in1[i],in2[i]);
    fori(0,q){
        a=_s[i]; b=_e[i];
        ford(j,L-1,0) if(p1[j][a]>=_l[i]) a=p1[j][a];
        ford(j,L-1,0) if(p2[j][b]<=_r[i]) b=p2[j][b];
        que.eb(ou1[a],in1[a],in2[b],ou2[b],i);
    }
    sort(all(node)); node.eb(inf,inf); sort(all(que));
    for(auto i:que){
        tie(a,b,c,d,y)=i;
        for(;node[x].pf<=a;x++) st.upd(node[x].ps,node[x].pf);
        ans[y]=st.query(c,d)>=b;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    int n,m,q,a,b,c,d; vector<int> x,y,s,e,l,r,ans;
    cin>>n>>m>>q;
    fori(0,m){
        cin>>a>>b; x.pb(a); y.pb(b);
    }
    fori(0,q){
        cin>>a>>b>>c>>d; s.pb(a); e.pb(b); l.pb(c); r.pb(d);
    }
    ans=check_validity(n,x,y,s,e,l,r);
    fori(0,q) cout<<ans[i]<<nl;
    return 0;
}
/**
6 6 3
5 1
1 2
1 3
3 4
3 0
5 2
4 2 1 2
4 2 2 2
5 4 3 4
*/