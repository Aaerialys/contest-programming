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
typedef pair<int,int> pii;

struct node
{
    ll l,r,v,m,lz,lc,rc;
};

const int N=1<<30;
node seg[4500000];
int sz;

class segTree
{
public:
    segTree()
    {
        build();
    }
    void build()
    {
        seg[++sz]={1,N,0,0,INF,0,0};
    }
    void birth(int num)
    {
        if(seg[num].lc)
            return;
        int mid=(seg[num].l+seg[num].r)/2;
        seg[num].lc=++sz;
        seg[sz]={seg[num].l,mid,0,0,INF,0,0}; seg[sz].v=seg[num].v/(seg[num].r-seg[num].l+1)*(seg[sz].r-seg[sz].l+1); seg[sz].m=max(0LL,seg[sz].v);
        seg[num].rc=++sz;
        seg[sz]={mid+1,seg[num].r,0,0,INF,0,0}; seg[sz].v=seg[num].v/(seg[num].r-seg[num].l+1)*(seg[sz].r-seg[sz].l+1); seg[sz].m=max(0LL,seg[sz].v);
    }
    void pushDown(int num)
    {
        if(seg[num].lz==INF)
            return;
        seg[num].v=seg[num].lz*(seg[num].r-seg[num].l+1);
        seg[num].m=max(0LL,seg[num].v);
        if(seg[num].lc)
        {
            seg[seg[num].lc].lz=seg[num].lz;
            seg[seg[num].rc].lz=seg[num].lz;
        }
        seg[num].lz=INF;
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
            seg[num].lz=v;
            pushDown(num);
            return;
        }
        birth(num);
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            updateR(l,r,v,seg[num].lc);
        else if(l>mid)
            updateR(l,r,v,seg[num].rc);
        else
        {
            updateR(l,mid,v,seg[num].lc);
            updateR(mid+1,r,v,seg[num].rc);
        }
        pushDown(seg[num].lc); pushDown(seg[num].rc);
        seg[num].v=seg[seg[num].lc].v+seg[seg[num].rc].v;
        seg[num].m=max(seg[seg[num].lc].m,seg[seg[num].lc].v+seg[seg[num].rc].m);
        pushDown(num);
    }
    int query(int h)
    {
        return query(h,1);
    }
    int query(int h,int num)
    {
        int temp;
        pushDown(num);
        if(seg[num].l==seg[num].r)
            return temp=seg[num].m<=h;
        if(!seg[num].lc)
            return h/(seg[num].v/(seg[num].r-seg[num].l+1));
        pushDown(seg[num].lc); pushDown(seg[num].rc);
        if(seg[seg[num].lc].m>h)
            return temp=query(h,seg[num].lc);
        else
            return temp=query(h-seg[seg[num].lc].v,seg[num].rc)+seg[seg[num].lc].r-seg[seg[num].lc].l+1;
    }
};
segTree st;
int n,a,b,c;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("mou19.in", "r", stdin);
    cin>>n>>ch; st.updateR(n+1,n+1,inf);
    while(ch!='E')
    {
        if(ch=='I')
        {
            cin>>a>>b>>c;
            st.updateR(a,b,c);
        }
        if(ch=='Q')
        {
            cin>>a;
            cout<<st.query(a)<<"\n";
        }
        cin>>ch;
    }
    return 0;
}