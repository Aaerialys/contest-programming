#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;
long long arr[1000011];

struct node
{
    long long l,r,v,vr,vl,s;
};
node seg[2000011];
long long n,q,a,b;
char ch;

class segTree
{
public:
    long long N;
    segTree(long long n)
    {
        N=n;
    }
    void build(long long l,long long r,long long num)
    {
        seg[num].l=l;
        seg[num].r=r;
        if(l==r)
        {
            seg[num].s=seg[num].v=seg[num].vr=seg[num].vl=arr[l-1];
            return;
        }
        long long mid=(l+r)/2;
        build(l,mid,2*num);
        build(mid+1,r,2*num+1);
        seg[num].v=max(max(seg[2*num].v,seg[2*num+1].v),seg[2*num].vr+seg[2*num+1].vl);
        seg[num].s=seg[2*num].s+seg[2*num+1].s;
        seg[num].vl=max(seg[2*num].vl,seg[2*num].s+seg[2*num+1].vl);
        seg[num].vr=max(seg[2*num+1].vr,seg[2*num+1].s+seg[2*num].vr);
    }
    void update(long long pos,long long v)
    {
        update(pos,v,1);
    }
    void update(long long pos,long long v,long long num)
    {
        if(seg[num].l==pos&&seg[num].r==pos)
        {
            seg[num].s=seg[num].v=seg[num].vr=seg[num].vl=v;
            return;
        }
        long long mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,2*num);
        else
            update(pos,v,2*num+1);
        seg[num].v=max(max(seg[2*num].v,seg[2*num+1].v),seg[2*num].vr+seg[2*num+1].vl);
        seg[num].s=seg[2*num].s+seg[2*num+1].s;
        seg[num].vl=max(seg[2*num].vl,seg[2*num].s+seg[2*num+1].vl);
        seg[num].vr=max(seg[2*num+1].vr,seg[2*num+1].s+seg[2*num].vr);
    }
    long long queryl(long long l,long long r,long long num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].vl;
        long long mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return queryl(l,r,2*num);
        else if(l>mid)
            return queryl(l,r,2*num+1);
        return max(seg[2*num].vl,seg[2*num].s+queryl(mid+1,r,2*num+1));
    }
    long long queryr(long long l,long long r,long long num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].vr;
        long long mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return queryr(l,r,2*num);
        else if(l>mid)
            return queryr(l,r,2*num+1);
        return max(seg[2*num+1].vr,seg[2*num+1].s+queryr(l,mid,2*num));
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
        return max(max(max(query(l,mid,2*num),query(mid+1,r,2*num+1)),max(queryr(l,mid,2*num),queryl(mid+1,r,2*num+1))),queryr(l,mid,2*num)+queryl(mid+1,r,2*num+1));
    }
};

segTree st(100011);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    fori(0,n)
        cin>>arr[i];
    st.build(1,n,1);
    fori(0,q)
    {
        cin>>ch>>a>>b;
        if(ch=='S')
            st.update(a,b);
        if(ch=='Q')
            cout<<st.query(a,b)<<"\n";
    }
    return 0;
}