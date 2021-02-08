#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int arr[100010];

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

struct node
{
    int l,r,v,v1,v2;
};

class segTree
{
public:
    node seg[300010];
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
        if(l==r)
        {
            seg[num].v=arr[l-1];
            seg[num].v1=arr[l-1];
            seg[num].v2=1;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num);
        build(mid+1,r,2*num+1);
        seg[num].v=min(seg[2*num].v,seg[2*num+1].v);
        seg[num].v1=gcd(seg[2*num].v1,seg[2*num+1].v1);
        seg[num].v2=0;
        if(seg[num].v1==seg[2*num].v1)
            seg[num].v2+=seg[2*num].v2;
        if(seg[num].v1==seg[2*num+1].v1)
            seg[num].v2+=seg[2*num+1].v2;
    }
    void update(int pos,int v)
    {
        update(pos+1,v,1);
    }
    void update(int pos,int v,int num)
    {
        if(seg[num].l==pos&&seg[num].r==pos)
        {
            seg[num].v=v;
            seg[num].v1=v;
            return;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,2*num);
        else
            update(pos,v,2*num+1);
        seg[num].v=min(seg[2*num].v,seg[2*num+1].v);
        seg[num].v1=gcd(seg[2*num].v1,seg[2*num+1].v1);
        seg[num].v2=0;
        if(seg[num].v1==seg[2*num].v1)
            seg[num].v2+=seg[2*num].v2;
        if(seg[num].v1==seg[2*num+1].v1)
            seg[num].v2+=seg[2*num+1].v2;
    }
    int query(int l,int r)
    {
        return query(l+1,r+1,1);
    }
    int query(int l,int r,int num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        else if(l>mid)
            return query(l,r,2*num+1);
        else
            return min(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
    int query2(int l,int r)
    {
        return query2(l+1,r+1,1);
    }
    int query2(int l,int r,int num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v1;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query2(l,r,2*num);
        else if(l>mid)
            return query2(l,r,2*num+1);
        else
            return gcd(query2(l,mid,2*num),query2(mid+1,r,2*num+1));
    }
    int query3(int l,int r)
    {
        return query3(l+1,r+1,1);
    }
    int query3(int l,int r,int num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v2;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query3(l,r,2*num);
        else if(l>mid)
            return query3(l,r,2*num+1);
        else
        {
            int t=0,t1=query2(l,mid,2*num),t2=query2(mid+1,r,2*num+1);
            if(gcd(t1,t2)==t1)
                t+=query3(l,mid,2*num);
            if(gcd(t1,t2)==t2)
                t+=query3(mid+1,r,2*num+1);
            return t;
        }
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q,a,b;
    char ch;
    cin>>n>>q;
    fori(0,n)
    {
        cin>>arr[i];
    }
    segTree st(n);
    st.build();
    fori(0,q)
    {
        cin>>ch>>a>>b;
        a--;
        b--;
        if(ch=='C')
        {
            st.update(a,b+1);
        }
        if(ch=='M')
        {
            cout<<st.query(a,b)<<"\n";
        }
        if(ch=='G')
        {
            cout<<st.query2(a,b)<<"\n";
        }
        if(ch=='Q')
        {
            cout<<st.query3(a,b)<<"\n";
        }
    }
    return 0;
}