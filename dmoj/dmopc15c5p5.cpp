#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const long long N=200100,M=1000000007;
long long tree[N];

class biTree
{
    public:
    void add(long long x,long long v)
    {
        while(x<=N)
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

biTree bit;
long long n,x,y,o[N],ans[N];
vector<long long> gr[N];

void dfs(long long v)
{
    long long old=bit.addto(o[v]);
    fori(0,gr[v].size())
        dfs(gr[v][i]);
    ans[v]=(bit.addto(o[v])-old+1)%M;
    bit.add(o[v],ans[v]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(1,n+1)
    {
        cin>>x;
        gr[x].push_back(i);
    }
    fori(1,n+1)
    {
        cin>>x;
        o[x]=i;
    }
    dfs(gr[0][0]);
    fori(1,n+1)
        cout<<ans[i]<<" ";
    return 0;
}
/*
find value: sum of all nodes visited before it (using binary index tree)
visit all nodes starting from root with dfs
first time at the node, find the value
go through its children
then find the value again
how much the value increased is the real value
nice
*/