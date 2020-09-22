#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
vector<int> recipe[350000];
int steal[350000];
int have[350000];

int least(int x)
{
    if(steal[x]!=INT_MAX)
        return steal[x];
    int y=recipe[x].size();
    fori(0,y)
    {
        steal[x]=min(steal[x],least(recipe[x][i]));
    }
    if(y==0)
        steal[x]=0;
    steal[x]+=have[x];
    return steal[x];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    fori(0,m)
    {
        cin>>a>>b;
        a--;
        fori(0,b)
        {
            cin>>c;
            c--;
            recipe[a].push_back(c);
        }
    }
    fori(0,n)
    {
        cin>>have[i];
        steal[i]=INT_MAX;
    }
    cout<<least(0);
    return 0;
}