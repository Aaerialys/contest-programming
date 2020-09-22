#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=131072;

int arr[NN];

struct node
{
    int l,r;
    long long v[21],lz;
};
node seg[2*NN];

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
        seg[num].l=l; seg[num].r=r;
        seg[num].lz=-1;
        if(l==r)
        {
            fori(1,21)
                seg[num].v[i]=0;
            if(arr[r-1]!=-1)
                seg[num].v[arr[r-1]]=1;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
        fori(0,21)
            seg[num].v[i]=seg[2*num].v[i]+seg[2*num+1].v[i];
    }
    void pushDown(int num)
    {
        if(seg[num].lz==-1)
            return;
        fori(1,21)
            seg[num].v[i]=0;
        seg[num].v[seg[num].lz]=seg[num].r-seg[num].l+1;
        if(seg[num].l!=seg[num].r)
        {
            seg[2*num].lz=seg[num].lz;
            seg[2*num+1].lz=seg[num].lz;
        }
        seg[num].lz=-1;
    }
    void updateR(int l,int r,int ct)
    {
        updateR(l,r,ct,1);
    }
    void updateR(int l,int r,int ct,int num)
    {
        pushDown(num);
        if(seg[num].l==l&&seg[num].r==r)
        {
            seg[num].lz=ct;
            pushDown(num);
            return;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            updateR(l,r,ct,2*num);
        else if(l>mid)
            updateR(l,r,ct,2*num+1);
        else
        {
            updateR(l,mid,ct,2*num);
            updateR(mid+1,r,ct,2*num+1);
        }
        pushDown(2*num); pushDown(2*num+1);
        fori(1,21)
            seg[num].v[i]=seg[2*num].v[i]+seg[2*num+1].v[i];
    }
    long long query(int l,int r,int ct)
    {
        return query(l,r,ct,1);
    }
    long long query(int l,int r,int ct,int num)
    {
        pushDown(num);
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v[ct];
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,ct,2*num);
        else if(l>mid)
            return query(l,r,ct,2*num+1);
        return query(l,mid,ct,2*num)+query(mid+1,r,ct,2*num+1);
    }
    void out()
    {
        out(1);
    }
    void out(int num)
    {
        pushDown(num);
        if(seg[num].l==seg[num].r)
        {
            fori(1,21)
                if(seg[num].v[i]>0)
                {
                    cout<<i<<" ";
                    return;
                }
            return;
        }
        out(2*num); out(2*num+1);
    }
};

int n,m,a,b,k,fav[21],numb[21];
segTree st(NN);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,NN)
        arr[i]=-1;
    cin>>n>>m>>k;
    fori(0,n)
        cin>>arr[i];
    st.build();
    fori(0,m)
    {
        cin>>a>>b;
        fori(1,k+1)
            numb[i]=st.query(a,b,i);
        fori(1,k+1)
            cin>>fav[i];
        fori(1,k+1)
        {
            if(numb[fav[i]]>0)
                st.updateR(a,a+numb[fav[i]]-1,fav[i]);
            a+=numb[fav[i]];
        }
    }
    st.out();
    return 0;
}
/**
segtree store amount of each number (how many 0s, 1s, 2s,...)
when increment, 0s become 1s, 9s become 0s
*/