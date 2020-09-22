#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

char yard[400][100];
char mov[30000];
int r,c,m;

bool ka(int x,int y,int z)
{
    if(x<0||x>=r||y<0||y>=c||yard[x][y]=='X')
        return false;
    fori(0,m)
    {
        z=(z+4)%4;
        if(mov[i]=='R')
            z++;
        if(mov[i]=='L')
            z--;
        if(mov[i]=='F')
        {
            if(z==0)
                y--;
            if(z==1)
                x++;
            if(z==2)
                y++;
            if(z==3)
                x--;
        }
        if(x<0||x>=r||y<0||y>=c||yard[x][y]=='X')
            return false;
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c;
    fori(0,r)
    {
        forj(0,c)
        {
            cin>>yard[i][j];
        }
    }
    cin>>m;
    fori(0,m)
        cin>>mov[m-i-1];
    fori(0,r)
    {
        forj(0,c)
        {
            if(ka(i,j,0)||ka(i,j,1)||ka(i,j,2)||ka(i,j,3))
                yard[i][j]='*';
            cout<<yard[i][j];
        }
        cout<<"\n";
    }
    return 0;
}