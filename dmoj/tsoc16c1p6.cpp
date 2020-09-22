#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,m,edit[1001][1001];
string s1,s2;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,1001)
        forj(0,1001)
            edit[i][j]=INT_MAX;
    edit[0][0]=0;
    fori(0,1001)
        edit[i][0]=edit[0][i]=(i+2)/3;
    cin>>n>>m>>s1>>s2;
    fori(1,n+1)
    {
        forj(1,m+1)
        {
            if(s1[i-1]==s2[j-1])
                edit[i][j]=edit[i-1][j-1];
            edit[i][j]=min(edit[i][j],edit[i][j-1]+1);
            if(j>=2)
                edit[i][j]=min(edit[i][j],edit[i][j-2]+1);
            if(j>=3)
                edit[i][j]=min(edit[i][j],edit[i][j-3]+1);
            edit[i][j]=min(edit[i][j],edit[i-1][j]+1);
            if(i>=2)
                edit[i][j]=min(edit[i][j],edit[i-2][j]+1);
            if(i>=3)
                edit[i][j]=min(edit[i][j],edit[i-3][j]+1);
            edit[i][j]=min(edit[i][j],edit[i-1][j-1]+1);
        }
    }
    cout<<edit[n][m]<<endl;
    return 0;
}