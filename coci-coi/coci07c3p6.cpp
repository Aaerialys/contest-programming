#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=262144;

int arr[NN];

struct node
{
    int l,r;
    long long v[10],lz;
};

class segTree
{
public:
    int N;
    node seg[2*NN];
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
        seg[num].lz=0;
        if(l==r)
        {
            fori(0,10)
                seg[num].v[i]=0;
            if(arr[r-1]!=-1)
                seg[num].v[arr[r-1]]=1;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
        fori(0,10)
            seg[num].v[i]=seg[2*num].v[i]+seg[2*num+1].v[i];
    }
    void pushDown(int num)
    {
        int numb[10];
        fori(0,10)
            numb[i]=seg[num].v[i];
        fori(0,10)
            seg[num].v[(i+seg[num].lz)%10]=numb[i];
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
            seg[num].lz++;
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
        fori(0,10)
            seg[num].v[i]=seg[2*num].v[i]+seg[2*num+1].v[i];
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
        {
            int t=0;
            fori(0,10)
                t+=seg[num].v[i]*i;
            return t;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        else if(l>mid)
            return query(l,r,2*num+1);
        return query(l,mid,2*num)+query(mid+1,r,2*num+1);
    }
};

string x;
int n,m,a,b;
segTree st(NN);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,NN)
        arr[i]=-1;
    cin>>n>>m>>x;
    fori(0,n)
        arr[i]=x[i]-'0';
    st.build();
    fori(0,m)
    {
        cin>>a>>b;
        cout<<st.query(a,b)<<"\n";
        st.updateR(a,b,1);
    }
    return 0;
}
/**
segtree store amount of each number (how many 0s, 1s, 2s,...)
when increment, 0s become 1s, 9s become 0s
*/