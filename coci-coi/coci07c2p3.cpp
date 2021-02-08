#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c,x;
    string down[20],accr[20],m="zzzzzzzzzzzzzzzzzzzzzzzzz";
    char ch;
    cin>>r>>c;
    fori(0,20)
        down[i]=accr[i]="####################";
    fori(0,r)
        forj(0,c)
        {
            cin>>ch;
            accr[i][j]=down[j][i]=ch;
        }
    fori(0,r)
    {
        x=0;
        forj(0,c+1)
        {
            if(accr[i][j]=='#'&&j>x+1)
            {
                m=min(m,accr[i].substr(x,j-x));
            }
            if(accr[i][j]=='#')
                x=j+1;
        }
    }
    fori(0,c)
    {
        x=0;
        forj(0,r+1)
        {
            if(down[i][j]=='#'&&j>x+1)
            {
                m=min(m,down[i].substr(x,j-x));
            }
            if(down[i][j]=='#')
                x=j+1;
        }
    }
    cout<<m;
    return 0;
}