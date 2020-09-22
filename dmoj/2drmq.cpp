#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define foru(i,a,b) for(int i=a;i<b;i++)
#define clz __builtin_clz
using namespace std;

const int N=1001,L=10;
int n,lg,st[L][N][L][N],x,y,p[L]={1,2,4,8,16,32,64,128,256,512};

void init(vector<vector<int>>arr)
{
    n=arr.size();
    fork(0,n)
    {
        forj(0,n)
            st[0][k][0][j]=arr[k][j];
        fori(1,L)
            forj(0,n-p[i]+1)
                st[0][k][i][j]=min(st[0][k][i-1][j],st[0][k][i-1][j+p[i-1]]);
    }
            fori(1,L)
                forj(0,n-p[i]+1)
    fork(0,L)
        foru(l,0,n-p[k]+1)
                    st[i][j][k][l]=min(st[i-1][j][k][l],st[i-1][j+(1<<i-1)][k][l]);
}
int query(int a,int b,int c,int d)
{
    x=31-clz(b-a+1); y=31-clz(d-c+1);
    return min(min(st[x][a][y][c],st[x][a][y][d-(1<<y)+1]),min(st[x][b-(1<<x)+1][y][c],st[x][b-(1<<x)+1][y][d-(1<<y)+1]));
}