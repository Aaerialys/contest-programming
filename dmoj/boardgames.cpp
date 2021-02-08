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

const int N=300010;
int n,m,dist[N];
priority_queue<int> toV;

void dfs()
{
    int x=-toV.top(); toV.pop();
    if(x<=100000&&dist[x*3]>dist[x]+1)
    {
        dist[x*3]=dist[x]+1;
        toV.push(-x*3);
    }
    if(x%2==0&&dist[x/2]>dist[x]+1)
    {
        dist[x/2]=dist[x]+1;
        toV.push(-x/2);
    }
    if(x>1&&dist[x-1]>dist[x]+1)
    {
        dist[x-1]=dist[x]+1;
        toV.push(-x+1);
    }
    if(x>3&&dist[x-3]>dist[x]+1)
    {
        dist[x-3]=dist[x]+1;
        toV.push(-x+3);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m; seto(dist,inf); dist[n]=0; toV.push(-n);
    while(!toV.empty())
        dfs();
    cout<<dist[m];
    return 0;
}