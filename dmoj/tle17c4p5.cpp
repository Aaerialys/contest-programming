#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=1<<18;
int n,M,x,pnum[N],last[N],prime[N];

long long fpow(long long a,long long b)
{
    if(b==0)
        return 1;
    long long t=fpow(a,b/2);
    if(b&1)
        return t*t%M*a%M;
    return t*t%M;
}

struct node
{
    int l,r;
    long long v,n;
};

class segTree
{
public:
    node seg[2*N]; //4*NN if NN is not a power of 2
    segTree()
    {
        build();
    }
    void build()
    {
        build(1,N,1);
    }
    void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r; seg[num].v=1; seg[num].n=0;
        if(l==r)
            return;
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
    }
    void update(int pos,int v)
    {
        update(pos,v,1);
    }
    void update(int pos,int v,int num)
    {
        if(seg[num].l==pos&&seg[num].r==pos)
        {
            seg[num].n+=v;
            seg[num].v=fpow(prime[pos],seg[num].n);
            return;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,2*num);
        else
            update(pos,v,2*num+1);
        seg[num].v=seg[2*num].v*seg[2*num+1].v%M;
    }
    long long query()
    {
        return query(1,N,1);
    }
    long long query(int l,int r,int num)
    {
        if(seg[num].l==l&&seg[num].r==r)
            return seg[num].v;
        int mid=(seg[num].l+seg[num].r)/2;
        if(r<=mid)
            return query(l,r,2*num);
        if(l>mid)
            return query(l,r,2*num+1);
        return query(l,mid,2*num)*query(mid+1,r,2*num+1)%M;
    }
};
segTree st;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>M;
    fori(1,N)
        last[i]=i;
    fori(2,N)
    {
        if(last[i]==i)
        {
            pnum[i]=++x; prime[x]=i;
            for(int j=i*2;j<N;j+=i)
                last[j]=i;
        }
    }
    fori(1,n+2)
    {
        cout<<st.query()<<"\n";
        x=n-i+1;
        while(x>1)
        {
            st.update(pnum[last[x]],1);
            x/=last[x];
        }
        x=i;
        while(x>1)
        {
            st.update(pnum[last[x]],-1);
            x/=last[x];
        }
    }
    return 0;
}