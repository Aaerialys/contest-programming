#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,v,j,best[10010],coin[2010],spend[100010],ans[100010];
pair<int,int> mall[100010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(1,10010)
        best[i]=1e6;
    cin>>n>>v;
    fori(0,n)
        cin>>coin[i];
    fori(0,v)
    {
        cin>>spend[i]>>mall[i].first;
        mall[i].second=i;
    }
    sort(mall,mall+v);
    fori(0,v)
    {
        for(;j<mall[i].first;j++)
            fork(coin[j],10010)
                best[k]=min(best[k],best[k-coin[j]]+1);
        ans[mall[i].second]=best[spend[mall[i].second]];
    }
    fori(0,v)
    {
        if(ans[i]>=1e6)
            cout<<-1<<"\n";
        else
            cout<<ans[i]<<"\n";
    }
    return 0;
}