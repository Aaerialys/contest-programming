#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pii;

const long long N=200100;
long long tree[N];

class biTree
{
    public:
    void add(long long x,long long v)
    {
        while(x<N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    long long addto(long long x)
    {
        long long sum=0;
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
    long long t,a,b,c,i;
};

biTree bit;
long long n,q,a,b,c,x,y,arr[N*3],ans[N];
query que[N*3];

void go(long long l,long long r,long long le,long long re)
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
    long long mid=(le+re)/2;
    fori(l,r+1)
    {
        if(que[i].t==0&&que[i].b<=mid)
            bit.add(que[i].a,-1);
        if(que[i].t==1&&que[i].b<=mid)
            bit.add(que[i].a,1);
        if(que[i].t==2)
            arr[i]=bit.addto(que[i].b)-bit.addto(que[i].a-1);
    }
    vector<query> left, right;
    fori(l,r+1)
    {
        if(que[i].t==0)
        {
            if(que[i].b<=mid)
            {
                bit.add(que[i].a,1);
                left.push_back(que[i]);
            }
            else
                right.push_back(que[i]);

        }
        if(que[i].t==1)
        {
            if(que[i].b<=mid)
            {
                bit.add(que[i].a,-1);
                left.push_back(que[i]);
            }
            else
                right.push_back(que[i]);
        }
        if(que[i].t==2)
        {
            if(arr[i]>=que[i].c)
                left.push_back(que[i]);
            else
            {
                que[i].c-=arr[i];
                right.push_back(que[i]);
            }
        }
    }
    fori(0,left.size())
        que[l+i]=left[i];
    fori(0,right.size())
        que[l+left.size()+i]=right[i];
    go(l,l+left.size()-1,le,mid);
    go(l+left.size(),r,mid+1,re);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(1,n+1)
    {
        cin>>arr[i];
        que[x++]={1,i,arr[i],0,0};
    }
    cin>>q;
    fori(0,q)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            que[x++]={0,b,arr[b],0,0};
            que[x++]={1,b,c,0,0};
            arr[b]=c;
        }
        if(a==2)
        {
            cin>>a>>b>>c;
            que[x++]={2,a,b,c,y++};
        }
    }
    go(0,x-1,1,1e9+1);
    fori(0,y)
        cout<<ans[i]<<"\n";
    return 0;
}