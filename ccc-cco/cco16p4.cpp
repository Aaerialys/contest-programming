#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int type[600000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,g,a;
    char ch;
    cin>>n>>g;
    bool grid[g][n][n];
    fori(0,g)
    {
        forj(0,n)
        {
            fork(0,n)
            {
                cin>>ch;
                if(ch=='R')
                    grid[i][j][k]=1;
                if(ch=='W')
                    grid[i][j][k]=0;
            }
        }
    }
    fori(0,g)
    {
        forj(0,n-1)
        {
            fork(0,n-1)
            {
                if(grid[i][j][k]==1)
                {
                    grid[i][j][k]=!grid[i][j][k];
                    grid[i][j][k+1]=!grid[i][j][k+1];
                    grid[i][j+1][k]=!grid[i][j+1][k];
                    grid[i][j+1][k+1]=!grid[i][j+1][k+1];
                }
            }
        }
        a=0;
        forj(0,n-1)
        {
            a*=2;
            a+=grid[i][j][n-1];
            a*=2;
            a+=grid[i][n-1][j];
        }
        a*=2;
        a+=grid[i][n-1][n-1];
        type[a]++;
    }
    a=0;
    fori(0,600000)
    {
        a+=type[i]*(type[i]-1)/2;
    }
    cout<<a<<endl;
    return 0;
}