#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

char b[6][6][6];
int t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,6)
        forj(0,6)
            fork(0,6)
                cin>>b[i][j][k];
    fori(0,6)
        forj(0,6)
            fork(0,6)
            {
                if(i<3&&b[i][j][k]=='R'&&b[i][j][k]==b[i+1][j][k]&&b[i+1][j][k]==b[i+2][j][k]&&b[i+2][j][k]==b[i+3][j][k])
                    t++;
                if(j<3&&b[i][j][k]=='R'&&b[i][j][k]==b[i][j+1][k]&&b[i][j+1][k]==b[i][j+2][k]&&b[i][j+2][k]==b[i][j+3][k])
                    t++;
                if(k<3&&b[i][j][k]=='R'&&b[i][j][k]==b[i][j][k+1]&&b[i][j][k+1]==b[i][j][k+2]&&b[i][j][k+2]==b[i][j][k+3])
                    t++;
            }
    if(t==0)
        cout<<"lost";
    else
        cout<<t;
    return 0;
}