#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int pre[1100000];
int dist[1100000];
int nxt[1100000];
int m,n,a,b,c,g;

int next(int x)
{
    int w=x,y=m*n,z;
    fori(0,y)
    {
        z=0;
        if(i>=m&&x&(1<<(i-m)))
            z++;
        if(i<y-m&&x&(1<<(i+m)))
            z++;
        if(i%m>0&&x&(1<<(i-1)))
            z++;
        if(i%m<m-1&&x&(1<<(i+1)))
            z++;
        if(i>=m&&i%m>0&&x&(1<<(i-m-1)))
            z++;
        if(i>=m&&i%m<m-1&&x&(1<<(i-m+1)))
            z++;
        if(i<y-m&&i%m>0&&x&(1<<(i+m-1)))
            z++;
        if(i<y-m&&i%m<m-1&&x&(1<<(i+m+1)))
            z++;
        if(z<a||z>b)
           w=w&~(1<<i);
        if(!(x&(1<<i))&&z>c)
            w=w|(1<<i);
    }
    return w;
}

int main()
{
    cin>>n>>m>>a>>b>>c;
    int x=m*n,v;
    char ch;
    g=0;
    fori(0,x)
    {
        cin>>ch;
        if(ch=='*')
            g=g|1<<i;
    }
    x=1<<x;
    fori(0,x)
    {
        dist[i]=INT_MAX;
        pre[i]=INT_MAX;
    }
    fori(0,x)
    {
        pre[next(i)]=i;
        nxt[i]=next(i);
    }
    queue<int> nV;
    fori(0,x)
    {
        if(pre[i]==INT_MAX)
        {
            nV.push(i);
            dist[i]=0;
        }
    }
    while(!nV.empty())
    {
        v=nV.front();
        nV.pop();
        if(dist[nxt[v]]>dist[v]+1)
        {
            dist[nxt[v]]=dist[v]+1;
            nV.push(nxt[v]);
        }
    }
    if(dist[g]==INT_MAX)
        cout<<-1<<endl;
    else
        cout<<dist[g]<<endl;
    return 0;
}