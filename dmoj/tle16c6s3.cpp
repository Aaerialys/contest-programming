#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,o,fax[2001][2001][2],y[2001];
pair<long long,long long> x[2001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>x[i].first>>x[i].second;
    sort(x,x+n);
    y[0]=0;
    fori(1,n+1)
    {
        y[i]=y[i-1]+x[i-1].second;
        if(x[i-1].first==0)
            o=fax[i-1][i-1][0]=fax[i-1][i-1][1]=x[i-1].second;
    }
    fori(1,n)
    {
        forj(0,n-i)
        {
            if(fax[j+1][j+i][0]>=x[j+1].first-x[j].first)
                fax[j][j+i][0]=max(fax[j][j+i][0],fax[j+1][j+i][0]+x[j].second-x[j+1].first+x[j].first);
            if(fax[j+1][j+i][1]>=x[j+i].first-x[j].first)
                fax[j][j+i][0]=max(fax[j][j+i][0],fax[j+1][j+i][1]+x[j].second-x[j+i].first+x[j].first);
            if(fax[j][j+i-1][1]>=x[j+i].first-x[j+i-1].first)
                fax[j][j+i][1]=max(fax[j][j+i][1],fax[j][j+i-1][1]+x[j+i].second-x[j+i].first+x[j+i-1].first);
            if(fax[j][j+i-1][0]>=x[j+i].first-x[j].first)
                fax[j][j+i][1]=max(fax[j][j+i][1],fax[j][j+i-1][0]+x[j+i].second-x[j+i].first+x[j].first);
            if(max(fax[j][j+i][0],fax[j][j+i][1])>0)
                o=max(o,y[j+i+1]-y[j]);
        }
    }
    cout<<o;
    return 0;
}