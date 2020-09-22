#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,m[1010][1010],w[2][1010],p[2][1010];
char ch;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(1,n+1)
    {
        cin>>ch;
        if(ch=='W')
            w[0][i]=1;
    }
    fori(1,n+1)
        cin>>p[0][i];
    fori(1,n+1)
    {
        cin>>ch;
        if(ch=='W')
            w[1][i]=1;
    }
    fori(1,n+1)
        cin>>p[1][i];
    fori(1,n+1)
    {
        forj(1,n+1)
        {
            m[i][j]=max(m[i-1][j],m[i][j-1]);
            if((w[0][i]&&!w[1][j]&&p[0][i]>p[1][j])||(!w[0][i]&&w[1][j]&&p[0][i]<p[1][j]))
                m[i][j]=max(m[i][j],m[i-1][j-1]+p[0][i]+p[1][j]);
        }
    }
    cout<<m[n][n];
    return 0;
}