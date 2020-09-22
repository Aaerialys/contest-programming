#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t,chap,cprep,cern,ctime;
    cin>>n;
    int ern[n+1],hap[n+1],prep[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>hap[i]>>ern[i]>>prep[i];
    }
    cin>>t;
    int best[n+1][t+1];
    int time[n+1][t+1];
    for(int i=0;i<=n;i++)
    {
        best[i][0]=0;
        time[i][0]=0;
    }
    for(int i=0;i<=t;i++)
    {
        best[0][i]=0;
        time[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            chap=hap[i];
            cprep=prep[i];
            cern=0;
            ctime=1;
            best[i][j]=best[i-1][j];
            time[i][j]=time[i-1][j];
            while(cern<hap[i])
            {
                if(j>=cprep&&best[i][j]<best[i-1][j-cprep]+chap)
                {
                    best[i][j]=best[i-1][j-cprep]+chap;
                    time[i][j]=time[i-1][j-cprep]+ctime;
                }
                else if(j>=cprep&&best[i][j]==best[i-1][j-cprep]+chap&&time[i][j]>time[i-1][j-cprep]+ctime)
                {
                    time[i][j]=time[i-1][j-cprep]+ctime;
                }
                cern+=ern[i];
                chap+=hap[i]-cern;
                cprep+=prep[i];
                ctime++;
            }
        }
    }
    cout<<best[n][t]<<endl;
    cout<<time[n][t]<<endl;
    return 0;
}