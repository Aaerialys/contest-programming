#include <bits/stdc++.h>

using namespace std;

    int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str1,str2;
    int a,b,c,x,y;
    cin>>a>>b>>c>>str1>>str2;
    x=str1.length();
    y=str2.length();
    int best[x+1][y+1];
    best[0][0]=0;
    for(int i=0;i<=x;i++)
    {
        best[i][0]=a*i;
    }
    for(int i=0;i<=y;i++)
    {
        best[0][i]=b*i;
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(str1[i-1]==str2[j-1])
                best[i][j]=best[i-1][j-1];
            else
            {
                best[i][j]=best[i-1][j-1]+c;
                if(best[i][j]>best[i-1][j]+a)
                    best[i][j]=best[i-1][j]+a;
                if(best[i][j]>best[i][j-1]+b)
                    best[i][j]=best[i][j-1]+b;
            }
        }
    }
    cout<<best[x][y];
    return 0;
}