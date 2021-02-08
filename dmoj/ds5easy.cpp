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

const int N=100010,M=1e9+7;

typedef struct node* sp; //sp=splay tree
struct lazy{
    int a,b;
    operator bool() const{return !a||b;}
};
lazy operator+=(lazy& a,lazy& b){
    a.a=a.a*b.a; a.b=a.b*b.a+b.b;
    return a;
}
struct Info{
    int sz,s,mi,ma;
    Info(int val){
        sz=1; s=mi=ma=val;
    }
    Info(){
        sz=s=0; mi=inf; ma=-inf;
    }
};
Info operator+=(Info& a,lazy& b){
    if(!a.sz) return a;
    a.s=a.s*b.a+a.sz*b.b; a.mi=a.mi*b.a+b.b; a.ma=a.ma*b.a+b.b;
    return a;
}
Info operator+=(Info& a,Info& b){
    a.s+=b.s; a.sz+=b.sz; a.mi=min(a.mi,b.mi); a.ma=max(a.ma,b.ma);
    return a;
}
int operator +=(int& a,lazy& b){
    a=a*b.a+b.b;
    return a;
}
struct node{
    int v,id;
    sp c[5],p;
    Info info[2];
    lazy lz[2];
    bool flip;
    node(int i,int val){
        id=i; v=val;
        lz[0]=lz[1]={1,0}; info[0]=Info(val);
        fori(0,5) c[i]=nullptr; p=nullptr;
        flip=0;
    }
    void upd(lazy l){
        lz[0]+=l;
        info[0]+=l;
        v+=l;
    }
    void upd2(lazy l){
        lz[1]+=l;
        info[1]+=l;
    }
    void push(){
        if(flip){
            swap(c[0],c[1]); flip=0;
            fori(0,2) if(c[i]) c[i]->flip^=1;
        }
        if(lz[1]){
            fori(0,5) if(c[i]){
                c[i]->upd2(lz[1]);
                if(i>=2) c[i]->upd(lz[1]);
            }
            lz[1]={1,0};
        }
        if(lz[0]){
            fori(0,2) if(c[i]) c[i]->upd(lz[0]);
            lz[0]={1,0};
        }
    }
    void pull(){
        info[0]=Info(v); info[1]=Info();
        fori(0,5) if(c[i]){
            info[1]+=c[i]->info[1];
            info[i>=2]+=c[i]->info[0];
        }
    }
    friend sp push(sp x){if(x) x->push(); return x;}
    friend sp pull(sp x){if(x) x->pull(); return x;}
    int dir(){
        if(!p) return 5;
        fori(0,5) if(p->c[i]==this) return i;
        assert(0);
    }
    friend void connect(sp x,sp y,int d){ //make y a child of x
        if(d<5) x->c[d]=y;
        if(y) y->p=x;
    }
    void rot(){ //rotate with its parent
        sp x=p; int d=dir(); connect(x->p,this,x->dir()); connect(x,c[d^1],d); connect(this,x,d^1);
        x->pull(); pull();
    }
};
void splay(sp x){
    if(!x) return;
    sp y;
    while(x->dir()<2){
        y=x->p; push(y->p); push(y); push(x);
        if(y->dir()<2){
            if(x->dir()==y->dir()){
                if(y->p->dir()>=2) fori(2,4){
                    connect(y,y->p->c[i],i);
                    y->p->c[i]=nullptr;
                }
                y->rot();
            }
            else x->rot();
        }
        fori(2,4){
            connect(x,x->p->c[i],i);
            x->p->c[i]=nullptr;
        }
        x->rot();
    }
    while(x->dir()<4){
        y=x->p; push(y->p); push(y); push(x);
        if(y->dir()<4) x->dir()==y->dir()? y->rot(): x->rot();
        x->rot();
    }
    push(x); pull(x); //important for lct in order to update whole path during access()
}
sp splayRight(sp x){
    while(x->c[3]) x=x->c[3];
    splay(x);
    return x;
}
sp join(sp a,sp b){
    if(!a) return b;
    splay(a); a=splayRight(a);
    connect(a,b,3); a->pull();
    return a;
}
void access(sp x){
    for(sp v=x,last=0;v;v=v->p){
        splay(v);
        auto c=v->c[1];
        if(c) c->p=nullptr;
        if(last){
            auto a=last->c[2],b=last->c[3];
            if(a) a->p=nullptr;
            if(b) b->p=nullptr;
            last->c[2]=last->c[3]=nullptr; last->pull();
            connect(v,join(join(a,b),c),4);
        }
        else{
            if(v->c[4]) v->c[4]->p=nullptr;
            connect(v,join(c,v->c[4]),4);
        }
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
    evert(x); connect(y,join(x,y->c[4]),4);
    pull(y);
}
void cut(sp x){
    access(x);
    x->c[0]->p=nullptr; x->c[0]=nullptr; x->pull();
}
sp lct[N];
int n,q,a,b,c,t,rt;
pii e[N];
Info ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(1,n+1){
        cin>>a; lct[i]=new node(i,a);
    }
    fori(1,n) cin>>e[i].pf>>e[i].ps;
    fori(1,n){
        tie(a,b)=e[i];
        link(lct[a],lct[b]);
    }
    cin>>rt;
    while(q--){
        cin>>t;
        if(t==0){
            cin>>a; rt=a;
        }
        if(t==99){
            cin>>a>>b;
            evert(lct[rt]); access(lct[a]);
            lazy temp={0,b};
            if(lct[a]->c[4]){
                lct[a]->c[4]->upd(temp); lct[a]->c[4]->upd2(temp);
            }
            lct[a]->v+=temp;
            pull(lct[a]); //might not need this?
        }
        if(t==599){
            cin>>a>>b;
            evert(lct[rt]); access(lct[a]);
            lazy temp={1,b};
            if(lct[a]->c[4]){
                lct[a]->c[4]->upd(temp); lct[a]->c[4]->upd2(temp);
            }
            lct[a]->v+=temp;
            pull(lct[a]);  //might not need this?
        }
        if(t==399){
            cin>>a;
            evert(lct[rt]); access(lct[a]);
            ans=Info(lct[a]->v);
            if(lct[a]->c[4]){
                ans+=lct[a]->c[4]->info[0];
                ans+=lct[a]->c[4]->info[1];
            }
            cout<<ans.mi<<nl;
        }
        if(t==499){
            cin>>a;
            evert(lct[rt]); access(lct[a]);
            ans=Info(lct[a]->v);
            if(lct[a]->c[4]){
                ans+=lct[a]->c[4]->info[0];
                ans+=lct[a]->c[4]->info[1];
            }
            cout<<ans.ma<<nl;
        }
        if(t==1199){
            cin>>a;
            evert(lct[rt]); access(lct[a]);
            ans=Info(lct[a]->v);
            if(lct[a]->c[4]){
                ans+=lct[a]->c[4]->info[0];
                ans+=lct[a]->c[4]->info[1];
            }
            cout<<ans.s<<nl;
        }
        if(t==1){
            cin>>a>>b>>c;
            evert(lct[a]); access(lct[b]);
            lct[b]->upd({0,c});
        }
        if(t==2){
            cin>>a>>b>>c;
            evert(lct[a]); access(lct[b]);
            lct[b]->upd((lazy){1,c});
        }
        if(t==3){
            cin>>a>>b;
            evert(lct[a]); access(lct[b]);
            cout<<lct[b]->info[0].mi<<nl;
        }
        if(t==4){
            cin>>a>>b;
            evert(lct[a]); access(lct[b]);
            cout<<lct[b]->info[0].ma<<nl;
        }
        if(t==5){
            cin>>a>>b;
            evert(lct[a]); access(lct[b]);
            cout<<lct[b]->info[0].s<<nl;
        }
        if(t==6){
            cin>>a>>b;
            evert(lct[rt]);
            if(lca(lct[a],lct[b])==lct[a]) continue;
            cut(lct[a]); link(lct[a],lct[b]);
        }
        if(t==7){
            cin>>a>>b; evert(lct[rt]);
            cout<<lca(lct[a],lct[b])->id<<nl;
        }
    }
    return 0;
}
/**
9 13
100 2 1 3 6 5 4 7 8
1 2
1 3
2 4
2 7
3 6
3 8
3 5
5 9
1
7 9 4
*/