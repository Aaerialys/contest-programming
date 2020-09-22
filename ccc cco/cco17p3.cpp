#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

const int N=1<<20,B=60,M=1e9+7;
struct rect
{
    ll x,y1,y2,v,i;
};
bool cmp(rect aa,rect bb)
{
    if(aa.x==bb.x)
        return aa.v>bb.v;
    return aa.x<bb.x;
}
struct node
{
    ll l,r,v,lz;
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
        seg[num].l=l; seg[num].r=r; seg[num].lz=seg[num].v=0;
        if(l==r)
            return;
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
    }
    void pushDown(int num)
    {
        seg[num].v+=seg[num].lz*(seg[num].r-seg[num].l+1);
        if(seg[num].l!=seg[num].r)
        {
            seg[2*num].lz+=seg[num].lz;
            seg[2*num+1].lz+=seg[num].lz;
        }
        seg[num].lz=0;
    }
    void updateR(int l,int r,int v)
    {
        updateR(l,r,v,1);
    }
    void updateR(int l,int r,int v,int num)
    {
        pushDown(num);
        if(seg[num].l==l&&seg[num].r==r)
        {
            seg[num].lz+=v;
            pushDown(num);
            return;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            updateR(l,r,v,2*num);
        else if(l>mid)
            updateR(l,r,v,2*num+1);
        else
        {
            updateR(l,mid,v,2*num);
            updateR(mid+1,r,v,2*num+1);
        }//! check for error here
        pushDown(2*num); pushDown(2*num+1);
        seg[num].v=seg[2*num].v+seg[2*num+1].v;
    }
    ll query(int l)
    {
        return query(l,l,1);
    }
    ll query(int l,int r,int num)
    {
        pushDown(num);
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        if(l>mid)
            return query(l,r,2*num+1);
        return query(l,mid,2*num)+query(mid+1,r,2*num+1);
    }
};
ll n,q,x,y,v,a,b,c,p[B],ans[200010];
unordered_map<ll,int> cord;
vector<ll> coord;
vector<rect> poi;
segTree st;
ll reverse(ll aa)
{
    bitset<B> bin; string str;
    bin=aa; str=bin.to_string(); reverse(str.begin(),str.end()); bin=bitset<B>(str);
    return bin.to_ullong();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("02.in", "r", stdin);
    cin>>n>>q; p[0]=1;
    fori(1,B)
        p[i]=p[i-1]<<1;
    fori(0,n)
    {
        cin>>x>>y>>v; a=__builtin_clzll(x)-4; b=__builtin_clzll(y)-4; x=reverse(x); y=reverse(y);
        poi.push_back({x-p[a]+1,y-p[b]+1,y+p[b]-1,v,0}); poi.push_back({x+p[a]-1,y-p[b]+1,y+p[b]-1,-v,0});
        coord.push_back(y-p[b]+1); coord.push_back(y+p[b]-1);
    }
    fori(0,q)
    {
        cin>>x>>y; x=reverse(x); y=reverse(y);
        poi.push_back({x,y,0,0,i});
        coord.push_back(y);
    }
    sort(poi.begin(),poi.end(),cmp); sort(coord.begin(),coord.end());
    fori(0,coord.size())
        cord[coord[i]]=i+1;
    for(auto i:poi)
    {
        if(i.v==0)
            ans[i.i]=st.query(cord[i.y1]);
        else
            st.updateR(cord[i.y1],cord[i.y2],i.v);
    }
    fori(0,q)
        cout<<ans[i]<<"\n";
    return 0;
}