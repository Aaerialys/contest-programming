#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=131072;

struct node
{
    int l,r;
    long long v,m;
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
        seg[num].v=seg[num].m=0;
        if(l==r)
        {
            return;
        }
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
            seg[num].v+=v;
            seg[num].m=seg[num].v;
            return;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,2*num);
        else
            update(pos,v,2*num+1);
        seg[num].v=seg[2*num].v+seg[2*num+1].v;
        seg[num].m=min(seg[2*num].m,seg[2*num].v+seg[2*num+1].m);
    }
    long long query()
    {
        return seg[1].m;
    }
};

segTree st(NN);
int n,bin[NN],ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    st.build();
    cin>>n;
    fori(1,n+1)
        cin>>bin[i];
    fori(1,n/2+1)
    {
        st.update(bin[i],-2); st.update(bin[i*2-1],1); st.update(bin[i*2],1);
        if(st.query()>=0)
            ans=i;
    }
    cout<<ans;
    return 0;
}