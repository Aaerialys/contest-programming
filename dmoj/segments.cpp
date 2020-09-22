#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
const int NN=1<<18;

struct node
{
    int l,r;
    long long v,lz;
};

class segTree
{
public:
    int N;
    node seg[2*NN];
    segTree()
    {
        N=NN;
        build();
    }
    void build()
    {
        build(1,N,1);
    }
    void build(int l,int r,int num)
    {
        seg[num].l=l; seg[num].r=r;
        seg[num].lz=seg[num].v=0;
        if(l==r)
            return;
        int mid=(l+r)/2;
        build(l,mid,2*num); build(mid+1,r,2*num+1);
    }
    void pushDown(int num)
    {
        seg[num].v+=seg[num].lz;
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
            seg[num].lz+=v;
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
        seg[num].v=max(seg[2*num].v,seg[2*num+1].v);
        pushDown(num);
    }
    int query()
    {
        pushDown(1);
        return seg[1].v;
    }
};

segTree st;
unordered_map<int,int> cord;
int t,n,a,b,m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    forj(0,t)
    {
        vector<pair<int,int>> seg; m=0;
        cin>>n;
        fori(0,n)
        {
            cin>>a>>b;
            seg.push_back({a,-b});
            seg.push_back({b,-a});
        }
        sort(seg.begin(),seg.end());
        fori(0,seg.size())
            cord[seg[i].first]=i+1;
        fori(0,seg.size())
        {
            seg[i].first=cord[seg[i].first];
            seg[i].second=cord[-seg[i].second];
        }
        fori(0,seg.size())
            if(seg[i].first<seg[i].second)
                st.updateR(seg[i].first,seg[i].second,1);
        a=0;
        fori(0,seg.size())
        {
            if(seg[i].first<seg[i].second)
            {
                a++;
                st.updateR(seg[i].first,seg[i].second,-1);
                m=max(m,a+st.query());
            }
            else
                a--;
        }
        cout<<"Case "<<j+1<<": "<<m<<"\n";
    }
    return 0;
}
/*
line sweep the 1st segment

*/