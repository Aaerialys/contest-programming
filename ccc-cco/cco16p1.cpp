#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

class djSet
{
public:
    int V;
    vector<int> parent;
    vector<int> setsize;
    vector<bool> cycle;
    djSet(int v)
    {
        V=v;
        parent.reserve(V);
        setsize.reserve(V);
        cycle.reserve(V);
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
            setsize[i]=1;
            cycle[i]=false;
        }
    }
    int lead(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=lead(parent[x]);
        }
        return parent[x];
    }
    void link(int x,int y)
    {
        x=lead(x);
        y=lead(y);
        if(x==y)
            cycle[x]=true;
        else
        {
            parent[x]=y;
            setsize[y]+=setsize[x];
        }
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,a,b,s=0,t=0;
    cin>>n>>m>>k;
    djSet fri(n);
    int group[n]={0};
    fori(0,m)
    {
        cin>>a>>b;
        a--;
        b--;
        fri.link(a,b);
    }
    fori(0,n)
    {
        group[fri.lead(i)]++;
    }
    fori(0,n)
    {
        if(group[i]>0)
        {
            t+=(fri.setsize[i]/k)*k;
            if(fri.cycle[i]&&fri.setsize[i]>k)
            {
                s+=(fri.setsize[i]-1)/k+1;
            }
            else if(!fri.cycle[i]&&fri.setsize[i]>k)
            {
                s+=(fri.setsize[i]-1)/k;
            }
        }
    }
    cout<<t<<" "<<s<<endl;
    return 0;
}