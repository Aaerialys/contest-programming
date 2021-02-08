#include <bits/stdc++.h>

using namespace std;

int V,m,numb=0;
vector<int> gr[20];

int dfsR(int v,bool pizza[20])/*directional unweighted graph using adj matrix*/
{
    bool npizza[20];
    for(int i=0;i<20;i++)
    {
        npizza[i]=pizza[i];
    }
    if(v==V)
    {
        numb++;
        return 0;
    }
    pizza[v]=false;
    dfsR(v+1,npizza);
    for(int i=0;i<gr[v].size();i++)
    {
        if(npizza[gr[v][i]]==true)
        {
            return 0;
        }
    }
    npizza[v]=true;
    dfsR(v+1,npizza);
    return 0;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>V>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    bool pizza[20]={false};
    dfsR(0,pizza);
    cout<<numb;
    return 0;
}