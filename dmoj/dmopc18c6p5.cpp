#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=524288;
struct node
{
    int l,r;
    int v,lz;
};
class segTree
{
public:
    int N;
    node seg[2*NN];
    segTree(int n)
    {
        N=n;
        build();
    }
    void build()
    {
        build(1,N,1);
    }
    void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r;
        seg[num].lz=seg[num].v=0;
        if(l==r)
            return;
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
    }
    void pushDown(int num)
    {
        seg[num].v+=seg[num].lz;
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
        }
        pushDown(2*num); pushDown(2*num+1);
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
        pushDown(num);
    }
    int query(int l,int r)
    {
        return query(l,r,1);
    }
    int query(int l,int r,int num)
    {
        pushDown(num);
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        else if(l>mid)
            return query(l,r,2*num+1);
        return max(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
};

class rct
{
public:
    int t,l,a,b,g;
};

bool cmp(rct a,rct b)
{
    if(a.l==b.l)
        return a.t<b.t;
    return a.l<b.l;
}

int n,m,k,q,t,gos[NN],a,b,c,d;
long long s;
vector<int> cox,coy;
segTree st(NN);
vector<rct> xy,yx;
rct z;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k>>q>>t;
    cox.push_back(INT_MIN); cox.push_back(INT_MAX); coy.push_back(INT_MIN); coy.push_back(INT_MAX);
    fori(0,k)
    {
        cin>>a>>b; cox.push_back(a); coy.push_back(b);
        xy.push_back({1,a,b-t,b+t,i});
        yx.push_back({1,b,a-t,a+t,i});
    }
    fori(0,q)
    {
        cin>>a>>b>>c>>d; cox.push_back(a); coy.push_back(b); cox.push_back(c); coy.push_back(d);
        xy.push_back({0,a,b,d,-1});
        xy.push_back({2,c,b,d,-1});
        yx.push_back({0,b,a,c,-1});
        yx.push_back({2,d,a,c,-1});
    }
    sort(xy.begin(),xy.end(),cmp); sort(yx.begin(),yx.end(),cmp);
    sort(cox.begin(),cox.end()); sort(coy.begin(),coy.end());
    fori(0,xy.size())
    {
        z=xy[i];
        a=lower_bound(coy.begin(),coy.end(),z.a)-coy.begin(); b=upper_bound(coy.begin(),coy.end(),z.b)-coy.begin()-1;
        if(z.t==0)
            st.updateR(a,b,1);
        if(z.t==1)
        {
            gos[z.g]=st.query(a,b);
        }
        if(z.t==2)
            st.updateR(a,b,-1);
    }
    fori(0,yx.size())
    {
        z=yx[i];
        a=lower_bound(cox.begin(),cox.end(),z.a)-cox.begin(); b=upper_bound(cox.begin(),cox.end(),z.b)-cox.begin()-1;
        if(z.t==0)
            st.updateR(a,b,1);
        if(z.t==1)
        {
            gos[z.g]=max(gos[z.g],st.query(a,b));
        }
        if(z.t==2)
            st.updateR(a,b,-1);
    }
    fori(0,k)
        s+=gos[i];
    cout<<s;
    return 0;
}
/*
line sweep
geese;
first line sweep left to right, then up to down

1. goose can only move left or right
add rectangle, find maximum number of rectanges for that goose, then remove rectangle

repeat for up to down
*/