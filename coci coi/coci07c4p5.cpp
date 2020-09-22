#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=524288*2;

struct node
{
    int l,r,v;
};

class segTree
{
public:
    int N;
    node seg[2*NN+10];
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
        if(l==r)
        {
            seg[num].v=0;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
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
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
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
        else if(l>mid)
            return query(l,r,2*num+1);
        return max(query(l,mid,2*num),query(mid+1,r,2*num+1));
    }
};

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

segTree st(NN);
int n,dp[100010],x,z,m;
pair<int,int> in[100010];
stack<pair<int,int>> seq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    st.build();
    cin>>n;
    fori(0,n)
        cin>>in[i].first>>in[i].second;
    sort(in,in+n,cmp);
    fori(0,n)
    {
        dp[i]=st.query(in[i].second,NN)+1;
        if(dp[i]>m)
        {
            m=dp[i];
            x=in[i].second;
            z=i;
        }
        st.update(in[i].second,dp[i]);
    }
    seq.push({in[z].first,in[z].second});
    cout<<m<<"\n";
    for(int i=z-1;i>=0;i--)
    {
        if(dp[i]==m-1&&in[i].second>=x)
        {
            m--;
            x=in[i].second;
            seq.push({in[i].first,in[i].second});
        }
    }
    while(!seq.empty())
    {
        cout<<seq.top().first<<" "<<seq.top().second<<"\n";
        seq.pop();
    }
    return 0;
}