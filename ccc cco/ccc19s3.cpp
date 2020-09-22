#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int grid[3][3],x=100000001;
string ch;

void fil()
{
    int b=0;
    while(b!=3)
    {
        b=0;
        fori(0,3)
        {
            if(grid[i][0]==x&&grid[i][1]!=x&&grid[i][2]!=x)
                grid[i][0]=grid[i][1]*2-grid[i][2];
            else if(grid[i][0]!=x&&grid[i][1]==x&&grid[i][2]!=x)
                grid[i][1]=(grid[i][0]+grid[i][2])/2;
            else if(grid[i][0]!=x&&grid[i][1]!=x&&grid[i][2]==x)
                grid[i][2]=grid[i][1]*2-grid[i][0];
            else if(grid[0][i]==x&&grid[1][i]!=x&&grid[2][i]!=x)
                grid[0][i]=grid[1][i]*2-grid[2][i];
            else if(grid[0][i]!=x&&grid[1][i]==x&&grid[2][i]!=x)
                grid[1][i]=(grid[0][i]+grid[2][i])/2;
            else if(grid[0][i]!=x&&grid[1][i]!=x&&grid[2][i]==x)
                grid[2][i]=grid[1][i]*2-grid[0][i];
            else
                b++;
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,3)
        forj(0,3)
        {
            cin>>ch;
            if(ch=="X")
                grid[i][j]=x;
            else
                grid[i][j]=stoi(ch);

        }
    fil();
    if(grid[1][1]==x)
        grid[1][1]=1;
    fil();
    if(grid[0][1]==x)
        grid[0][1]=0;
    fil();
    if(grid[2][1]==x)
        grid[2][1]=0;
    fil();
    if(grid[1][0]==x)
        grid[1][0]=0;
    fil();
    if(grid[1][2]==x)
        grid[1][2]=0;
    fil();
    if(grid[0][0]==x)
        grid[0][0]=1;
    fil();
    fori(0,3)
    {
        forj(0,3)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}