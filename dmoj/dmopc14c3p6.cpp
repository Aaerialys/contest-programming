#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    int best[2][t+1];
    int prob[n+1][6];
    for(int i=1;i<=n;i++)
    {
        cin>>prob[i][0]>>prob[i][1]>>prob[i][2]>>prob[i][3]>>prob[i][4]>>prob[i][5];
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<=t;j++){
            best[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            best[1][j]=best[0][j];
            if(j>=prob[i][0]&&best[1][j]<prob[i][1]+best[0][j-prob[i][0]])
                best[1][j]=prob[i][1]+best[0][j-prob[i][0]];
            if(j>=prob[i][2]&&best[1][j]<prob[i][3]+best[0][j-prob[i][2]])
                best[1][j]=prob[i][3]+best[0][j-prob[i][2]];
            if(j>=prob[i][4]&&best[1][j]<prob[i][5]+best[0][j-prob[i][4]])
                best[1][j]=prob[i][5]+best[0][j-prob[i][4]];
        }
        for(int j=0;j<=t;j++)
        {
            best[0][j]=best[1][j];
        }
    }
    cout<<best[1][t];
    return 0;
}