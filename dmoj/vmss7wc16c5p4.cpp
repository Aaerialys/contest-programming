#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int best[n+1];
    for(int i=0;i<=n;i++)
        best[i]=INT_MIN;
    best[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i>=a&&best[i-a]+1>best[i])
        {
            best[i]=best[i-a]+1;
        }
        if(i>=b&&best[i-b]+1>best[i])
        {
            best[i]=best[i-b]+1;
        }
        if(i>=c&&best[i-c]+1>best[i])
        {
            best[i]=best[i-c]+1;
        }
    }
    cout<<best[n];
    return 0;
}