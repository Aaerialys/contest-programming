#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int R,C,x,in[4000010];
char lot[2001][2001];
vector<int> gr[4000010];
queue<int> toV;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    fori(0,R)
        forj(0,C)
        {
            cin>>lot[i][j];
            if(lot[i][j]=='.')
                in[i*C+j]=INT_MAX/2;
        }
    fori(0,R)
    {
        x=0;
        forj(0,C)
            if(lot[i][j]=='W')
            {
                fork(x,j)
                {
                    if(lot[i][k]!='.')
                    {
                        gr[i*C+k].push_back(i*C+j);
                        in[i*C+j]++;
                    }
                }
                x=j;
            }
    }
    fori(0,R)
    {
        x=C-1;
        for(int j=C-1;j>=0;j--)
            if(lot[i][j]=='E')
            {
                for(int k=x;k>j;k--)
                {
                    if(lot[i][k]!='.')
                    {
                        gr[i*C+k].push_back(i*C+j);
                        in[i*C+j]++;
                    }
                }
                x=j;
            }
    }
    fori(0,C)
    {
        x=0;
        forj(0,R)
            if(lot[j][i]=='N')
            {
                fork(x,j)
                {
                    if(lot[k][i]!='.')
                    {
                        gr[k*C+i].push_back(j*C+i);
                        in[j*C+i]++;
                    }
                }
                x=j;
            }
    }
    fori(0,C)
    {
        x=R-1;
        for(int j=R-1;j>=0;j--)
            if(lot[j][i]=='S')
            {
                for(int k=x;k>j;k--)
                {
                    if(lot[k][i]!='.')
                    {
                        gr[k*C+i].push_back(j*C+i);
                        in[j*C+i]++;
                    }
                }
                x=j;
            }
    }
    fori(0,R*C)
        if(in[i]==0)
            toV.push(i);
    while(!toV.empty())
    {
        x=toV.front(); toV.pop();
        cout<<"("<<x/C<<","<<x%C<<")\n";
        fori(0,gr[x].size())
        {
            in[gr[x][i]]--;
            if(in[gr[x][i]]==0)
                toV.push(gr[x][i]);
        }
    }
    return 0;
}
/**
topological
*/