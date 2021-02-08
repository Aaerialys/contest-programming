#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

const int N=2048;

using namespace std;

struct node
{
    int l,r;
    long long v,lz;
};

node seg[2*N]; //4*NN if NN is not a power of 2
class segTree
{
public:
    segTree()
    {
        build(1,N,1);
    }
    void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r;
        seg[num].v=INT_MAX;
        if(l==r)
        {
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);\
    }
    void update(int pos,int v)
    {
        update(pos,v,1);
    }
    void update(int pos,int v,int num)
    {
        if(seg[num].l==pos&&seg[num].r==pos)
        {
            seg[num].v=v;
            return;
        }
        int mid=(seg[num].l+seg[num].r)/2;
        if(pos<=mid)
            update(pos,v,2*num);
        else
            update(pos,v,2*num+1);
        seg[num].v=min(seg[2*num].v,seg[2*num+1].v);
    }
    long long query(int l,int r)
    {
        return query(l,r,1);
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
        return min(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
};

int M=1e9+7;
int n,m,q,x,l,r,mid,rnum[2001][5001],lcp[2001][2001],o[2001];
segTree st;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,n)
        forj(1,m+1)
        {
            cin>>ch; x=ch-'0';
            rnum[i][j]=((rnum[i][j-1]<<1)+x)%M;
        }
    fori(0,n)
        forj(0,n)
        {
            l=0; r=m+1;
            while(l<r)
            {
                mid=(l+r)/2;
                if(rnum[i][mid]==rnum[j][mid])
                {
                    l=mid+1;
                    x=mid;
                }
                else
                    r=mid;
            }
            lcp[i][j]=x;
        }
    fori(1,n+1)
        o[i]=i-1;
    fori(1,n)
        st.update(i,lcp[i][i-1]);
    cin>>q;
    fori(0,q)
    {
        cin>>l>>r;
        if(l==r)
        {
            cout<<m*(r-l+1)<<"\n";
            continue;
        }
        cout<<st.query(l,r-1)*(r-l+1)<<"\n";//<<endl;
        swap(o[l],o[r]);
        if(l>1)
            st.update(l-1,lcp[o[l]][o[l-1]]);
        st.update(l,lcp[o[l]][o[l+1]]);
        st.update(r-1,lcp[o[r]][o[r-1]]);
        st.update(r,lcp[o[r]][o[r+1]]);
    }
    return 0;
}