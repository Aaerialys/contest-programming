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

const int N=500001,M=1e9+7;
typedef struct node* sp; //sp=splay tree
struct node{
    int v; sp c[2],p;
    int sz,s,ms,lms,rms,lz;
    bool flip;
    node(int val){
        v=s=ms=lms=rms=val;
        c[0]=c[1]=p=nullptr; sz=1; lz=inf; flip=0;
    }
    void upd(int val){
        v=lz=val; s=val*sz; ms=lms=rms=max(val,s);
    }
    friend int Sz(sp x){return x?x->sz:0;}
    friend int S(sp x){return x?x->s:0;}
    friend int Ms(sp x){return x?x->ms:-inf;}
    friend int Lms(sp x){return x?x->lms:0;}
    friend int Rms(sp x){return x?x->rms:0;}
    void push(){
        if(flip){
            swap(c[0],c[1]);
            flip=0;
            fori(0,2) if(c[i]){
                c[i]->flip^=1;
                swap(c[i]->lms,c[i]->rms);
            }
        }
        if(lz!=inf){
            fori(0,2) if(c[i]) c[i]->upd(lz);
            lz=inf;
        }
    }
    void pull(){
        sz=1+Sz(c[0])+Sz(c[1]);
        s=v+S(c[0])+S(c[1]);
        ms=max(Ms(c[0]),Ms(c[1]),v+max(Rms(c[0]),0)+max(Lms(c[1]),0));
        lms=max(Lms(c[0]),S(c[0])+v+max(Lms(c[1]),0));
        rms=max(Rms(c[1]),S(c[1])+v+max(Rms(c[0]),0));
    }
    friend sp push(sp x){if(x) x->push(); return x;}
    friend sp pull(sp x){if(x) x->pull(); return x;}
    bool dir(){
        return p&&p->c[1]==this;
    }
    friend void connect(sp x,sp y,bool d){ //make y a child of x
        if(x) x->c[d]=y;
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
    while(x->p){
        y=x->p;
        if(y->p) x->dir()==y->dir()? y->rot(): x->rot();
        x->rot();
    }
}
sp findval(sp x,int v){ //value less than or equal to v
    if(!x) return x;
    push(x);
    if(x->v>v){
        if(!x->c[0]) splay(x);
        return findval(x->c[0],v);
    }
    if(x->v<v&&x->c[1]) return findval(x->c[1],v);
    splay(x);
    return x;
}
sp findind(sp x,int ind){ //index less than or equal to ind (first ind elements, 1 indexed)
    if(!x) return x;
    push(x);
    if(Sz(x->c[0])>=ind){
        if(!x->c[0]) splay(x);
        return findind(x->c[0],ind);
    }
    if(Sz(x->c[0])+1<ind&&x->c[1]) return findind(x->c[1],ind-1-Sz(x->c[0]));
    splay(x);
    return x;
}
pair<sp,sp> split(sp x,int v){ //nodes <=v to left
    sp y=findval(x,v),z;
    if(!y){
        splay(x);
        return {y,x};
    }
    z=y->c[1];
    if(z) z->p=y->c[1]=nullptr;
    pull(y);
    return {y,z};
}
pair<sp,sp> isplit(sp x,int ind){//first ind nodes to left
    sp y=findind(x,ind),z;
    if(!y){
        splay(x);
        return {y,x};
    }
    z=y->c[1];
    if(z) z->p=y->c[1]=nullptr;
    pull(y);
    return {y,z};
}
sp merge(node *l,node *r){
    if(!l) return r;
    l=findind(l,Sz(l));
    connect(l,r,1);
    return pull(l);
}
sp ins(sp cur,int v){
    auto a=split(cur,v-1),b=split(a.ps,v);
    return merge(a.pf,merge(new node(v),b.ps));
}
sp del(sp cur,int v){
    auto a=split(cur,v-1),b=split(a.ps,v);
    return merge(a.pf,b.ps);
}
void del(sp cur){
    if(!cur) return;
    fori(0,2) del(cur->c[i]);
    delete cur;
}
void tour(sp cur){
    if(!cur) return;
    push(cur); tour(cur->c[0]); cout<<cur->v<<" ";  tour(cur->c[1]);
}
int n,q,a,b,c,d;
string in;
sp rt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(1,n+1){
        cin>>a;
        rt=merge(rt,new node(a));
    }
    //tour(rt); cout<<endl;
    while(q--){
        cin>>in;
        if(in=="INSERT"){
            cin>>a>>b; auto x=isplit(rt,a);
            fori(0,b){
                cin>>c;
                x.pf=merge(x.pf,new node(c));
            }
            rt=merge(x.pf,x.ps);
        }
        if(in=="DELETE"){
            cin>>a>>b;
            auto x=isplit(rt,a-1),y=isplit(x.ps,b);
            del(y.pf);
            rt=merge(x.pf,y.ps);
        }
        if(in=="MAKE-SAME"){
            cin>>a>>b>>c;
            auto x=isplit(rt,a-1),y=isplit(x.ps,b);
            y.pf->upd(c);
            rt=merge(x.pf,merge(y.pf,y.ps));
        }
        if(in=="REVERSE"){
            cin>>a>>b;
            auto x=isplit(rt,a-1),y=isplit(x.ps,b);
            y.pf->flip^=1;
            rt=merge(x.pf,merge(y.pf,y.ps));
        }
        if(in=="GET-SUM"){
            cin>>a>>b;
            auto x=isplit(rt,a-1); auto y=isplit(x.ps,b);
            cout<<S(y.pf)<<"\n";
            rt=merge(x.pf,merge(y.pf,y.ps));
        }
        if(in=="MAX-SUM"){
            cout<<Ms(rt)<<"\n";
        }
        //tour(rt); cout<<endl;
    }
    return 0;
}
/**

*/