#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int r,c,x,y,n;
    char a;
    cin>>r>>c;
    bool field[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            field[i][j]=false;
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a;
            if(a=='X')
            {
                for(int k=0;k<r;k++)
                {
                    field[k][j]=true;
                }
                for(int k=0;k<c;k++)
                {
                    field[i][k]=true;
                }
            }
        }
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>y>>x;
        x--;
        y--;
        if(field[x][y])
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    return 0;
}