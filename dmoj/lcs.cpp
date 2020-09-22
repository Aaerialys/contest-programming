#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b,s1[1001],s2[1001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    fori(0,a)
        cin>>s1[i];
    fori(0,b)
        cin>>s2[i];
    int m[a+1][b+1];
    for(int i=0;i<=a;i++)
        m[i][0]=0;
    for(int i=0;i<=b;i++)
        m[0][i]=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                m[i][j]=m[i-1][j-1]+1;
            }
            else
            {
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    cout<<m[a][b];
    return 0;
}