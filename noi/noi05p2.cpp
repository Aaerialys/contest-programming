#include <bits/stdc++.h>/*
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("Ofast")*/
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i++)
#define ford(i,a,b) for(__typeof(a) i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcount
#define clz __builtin_clz
#define clzll __builtin_clz
#define ctz __builtin_ctz
#define ctzll __builtin_ctz
#define pow2(x) (1LL<<(x))
using namespace std;
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef long long i128; typedef long long ui128;
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
mt19937 randgen(time(0)); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=500001;
class node
{
public:
    int v,sum,ms,lms,rms,sz,lz,p;
    bool rev;
    node *left,*right;
    void init(int val)
    {
        v=sum=ms=lms=rms=val; sz=1; lz=inf; rev=false;
        p=randint(0,1e9);
        left=right=nullptr;
    }
    inline void updv(int val)
    {
        v=lz=val; sum=val*sz; ms=lms=rms=max(val,sum);
    }
    inline void upd();
    inline void pushdown();
};
node *x,*y,*z,*rt;
stack<node*> iarr,fre;
node* newnode(int val)
{
    node* n=fre.top(); fre.pop();
    n->init(val);
    return n;
}
class treap
{
public:
};
    inline int Sz(node *n)
    {
        return n?n->sz:0;
    }
    inline int Sum(node *n)
    {
        return n?n->sum:0;
    }
    inline int Ms(node *n)
    {
        return n?n->ms:-inf;
    }
    inline int Lms(node *n)
    {
        return n?n->lms:0;
    }
    inline int Rms(node *n)
    {
        return n?n->rms:0;
    }
    inline void node::upd()
    {
        sz=Sz(left)+Sz(right)+1;
        sum=Sum(left)+Sum(right)+v;
        ms=max(Ms(left),Ms(right),Rms(left)+v,v+Lms(right),Rms(left)+v+Lms(right));
        lms=max(Lms(left),Sum(left)+v,Sum(left)+v+Lms(right));
        rms=max(Rms(right),Sum(right)+v,Sum(right)+v+Rms(left));
    }
    inline void node::pushdown()
    {
        if(rev)
        {
            rev=false;
            swap(left,right);
            if(left)
            {
                left->rev^=1;
                swap(left->lms,left->rms);
            }
            if(right)
            {
                right->rev^=1;
                swap(right->lms,right->rms);
            }
        }
        if(lz!=inf)
        {
            if(left)
                left->updv(lz);
            if(right)
                right->updv(lz);
            lz=inf;
        }
    }
    inline void merge(node *&cur,node *l,node *r)
    {
        if(l)
            l->pushdown();
        else
        {
            cur=r;
            return;
        }
        if(r)
            r->pushdown();
        else
        {
            cur=l;
            return;
        }
        if(l->p<r->p)
        {
            merge(l->right,l->right,r);
            cur=l;
        }
        else
        {
            merge(r->left,l,r->left);
            cur=r;
        }
        cur->upd();
    }
    inline void split(node *cur,node *&l,node *&r,int pos)
    {
        if(!cur)
        {
            l=r=nullptr;
            return;
        }
        cur->pushdown();
        if(pos<=Sz(cur->left))
        {
            split(cur->left,l,cur->left,pos);
            r=cur;
        }
        else
        {
            split(cur->right,cur->right,r,pos-1-Sz(cur->left));
            l=cur;
        }
        cur->upd();
    }
    inline void del(node *cur)
    {
        if(!cur)
            return;
        del(cur->left); del(cur->right);
        fre.push(cur);
    }
int n,q,a,b,c,d;
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    fori(0,N)
        fre.push(new node);
    cin>>n>>q;
    fori(1,n+1)
    {
        cin>>a;
        y=newnode(a);
        for(int k=i;!(k&1);k>>=1,iarr.pop())
            merge(y,iarr.top(),y);
        iarr.push(y);
    }
    for(rt=nullptr;!iarr.empty();iarr.pop())
        merge(rt,iarr.top(),rt);
    fori(0,q)
    {
        cin>>in;
        if(in=="INSERT")
        {
            cin>>a>>b;
            forj(1,b+1)
            {
                cin>>c; y=newnode(c);
                for(int k=j;!(k&1);k>>=1,iarr.pop())
                    merge(y,iarr.top(),y);
                iarr.push(y);
            }
            for(y=nullptr;!iarr.empty();iarr.pop())
                merge(y,iarr.top(),y);
            split(rt,x,z,a);
            merge(rt,x,y); merge(rt,rt,z);
        }
        if(in=="DELETE")
        {
            cin>>a>>b;
            split(rt,x,y,a-1); split(y,y,z,b);
            merge(rt,x,z);
            del(y);
        }
        if(in=="MAKE-SAME")
        {
            cin>>a>>b>>c;
            split(rt,x,y,a-1); split(y,y,z,b);
            y->updv(c);
            merge(rt,x,y); merge(rt,rt,z);
        }
        if(in=="REVERSE")
        {
            cin>>a>>b;
            split(rt,x,y,a-1); split(y,y,z,b);
            y->rev^=1;
            merge(rt,x,y); merge(rt,rt,z);
        }
        if(in=="GET-SUM")
        {
            cin>>a>>b;
            split(rt,x,y,a-1); split(y,y,z,b);
            cout<<Sum(y)<<"\n"; //assert(sum(y)<=1e7);
            merge(rt,x,y); merge(rt,rt,z);
        }
        if(in=="MAX-SUM")
        {
            cout<<Ms(rt)<<"\n";
        }
    }
    return 0;
}
/**

*/