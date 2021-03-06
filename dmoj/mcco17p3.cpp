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

const int N=400010,M=1e9+7;

typedef struct node* sp; //sp=splay tree
struct node{
    int v; sp c[2],p;
    int ma,lz;
    bool flip;
    node(int val){
        v=ma=val; lz=inf;
        c[0]=c[1]=p=nullptr; flip=0;
    }
    friend int Ma(sp x){return x?x->ma:0;}
    void upd(int val){
        v=min(v,val); lz=min(lz,val); ma=min(ma,val);
    }
    void push(){
        if(flip){
            swap(c[0],c[1]); flip=0;
            fori(0,2) if(c[i]) c[i]->flip^=1;
        }
        if(lz!=inf){
            fori(0,2) if(c[i]) c[i]->upd(lz);
            lz=inf;
        }
    }
    void pull(){
        ma=max(v,Ma(c[0]),Ma(c[1]));
    }
    friend sp push(sp x){if(x) x->push(); return x;}
    friend sp pull(sp x){if(x) x->pull(); return x;}
    int dir(){
        if(!p) return -2;
        fori(0,2) if(p->c[i]==this) return i;
        return -1;
    }
    bool notRoot(){return dir()>=0;}
    friend void connect(sp x,sp y,int d){ //make y a child of x
        if(d>=0) x->c[d]=y;
        if(y) y->p=x;
    }
    void rot(){ //rotate with its parent
        sp x=p,z=x->p; int d=dir(),dd=x->dir(); connect(x,c[d^1],d); connect(this,x,d^1);
        x->pull(); pull();
        connect(z,this,dd);
    }
};
void splay(sp x){
    if(!x) return;
    sp y;
    while(x->notRoot()){
        y=x->p; push(y->p); push(y); push(x);
        if(y->notRoot()) x->dir()==y->dir()? y->rot(): x->rot();
        x->rot();
    }
    push(x); pull(x); //important for lct in order to update whole path during access()
}
void access(sp x){
    for(sp v=x,last=0;v;v=v->p){
        splay(v);
        v->c[1]=last; last=v;
    }
    splay(x);
}
void evert(sp x){
    access(x);
    x->flip^=1;
}
sp lca(sp x,sp y){
    if(x==y) return x;
    access(x); access(y);
    if(!x->p) return nullptr;
    splay(x);
    return x->p?:x;
}
void link(sp x,sp y){
    evert(x); x->p=y;
}
sp lct[N];
int n,m,q,a,b,c,t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m>>q; n++;
    fori(0,n) lct[i]=new node(0);
    fori(0,m){
        cin>>a>>b; assert(a<n&&b<n);
        if(lca(lct[a],lct[b])){
            evert(lct[a]); access(lct[b]);
            lct[b]->upd(i);
        }
        else{
            lct[n+i]=new node(inf);
            link(lct[a],lct[n+i]); link(lct[b],lct[n+i]);
        }
    }
    fori(0,q){
        cin>>a>>b;
        if(lca(lct[a],lct[b])){
            evert(lct[a]); access(lct[b]);
            if(Ma(lct[b])>=m) cout<<-1<<"\n";
            else cout<<Ma(lct[b])<<"\n";
        }
        else cout<<-1<<"\n";
    }
    return 0;
}
/**
3 3 1
1 2
1 2
2 3
*/