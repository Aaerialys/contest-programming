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
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
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
struct chash{int operator()(ll x) const { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31)+SEED;}};
#define nl "\n";

const int N=P2(16),M=MOD;

typedef struct node* sp;
struct node{
    sp c[2],p;
    int val,id,mi,mii;
    bool flip;
    node(int v,int i){
        c[0]=c[1]=p=nullptr;
        flip=0;
        val=mi=v;
        id=mii=i;
    }
    void upd(int v){
        val=mi=v;
    }
    void push(){
        if(flip){
            swap(c[0],c[1]); flip=0;
            fori(0,2) if(c[i]) c[i]->flip^=1;
        }
    }
    void pull(){
        mii=id; mi=val;
        fori(0,2) if(c[i]&&c[i]->mi>mi){
            mi=c[i]->mi;
            mii=c[i]->mii;
        }
    }
    int dir(){
        if(!p) return -2;
        fori(0,2) if(p->c[i]==this) return i;
        return -1;
    }
    friend void connect(sp x,sp y,int d){
        if(d>=0) x->c[d]=y;
        if(y) y->p=x;
    }
    void rot(){
        sp x=p; int d=dir(); connect(x->p,this,x->dir()); connect(x,c[d^1],d); connect(this,x,d^1);
        x->pull(); pull();
    }
};
void splay(sp x){
    if(!x) return;
    sp y;
    while(x->dir()>=0){
        y=x->p; if(y->p) y->p->push(); y->push(); x->push();
        if(y->dir()>=0) x->dir()==y->dir()? y->rot(): x->rot();
        x->rot();
    }
    x->push(); x->pull();
}
void access(sp x){
    for(sp y=x,last=nullptr;y;y=y->p){
        splay(y);
        y->c[1]=last; last=y;
    }
    splay(x);
}
void evert(sp x){
    access(x);
    x->flip^=1;
}
void link(sp x,sp y){
    evert(x);
    x->p=y;
}
void cut(sp x){
    access(x);
    x->c[0]->p=nullptr; x->c[0]=nullptr; x->pull();
}
sp lca(sp x,sp y){
    if(x==y) return x;
    access(x); access(y);
    if(!x->p) return nullptr;
    splay(x);
    return x->p?:x;
}
sp lct[2*N];
vector<pii> edge[2*N];
ll n,m,q,a,b,c,ans;
bool done;
pii last[N],e[N];
void upd(int l,int r,pii v){
    for(l+=N,r+=N+1;l<r;l/=2,r/=2){
        if(l&1) edge[l++].pb(v);
        if(r&1) edge[--r].pb(v);
    }
}
void cutEdge(int x){
    evert(lct[e[x].pf]);
    cut(lct[n+x]);
    cut(lct[e[x].ps]);
}
void addEdge(int x){
    link(lct[e[x].pf],lct[n+x]);
    link(lct[e[x].ps],lct[n+x]);
}
void go(int x){
    stack<pii> undo;
    for(auto i:edge[x]){
        tie(a,b)=e[i.ps];
        lct[n+i.ps]->upd(i.pf);
        if(!lca(lct[a],lct[b])){
            undo.emplace(0,i.ps);
            addEdge(i.ps); ans+=i.pf;
            continue;
        }
        evert(lct[a]); access(lct[b]);
        if(lct[b]->mi>i.pf){
            undo.emplace(lct[b]->mii,i.ps);
            ans-=lct[b]->mi; cutEdge(lct[b]->mii);
            addEdge(i.ps); ans+=i.pf;
        }
    }
    if(x-N>=1&&x-N<=q) cout<<ans<<nl;
    if(x<N) go(x*2),go(x*2+1);
    while(sz(undo)){
        auto temp=undo.top(); undo.pop();
        cutEdge(temp.ps); ans-=lct[n+temp.ps]->val;
        if(temp.pf) addEdge(temp.pf), ans+=lct[n+temp.pf]->val;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>q;
    fori(1,n+1) lct[i]=new node(0,i);
    fori(1,m+1) lct[n+i]=new node(0,i);
    fori(1,m+1){
        cin>>a>>b>>c; e[i]={a,b};
        last[i]={0,c};
    }
    fori(1,q+1){
        cin>>a>>b;
        upd(last[a].pf,i-1,{last[a].ps,a});
        last[a]={i,b};
    }
    fori(1,m+1) upd(last[i].pf,q,{last[i].ps,i});
    go(1);
    return 0;
}
/**
5 5 3
1 2 1
2 3 2
3 4 3
4 5 4
5 1 5
1 6
1 1
5 3
*/