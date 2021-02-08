#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int arr[100010];

struct node
{
    int l,r,v,v1;
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
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num);
        build(mid+1,r,2*num+1);
        seg[num].v=min(seg[2*num].v,seg[2*num+1].v);
        seg[num].v1=max(seg[2*num].v1,seg[2*num+1].v1);
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
            return max(query2(l,mid,2*num),query2(mid+1,r,2*num+1));
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
        cin>>a>>b;
        a--;
        b--;
        cout<<st.query2(a,b)-st.query(a,b)<<"\n";
    }
    return 0;
}