#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int x,y,a,b;
int des[1001][1001];
int best[1001][1001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>x>>y;
    fori(0,y)
    {
        forj(0,x)
        {
            cin>>des[j][i];
            best[j][i]=INT_MAX/2;
        }
    }
    best[0][0]=des[0][0];
    cin>>a>>b;
    queue<int> vx;
    queue<int> vy;
    int v1,v2;
    vx.push(0);
    vy.push(0);
    while(!vx.empty())
    {
        v1=vx.front();
        v2=vy.front();
        vx.pop();
        vy.pop();
        if(v1>0&&best[v1][v2]+des[v1-1][v2]<best[v1-1][v2])
        {
            best[v1-1][v2]=best[v1][v2]+des[v1-1][v2];
            vx.push(v1-1);
            vy.push(v2);
        }
        if(v1<x&&best[v1][v2]+des[v1+1][v2]<best[v1+1][v2])
        {
            best[v1+1][v2]=best[v1][v2]+des[v1+1][v2];
            vx.push(v1+1);
            vy.push(v2);
        }
        if(v2<y&&best[v1][v2]+des[v1][v2+1]<best[v1][v2+1])
        {
            best[v1][v2+1]=best[v1][v2]+des[v1][v2+1];
            vx.push(v1);
            vy.push(v2+1);
        }
    }
    cout<<best[a][b];
    return 0;
}