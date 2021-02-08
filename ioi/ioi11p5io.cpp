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
#define nl "\n";

const int N=300010,M=1e9+7;

typedef struct node* sp; //sp=splay tree
int ind,op,op2;
struct node{
    int v; sp c[2],p;
    int s,id;
    node(int val){
        v=s=val; id=ind++;
        c[0]=c[1]=p=nullptr;
    }
    friend int S(sp x){return x?x->s:0;}
    void upd(int val){
        s+=val-v; v=val;
    }
    void pull(){
        s=v+S(c[0])+S(c[1]);
    }
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
        y=x->p;
        if(y->notRoot()) x->dir()==y->dir()? y->rot(): x->rot();
        x->rot();
    }
    pull(x); //important for lct in order to update whole path during access()
}
void access(sp x){
    for(sp v=x,last=0;v;v=v->p){
        splay(v);
        v->c[1]=last; last=v;
    }
    splay(x);
}
void link(sp x,sp y){
    access(x); x->p=y;
}
void cut(sp x){
    access(x);
    x->c[0]->p=nullptr; x->c[0]=nullptr; x->pull();
}
map<int,sp> lct;
gp_hash_table<int,int,chash> cnt;

int n,L,pos[N];
void ins(int x){
    if(!cnt[x]){
        if(!lct.count(x)){
            lct[x]=new node(1);
            auto last=prev(lct.find(x));
            if(!last->ps->v){
                cut(last->ps); link(last->ps,lct[x]);
            }
        }
        else{
            cut(lct[x]);
            lct[x]->upd(1);
        }
        if(!lct.count(x+L)){
            lct[x+L]=new node(0);
            auto last=prev(lct.find(x+L));
            if(!last->ps->v){
                cut(last->ps); link(last->ps,lct[x+L]);
            }
            link(lct[x+L],lct.upper_bound(x+L)->ps);
        }
        link(lct[x],lct[x+L]);
    }
    cnt[x]++;
}
void del(int x){
    cnt[x]--;
    if(!cnt[x]){
        cut(lct[x]);
        lct[x]->upd(0);
        link(lct[x],lct.upper_bound(x)->ps);
    }
}

void init(int _N,int _L,int _X[]){
    n=_N; L=_L+1;
    lct[-inf]=new node(0); lct[inf]=new node(0);
    link(lct[-inf],lct[inf]);
    fori(0,n){
        pos[i]=_X[i];
        ins(pos[i]);
    }
}
int update(int x,int y){
    del(pos[x]);
    pos[x]=y;
    ins(pos[x]);
    access(lct[-inf]);
    return S(lct[-inf]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("grader.in.10", "r", stdin); //freopen("", "w", stdout);
    int _N,_L,_X[N],q,x,y,ans;
    cin>>_N>>_L>>q;
    fori(0,_N) cin>>_X[i];
    init(_N,_L,_X); op=op2=0;
    fori(0,q){
        cin>>x>>y;
        cout<<update(x,y)<<nl;
        //cout<<update(x,y)<<" "<<ans<<"\n";
    }
    return 0;
}
/**
4 10 5
10 15 17 20
2 16
1 25
3 35
0 38
2 0

10 15 17 20
10 15 16 20
10 25 16 20
10 25 16 35
38 25 16 35
38 0 16 35

*/