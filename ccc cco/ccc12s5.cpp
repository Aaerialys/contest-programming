#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int r,c,k,a,b;
    cin>>r>>c>>k;
    int paths[r+1][c+1];
    for(int i=0;i<k;i++)
    {
        cin>>a>>b;
        paths[a][b]=INT_MIN;
    }
    for(int i=0;i<=r;i++)
    {
        paths[i][0]=0;
    }
    for(int i=0;i<=c;i++)
    {
        paths[0][i]=0;
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(paths[i][j]==INT_MIN)
                paths[i][j]=0;
            else
                paths[i][j]=paths[i-1][j]+paths[i][j-1];
            paths[1][1]=1;
        }
    }
    cout<<paths[r][c];
    return 0;
}