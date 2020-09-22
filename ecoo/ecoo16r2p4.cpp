#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int M=220;
int w,h,x1,x2,x3,x4,x5,x6,Y1,y2,y3,y4,y5,y6,pos[M][M];
char mp[M][M];

void hop(int x,int y)
{
    if(pos[x][y]==1)
        return;
    pos[x][y]=1;
    if(mp[x][y]=='.'&&mp[x][y+1]=='.')
        return hop(x,y+1);
    if(mp[x+1][y]!='=')
        hop(x+1,y);
    if(mp[x-1][y]!='=')
        hop(x-1,y);
    if(mp[x][y]=='#'&&mp[x][y-1]!='=')
        hop(x,y-1);
    if(mp[x][y+1]=='#')//!='='
        hop(x,y+1);
    if(mp[x][y-1]!='=')
    {
        hop(x,y-1);
        if(mp[x+1][y-1]!='=')
            hop(x+1,y-1);
        if(mp[x-1][y-1]!='=')
            hop(x-1,y-1);
    }
}

void skip(int x,int y)
{
    if(pos[x][y]==1)
        return;
    pos[x][y]=1;
    if(mp[x][y]=='.'&&mp[x][y+1]=='.')
        return skip(x,y+1);
    if(mp[x+1][y]!='=')
        skip(x+1,y);
    if(mp[x-1][y]!='=')
        skip(x-1,y);
    if(mp[x][y]=='#'&&mp[x][y-1]!='=')
        skip(x,y-1);
    if(mp[x][y+1]=='#')
        skip(x,y+1);
    if(mp[x-1][y]!='='&&mp[x-2][y]!='=')
        skip(x-2,y);
    if(mp[x+1][y]!='='&&mp[x+2][y]!='=')
        skip(x+2,y);
}

void jump(int x,int y)
{
    if(pos[x][y]==1)
        return;
    pos[x][y]=1;
    if(mp[x][y]=='.'&&mp[x][y+1]=='.')
        return jump(x,y+1);
    if(mp[x+1][y]!='=')
        jump(x+1,y);
    if(mp[x-1][y]!='=')
        jump(x-1,y);
    if(mp[x][y]=='#'&&mp[x][y-1]!='=')
        jump(x,y-1);
    if(mp[x][y+1]=='#')
        jump(x,y+1);
    if(mp[x][y-1]!='=')
    {
        jump(x,y-1);
        if(mp[x][y-2]!='=')
            jump(x,y-2);
        if(mp[x+1][y-1]!='=')
            jump(x+1,y-1);
        if(mp[x-1][y-1]!='=')
            jump(x-1,y-1);
        if(mp[x+1][y-1]!='='&&mp[x+1][y]!='='&&mp[x+2][y-1]!='=')
            jump(x+2,y-1);
        if(mp[x-1][y-1]!='='&&mp[x-1][y]!='='&&mp[x-2][y-1]!='=')
            jump(x-2,y-1);
    }
    if(mp[x-1][y]!='='&&mp[x-2][y]!='=')
        jump(x-2,y);
    if(mp[x+1][y]!='='&&mp[x+2][y]!='=')
        jump(x+2,y);
    if(mp[x-1][y]!='='&&mp[x-2][y]!='='&&mp[x-3][y]!='=')
        jump(x-3,y);
    if(mp[x+1][y]!='='&&mp[x+2][y]!='='&&mp[x+3][y]!='=')
        jump(x+3,y);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fork(0,10)
    {
        cin>>w>>h;
        fori(0,M)
            forj(0,M)
                mp[i][j]='.';
        fori(0,M)
            mp[0][i]=mp[i][0]=mp[i][M-1]=mp[M-1][i]='=';
        forj(3,h+3)
            fori(3,w+3)
            {
                cin>>mp[i][j];
                if(mp[i][j]=='h')
                {
                    x1=i;
                    Y1=j;
                    mp[i][j]='.';
                }
                if(mp[i][j]=='s')
                {
                    x2=i;
                    y2=j;
                    mp[i][j]='.';
                }
                if(mp[i][j]=='j')
                {
                    x3=i;
                    y3=j;
                    mp[i][j]='.';
                }
                if(mp[i][j]=='C')
                {
                    x4=i;
                    y4=j;
                    mp[i][j]='.';
                }
                if(mp[i][j]=='F')
                {
                    x5=i;
                    y5=j;
                    mp[i][j]='.';
                }
                if(mp[i][j]=='T')
                {
                    x6=i;
                    y6=j;
                    mp[i][j]='.';
                }
            }
        cout<<"\nHOP ";
        fori(0,M)
            forj(0,M)
                pos[i][j]=0;
        hop(x1,Y1);
        if(pos[x4][y4]==1)
            cout<<"C";
        if(pos[x5][y5]==1)
            cout<<"F";
        if(pos[x6][y6]==1)
            cout<<"T";
        cout<<"\nSKIP ";
        fori(0,M)
            forj(0,M)
                pos[i][j]=0;
        skip(x2,y2);
        if(pos[x4][y4]==1)
            cout<<"C";
        if(pos[x5][y5]==1)
            cout<<"F";
        if(pos[x6][y6]==1)
            cout<<"T";
        cout<<"\nJUMP ";
        fori(0,M)
            forj(0,M)
                pos[i][j]=0;
        jump(x3,y3);
        if(pos[x4][y4]==1)
            cout<<"C";
        if(pos[x5][y5]==1)
            cout<<"F";
        if(pos[x6][y6]==1)
            cout<<"T";
        cout<<endl;
    }
    return 0;
}