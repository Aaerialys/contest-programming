#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(__typeof(a) i=a,ENDI=b;i<ENDI;i++)
#define forj(a,b) for(__typeof(a) j=a,ENDJ=b;j<ENDJ;j++)
#define fork(a,b) for(__typeof(a) k=a,ENDK=b;k<ENDK;k++)
#define foru(i,a,b) for(__typeof(a) i=a;i<b;i--)
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
#endif
typedef long long ll; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii;
inline ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(b==0) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
mt19937 randgen(time(0)); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;} template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));} template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{
    template<class T1,class T2>
    size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}
};

const int N=1<<18;
int n,a,b,c,a1[N],b1[N];
unordered_map<int,set<pii>> ust;
char ch,ch1[N];
vector<pii> stu;
vector<int> poi;
unordered_map<int,int> cord;

struct node
{
    int l,r,v;
};

class segTree
{
public:
    node seg[2*N]; //4*NN if NN is not a power of 2
    segTree()
    {
        build();
    }
    void build()
    {
        build(1,N,1);
    }
    void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r;
        if(l==r)
        {
            seg[num].v=0;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
    }
    void update(int pos,int v)
    {
        seg[pos+N-1].v=max(seg[pos+N-1].v,v);
        for(int num=(pos+N-1)>>1;num;num>>=1)
            seg[num].v=max(seg[(num<<1)].v,seg[(num<<1)|1].v);
    }
    int query(int pos,int v)
    {
        return query(pos,v,1);
    }
    int query(int pos,int v,int num)
    {
        if(seg[num].v<v)
            return 0;
        if(seg[num].l==seg[num].r)
            return (*ust[seg[num].l].lower_bound({v,0})).ps;
        int mid=(seg[num].l+seg[num].r)/2,temp;
        if(pos>mid)
            return query(pos,v,2*num+1);
        temp=query(pos,v,2*num);
        if(temp)
            return temp;
        return query(pos,v,2*num+1);
    }
};
segTree st;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    fori(0,n)
    {
        cin>>ch1[i];
        if(ch1[i]=='D')
        {
            cin>>a1[i]>>b1[i];
            poi.pb(b1[i]);

        }
        if(ch1[i]=='P')
        {
            cin>>a1[i];
        }
    }
    sort(poi.begin(),poi.end());
    fori(0,poi.size())
        cord[poi[i]]=i+1;
    poi.clear();
    fori(0,n)
    {
        ch=ch1[i];
        if(ch=='D')
        {
            a=a1[i]; b=cord[b1[i]];
            stu.pb({b,a}); ust[b].insert({a,stu.size()});
            st.update(b,a);
        }
        if(ch=='P')
        {
            a=a1[i]; a--;
            b=st.query(stu[a].pf,stu[a].ps+1);
            if(b==0||stu[b-1].pf>stu[a].pf)
                b=st.query(stu[a].pf+1,stu[a].ps);
            if(b)
                cout<<b<<"\n";
            else
                cout<<"NE\n";
        }
    }
    return 0;
}
/**

*/