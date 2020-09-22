#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

struct node
{
    long long l,r,v,o1;
};
long long arr[100010];
node seg[400010];

class segTree
{
public:
    long long N;
    segTree(long long n)
    {
        N=n;
    }
    void build()
    {
        build(1,N,1);
    }
    void build(long long l,long long r,long long num)
    {
        seg[num].l=l; seg[num].r=r;
        if(l==r)
        {
            seg[num].v=arr[l-1];
            seg[num].o1=0;
            if(seg[num].v<=1)
                seg[num].o1=1;
            return;
        }
        long long mid=(l+r)/2;
        build(l,mid,2*num);
        build(mid+1,r,2*num+1);
        seg[num].v=seg[2*num].v+seg[2*num+1].v;
        if(seg[2*num].o1==1&&seg[2*num+1].o1==1)
            seg[num].o1=1;
    }
    long long query(long long l,long long r)
    {
        return query(l,r,1);
    }
    long long query(long long l,long long r,long long num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        long long mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        else if(l>mid)
            return query(l,r,2*num+1);
        else
            return query(l,mid,2*num)+query(mid+1,r,2*num+1);
    }
    void sq(long long l,long long r)
    {
        return sq(l,r,1);
    }
    void sq(long long l,long long r,long long num)
    {
        if(seg[num].o1)
            return;
        if(seg[num].l==seg[num].r)
        {
            seg[num].v=sqrt(seg[num].v);
            if(seg[num].v<=1)
                seg[num].o1=1;
            return;
        }
        long long mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            sq(l,r,2*num);
        else if(l>mid)
            sq(l,r,2*num+1);
        else
        {
            sq(l,mid,2*num);
            sq(mid+1,r,2*num+1);
        }
        seg[num].v=seg[2*num].v+seg[2*num+1].v;
        if(seg[2*num].o1&&seg[2*num+1].o1)
            seg[num].o1=1;
    }
};

long long n,q,a,b,c;
segTree st(100010);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>arr[i];
    st.build();
    cin>>q;
    fori(0,q)
    {
        cin>>a>>b>>c;
        if(a==1)
            cout<<st.query(b,c)<<"\n";
        if(a==2)
            st.sq(b,c);
    }
    return 0;
}