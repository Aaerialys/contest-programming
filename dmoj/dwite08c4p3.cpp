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

int n,a,b,dist[101];
vector<int> gr[101],ans;

void dfs(int v)
{
    for(auto i:gr[v])
        if(dist[i]>dist[v]+1)
        {
            dist[i]=dist[v]+1;
            dfs(i);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    forj(0,5)
    {
        cin>>n; seto(dist,inf); ans.clear();
        fori(0,101)
            gr[i].clear();
        fori(0,n)
        {
            cin>>a>>b;
            if(a==1&&b==2||b==1&&a==2)
                continue;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dist[2]=0; dfs(2);
        a=0;
        for(auto i:gr[1])
            if(dist[i]>2)
                ans.push_back(i);
        if(ans.size()==0)
            cout<<"none";
        else
            for(auto i:ans)
                cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}