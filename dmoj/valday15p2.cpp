#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int c,m;
    cin>>c>>m;
    int songs[c+1][m+1];
    int princess[c+1][2];
    for(int i=1;i<=c;i++)
    {
        cin>>princess[i][1]>>princess[i][0];
    }
    for(int i=0;i<=c;i++)
    {
        for(int j=0;j<=m;j++)
            songs[i][j]=0;
    }
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(princess[i][0]<=j&&songs[i-1][j]<princess[i][1]+songs[i-1][j-princess[i][0]])
            {
                songs[i][j]=princess[i][1]+songs[i-1][j-princess[i][0]];
            }
            else
                songs[i][j]=songs[i-1][j];
        }
    }
    cout<<songs[c][m];
    return 0;
}