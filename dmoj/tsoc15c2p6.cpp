#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long arr[30010];

struct node
{
    int l,r;
    long long v,lz;
};

node seg[60010];
class segTree
{
public:
    int N;
    segTree(int n)
    {
        N=n;
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
            seg[num].v=arr[l-1];
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num);
        build(mid+1,r,2*num+1);
        seg[num].v=min(seg[2*num].v,seg[2*num+1].v);
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
        seg[num].v=min(seg[2*num].v+seg[2*num].lz,seg[2*num+1].v+seg[2*num+1].lz);
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
        return min(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,q,a,b,c;
    cin>>n>>q;
    fori(0,n)
        cin>>arr[i];
    segTree st(n);
    st.build();
    fori(0,q)
    {
        cin>>a>>b>>c;
        st.updateR(a,b,-c);
        cout<<max(0LL,st.query(a,b))<<" "<<max(0LL,st.query(1,n))<<"\n";
    }
    return 0;
}