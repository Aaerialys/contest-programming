#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i++)
#define ford(i,a,b) for(__typeof(a) i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x7f3f3f3f
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
const int N=1<<20; //minimum power of 2 greater than n

pii arr[N];

struct node
{
    int l,r,a,b,s,lza,lzb;
};
class segTree
{
public:
    node seg[2*N]; //4*NN if NN is not a power of 2
    void build()
    {
        build(1,N,1);
    }
    void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r; seg[num].lza=seg[num].lzb=-inf;
        if(l==r)
        {
            seg[num].a=arr[l-1].pf; seg[num].b=arr[l-1].ps; seg[num].s=seg[num].a+seg[num].b;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
        seg[num].a=max(seg[2*num].a,seg[2*num+1].a);
        seg[num].b=max(seg[2*num].b,seg[2*num+1].b);
        seg[num].s=max(seg[2*num].s,seg[2*num+1].s);
    }
    void pushDown(int num)
    {
        if(seg[num].lza!=-inf)
        {
            seg[num].a=seg[num].lza;
            seg[num].s=seg[num].a+seg[num].b;//!b updated later
            if(seg[num].l!=seg[num].r)
            {
                seg[2*num].lza=seg[num].lza;
                seg[2*num+1].lza=seg[num].lza;
            }
            seg[num].lza=-inf;
        }
        if(seg[num].lzb!=-inf)
        {
            seg[num].b=max(seg[num].b,seg[num].lzb);
            seg[num].s=max(seg[num].s,seg[num].a+seg[num].lzb);
            if(seg[num].l!=seg[num].r)
            {
                seg[2*num].lzb=max(seg[2*num].lzb,seg[num].lzb);
                seg[2*num+1].lzb=max(seg[2*num+1].lzb,seg[num].lzb);
            }
            seg[num].lzb=-inf;
        }
    }
    void updateR(int l,int r,int a,int b)
    {
        pushDown(1);
        updateR(l,r,a,b,1);
    }
    void updateR(int l,int r,int a,int b,int num)
    {
        if(seg[num].l==l&&seg[num].r==r)
        {
            if(a!=-inf)
                seg[num].lza=a;
            if(b!=-inf)
                seg[num].lzb=max(seg[num].lzb,b);
            pushDown(num);
            return;
        }
        pushDown(2*num); pushDown(2*num+1);
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            updateR(l,r,a,b,2*num);
        else if(l>mid)
            updateR(l,r,a,b,2*num+1);
        else
        {
            updateR(l,mid,a,b,2*num);
            updateR(mid+1,r,a,b,2*num+1);
        }
        seg[num].a=max(seg[2*num].a,seg[2*num+1].a);
        seg[num].b=max(seg[2*num].b,seg[2*num+1].b);
        seg[num].s=max(seg[2*num].s,seg[2*num+1].s);
    }
    int query(int l,int r)
    {
        return query(l,r,1);
    }
    int query(int l,int r,int num)
    {
        pushDown(num);
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].s;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        if(l>mid)
            return query(l,r,2*num+1);
        return max(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
};
segTree st;
int n,q,x,y,l,r;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(0,n)
        cin>>arr[i].pf;
    fori(0,n)
        cin>>arr[i].ps;
    st.build();
    fori(0,q)
    {
        cin>>x>>l>>r;
        if(x==1)
        {
            cin>>y;
            st.updateR(l,r,y,-inf);
        }
        if(x==2)
        {
            cin>>y;
            st.updateR(l,r,-inf,y);
        }
        if(x==3)
            cout<<st.query(l,r)<<"\n";
    }
    return 0;
}
/**
5 100
1 2 3 4 5
5 4 3 2 1
2 1 5 10
3 1 5
*/