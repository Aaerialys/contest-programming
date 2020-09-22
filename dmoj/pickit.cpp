#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n;
    while(n!=0)
    {
        int numbs[n];
        int best[n][n];
        for(int i=0;i<n;i++)
            cin>>numbs[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                best[i][j]=0;
        }
        for(int i=0;i<n-2;i++)
        {
            best[i][i+2]=numbs[i]+numbs[i+1]+numbs[i+2];
        }
        for(int i=3;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                for(int k=j+1;k<j+i;k++)
                {
                    t=numbs[j]+numbs[k]+numbs[j+i]+best[j][k]+best[k][j+i];
                    if(t>best[j][j+i])
                        best[j][j+i]=t;
                }
            }
        }
        cout<<best[0][n-1]<<"\n";
        cin>>n;
    }
    return 0;
}