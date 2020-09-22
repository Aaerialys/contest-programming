#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

struct node
{
    int l,r;
    long long v,lz;
};

class segTree
{
public:
    int N;
    node seg[800010];
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
        seg[num].l=l;
        seg[num].r=r;
        seg[num].lz=0;
        if(l==r)
        {
            seg[num].v=0;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num);
        build(mid+1,r,2*num+1);
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
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
    void updateR(int l,int r,long long v,int num)
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
        seg[num].v=max(seg[2*num].v+seg[2*num].lz,seg[2*num+1].v+seg[2*num+1].lz);
        pushDown(num);
    }
    long long query(int l,int r)
    {
        return query(l,r,1);
    }
    long long query(int l,int r,int num)
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

int n,k,q,x,a,b;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>q;
    segTree st(n);
    fori(0,q)
    {
        cin>>x>>a>>b; a++;
        if(x==0&&a<=n&&k!=0)
        {
            st.updateR(max(1,a-k+1),a,b);
        }
        if(x==1)
        {
            b++;
            if(a>n||a>b||k==0)
                cout<<"0\n";
            else
                cout<<st.query(a,min(b,n))<<"\n";
        }

    }
    return 0;
}