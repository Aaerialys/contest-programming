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
#define nl "\n";

const int N=200010,M=1e9+7;
typedef struct node* sp;
struct node{
    int id;
    int sz;
    sp c[2],p;
    node(int i){
        id=i; sz=1;
        c[0]=c[1]=p=nullptr;
    }
    friend int Sz(sp x){return x?x->sz:0;}
    void push(){
        return;
    }
    void pull(){
        sz=1+Sz(c[0])+Sz(c[1]);
    }
    friend sp push(sp x){if(x) x->push(); return x;}
    friend sp pull(sp x){if(x) x->pull(); return x;}
    bool dir(){
        return p&&p->c[1]==this;
    }
    friend void connect(sp x,sp y,bool d){
        if(x) x->c[d]=y;
        if(y) y->p=x;
    }
    void rot(){
        int d = dir(); sp x=p;
        connect(x->p,this,x->dir()); connect(x,c[d^1],d); connect(this,x,d^1);
        x->pull(); pull();
    }
};
void splay(sp x){
    if(!x) return;
    sp y=x->p;
    while(x->p){
        y=x->p; push(y->p); push(y); push(x);
        if(y->p) x->dir()==y->dir()? y->rot(): x->rot();
        x->rot();
    }
}
sp findind(sp x,int ind){
    if(!x) return x;
    push(x);
    if(Sz(x->c[0])>=ind){
        if(!x->c[0]) splay(x);
        return findind(x->c[0],ind);
    }
    if(Sz(x->c[0])+1<ind&&x->c[1]) return findind(x->c[1],ind-Sz(x->c[0])-1);
    splay(x);
    return x;
}
sp merge(node *l,node *r){
    if(!l) return r;
    l=findind(l,Sz(l));
    connect(l,r,1);
    return pull(l);
}
sp in[N],out[N];
int getRoot(int a){
    sp x=in[a];
    splay(x);
    return findind(x,1)->id;
}
void disconnect(sp x,bool d){
    if(x->c[d]) x->c[d]->p=nullptr;
    x->c[d]=nullptr; pull(x);
}
void link(int a,int b){
    sp x,y,z; x=in[a];
    z=in[a]=new node(a);
    splay(x); y=x->c[0]; disconnect(x,0); y=merge(y,z);
    splay(in[b]); y=merge(y,in[b]);
    merge(y,x);
}
void cut(int a){
    sp x,y,z;
    splay(in[a]); x=in[a]->c[0]; disconnect(in[a],0);
    splay(out[a]); y=out[a]->c[1]; disconnect(out[a],1);
    x=findind(x,Sz(x)); y=findind(y,1);
    if(y==out[y->id]) out[y->id]=x;
    z=y->c[1]; delete(y); if(z) z->p=nullptr;
    merge(x,z);
}

int n,m,q,a,b,syn[N],se[N],dist[N],cnt;
bool on[N];
pii e[N];
vector<int> gr[N];
void dfs(int v,int p=0){
    for(auto i:gr[v]) if(i!=p){
        dist[i]=dist[v]+1;
        dfs(i,v);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("01-01.txt", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>q; fill(all(syn),1);
    fori(1,n+1) in[i]=out[i]=new node(i);
    fori(1,n){
        cin>>a>>b; e[i]={a,b};
        gr[a].pb(b); gr[b].pb(a);
    }
    dfs(1);
    fori(0,n) if(dist[e[i].pf]>dist[e[i].ps]) swap(e[i].pf,e[i].ps);
    fori(0,m){
        cin>>a; on[a]^=1;
        if(on[a]){
            syn[getRoot(e[a].pf)]+=syn[getRoot(e[a].ps)]-se[a];
            link(e[a].pf,e[a].ps);
        }
        else{
            cut(e[a].ps);
            se[a]=syn[getRoot(e[a].ps)]=syn[getRoot(e[a].pf)];
        }
    }
    fori(0,q){
        cin>>a;
        cout<<syn[getRoot(a)]<<nl;
    }
    return 0;
}
/**

*/