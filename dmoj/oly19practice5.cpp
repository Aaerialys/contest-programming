#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<(int)b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1<<18;

class biTree
{
    public:
    ll tree[N]={0};
    void add(int x,int v)
    {
        while(x<=N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    ll addto(int x)
    {
        ll sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};
struct query
{
    ll t,a,b,c,i;
};

biTree b1,b2;
ll n,q,a,b,c,x,y,arr[N];
int ans[N];
query que[N];

void go(int l,int r,int le,int re)
{
    if(l>r)
        return;
    if(le==re)
    {
        fori(l,r+1)
            if(que[i].t==2)
                ans[que[i].i]=le;
        return;
    }
    int mid=(le+re+1)/2;
    fori(l,r+1)
    {
        if(que[i].t==1&&que[i].c>=mid)
        {
            b1.add(que[i].a,1); b1.add(que[i].b+1,-1);
            b2.add(que[i].a,que[i].a-1); b2.add(que[i].b+1,-que[i].b);
        }
        if(que[i].t==2)
            arr[i]=(b1.addto(que[i].b)*que[i].b-b2.addto(que[i].b))-(b1.addto(que[i].a-1)*(que[i].a-1)-b2.addto(que[i].a-1));
    }
    vector<query> left, right;
    fori(l,r+1)
    {
        if(que[i].t==1)
        {
            if(que[i].c>=mid)
            {
                b1.add(que[i].a,-1); b1.add(que[i].b+1,1);
                b2.add(que[i].a,-que[i].a+1); b2.add(que[i].b+1,que[i].b);
                right.push_back(que[i]);
            }
            else
                left.push_back(que[i]);
        }
        if(que[i].t==2)
        {
            if(arr[i]>=que[i].c)
                right.push_back(que[i]);
            else
            {
                que[i].c-=arr[i];
                left.push_back(que[i]);
            }
        }
    }
    fori(0,left.size())
        que[l+i]=left[i];
    fori(0,right.size())
        que[l+left.size()+i]=right[i];
    go(l,l+left.size()-1,le,mid-1);
    go(l+left.size(),r,mid,re);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>q;
    fori(0,q)
    {
        cin>>a;
        if(a==1)
        {
            cin>>a>>b>>c;
            que[i]={1,a,b,c,0};
        }
        else
        {
            cin>>a>>b>>c;
            que[i]={2,a,b,c,y++};
        }
    }
    go(0,q-1,1,N);
    fori(0,y)
        cout<<ans[i]<<"\n";
    return 0;
}