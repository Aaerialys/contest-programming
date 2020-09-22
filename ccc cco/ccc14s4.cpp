#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,t,a[1001],b[1001],c[1001],d[1001],e[1001],cx=0,cy=0,dif[2001][2001];
long long ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    map<int,int> rx,ry;
    vector<int>x,y;
    fori(0,n)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
        rx[a[i]]=0;rx[c[i]]=0;ry[b[i]]=0;ry[d[i]]=0;
    }
    for(auto &it:rx)
    {
        it.second=cx++;
        x.push_back(it.first);
    }
    for(auto &it:ry)
    {
        it.second=cy++;
        y.push_back(it.first);
    }
    fori(0,n)
    {
        dif[rx[a[i]]+1][ry[b[i]]+1]+=e[i];
        dif[rx[c[i]]+1][ry[d[i]]+1]+=e[i];
        dif[rx[a[i]]+1][ry[d[i]]+1]-=e[i];
        dif[rx[c[i]]+1][ry[b[i]]+1]-=e[i];
    }
    fori(0,cx)
    {
        forj(0,cy)
        {
            dif[i+1][j+1]+=dif[i][j+1]+dif[i+1][j]-dif[i][j];
            if(dif[i+1][j+1]>=t)
                ans+=1LL*(x[i+1]-x[i])*(y[j+1]-y[j]);
        }
    }
    cout<<ans;
    return 0;
}