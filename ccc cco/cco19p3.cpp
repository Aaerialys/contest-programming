#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
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

const int N=200010;
ll n,x,y,a,b,pop[N],sz[N],t,ssz[N],m,K;
vector<int> gr[N];
set<ll> sum;

void sizedfs(int v,int p)
{
    sz[v]=pop[v];
    for(auto i:gr[v])
        if(i!=p)
        {
            sizedfs(i,v);
            sz[v]+=sz[i];
        }
}
int getCenter(int v,int p)
{
    for(auto i:gr[v])
        if(i!=p&&sz[i]*2>K)
            return getCenter(i,v);
    return v;
}
void dfs(int v,int p)
{
    sz[v]=pop[v];
    for(auto i:gr[v])
    {
        if(i==p)
            continue;
        dfs(i,v);
        sz[v]+=sz[i];
    }
    t+=pop[v]*(sz[v]-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("winter.1-02.in", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>pop[i];
        K+=pop[i];
    }
    fori(1,n)
    {
        cin>>x; x--;
        gr[x].push_back(i);
        gr[i].push_back(x);
    }
    sizedfs(0,-1);
    x=getCenter(0,-1);
    seto(sz,0);
    fori(0,gr[x].size())
    {
        dfs(gr[x][i],x);
        sz[x]+=sz[gr[x][i]];
        ssz[i]=sz[gr[x][i]];
    }
    t+=(sz[x]+pop[x]-1)*pop[x];
    m=gr[x].size()/2;
    fori(0,1<<m)
    {
        a=0;
        forj(0,m)
            if(i&(1<<j))
                a+=ssz[j];
        sum.insert(a);
    }
    sum.insert(-inf); sum.insert(inf);
    n=gr[x].size()-m;
    fori(0,1<<n)
    {
        a=0;
        forj(0,n)
            if(i&(1<<j))
                a+=ssz[j+m];
        b=*sum.upper_bound(sz[x]/2-a);
        if(abs(sz[x]-2*a-2*b)<abs(sz[x]-2*y))
            y=a+b;
        b=*prev(sum.upper_bound(sz[x]/2-a),1);
        if(abs(sz[x]-2*a-2*b)<abs(sz[x]-2*y))
            y=a+b;
    }
    t+=y*(sz[x]-y);
    cout<<t<<"\n";
    return 0;
}

/** big brain:
tree:
at each node, consider all nodes connected
start at centroid
partition subtrees into 2 sets so that incoming*outgoing is max
outgoing=total-root-incoming, t=total-root
maximum when incoming is closest to t/2
split children into 2 groups, use meet in middle to find closest sum to t/2
do dfs to find the number of letters sent inside each subtree, will be the same incoming or outgoing
add all of those to the total
*/