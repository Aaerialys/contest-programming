#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,minn=0,maxx=1;
    cin>>n;
    int amount[101]={0};
    amount[0]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        amount[a]++;
    }
    for(int i=1;i<101;i++)
    {
        if(amount[i]<amount[minn]&&amount[i]>0)
            minn=i;
        if(amount[i]>=amount[maxx])
            maxx=i;
    }
    if(maxx>minn)
        cout<<maxx-minn;
    else
        cout<<minn-maxx;
    return 0;
}