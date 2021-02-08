#include <bits/stdc++.h>

using namespace std;

char octo[2002][2002];
int tri[2002][2002];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>octo[i][j];
        }
    }
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(octo[i][j]=='#')
            {
                tri[i][j]=tri[i+1][j]+1;
                if(tri[i][j]>tri[i+1][j-1]+1)
                    tri[i][j]=tri[i+1][j-1]+1;
                if(tri[i][j]>tri[i+1][j+1]+1)
                    tri[i][j]=tri[i+1][j+1]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            t+=tri[i][j];
    }
    cout<<t<<endl;
    return 0;
}