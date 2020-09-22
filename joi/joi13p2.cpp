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

const int N=100010,M=1e9+7;
typedef struct node* sp;
struct node{
    sp p,c[2]; int id;
    node(int i){
        id=i;
        p=c[0]=c[1]=nullptr;
    }
    int dir(){
        if(!p) return -2;
        fori(0,2) if(p->c[i]==this) return i;
        return -1;
    }
    bool notRoot(){
        return dir()>=0;
    }
    friend void connect(sp x,sp y,int d){
        if(d>=0) x->c[d]=y;
        if(y) y->p=x;
    }
    void rot(){
        sp x=p,y=x->p; int d=dir(),dd=x->dir(); connect(x,c[d^1],d); connect(this,x,d^1);
        connect(y,this,dd);
    }
};
void splay(sp x){
    if(!x) return;
    sp y;
    while(x->notRoot()){
        y=x->p;
        if(y->notRoot()) x->dir()==y->dir()? y->rot(): x->rot();
        x->rot();
    }
}
void access(sp x){
    for(sp y=x,last=nullptr;y;y=y->p){
        splay(y);
        y->c[1]=last; last=y;
    }
    splay(x);
}
int getRoot(sp x){
    access(x);
    while(x->c[0]) x=x->c[0];
    access(x);
    return x->id;
}
void link(sp x,sp y){
    access(y); y->p=x;
}
void cut(sp x){
    access(x);
    x->c[0]->p=nullptr; x->c[0]=nullptr;
}
sp lct[N];

int n,m,q,a,b,syn[N],se[N],dist[N];
bool on[N];
pii e[N];
vector<int> gr[N];
void dfs(int v,int p=1){
    for(auto i:gr[v]) if(i!=p){
        dist[i]=dist[v]+1;
        dfs(i,v);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    fori(0,N) lct[i]=new node(i);
    cin>>n>>m>>q; fill(all(syn),1);
    fori(1,n){
        cin>>a>>b; e[i]={a,b};
        gr[a].pb(b); gr[b].pb(a);
    }
    dfs(1);
    fori(1,n) if(dist[e[i].pf]>dist[e[i].ps]) swap(e[i].pf,e[i].ps);
    fori(0,m){
        cin>>a; on[a]^=1;
        if(on[a]){
            syn[getRoot(lct[e[a].pf])]+=syn[getRoot(lct[e[a].ps])]-se[a];
            link(lct[e[a].pf],lct[e[a].ps]);
        }
        else{
            cut(lct[e[a].ps]);
            se[a]=syn[getRoot(lct[e[a].ps])]=syn[getRoot(lct[e[a].pf])];
        }
    }
    fori(0,q){
        cin>>a;
        cout<<syn[getRoot(lct[a])]<<"\n";
    }
    return 0;
}
/**

*/