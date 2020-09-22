#include <bits/stdc++.h>

using namespace std;

int main()
{
    int V,a,b;
    cin>>V;
    vector<int> gr[V];
    int paths[V]={0};
    paths[0]=1;
    cin>>a>>b;
    while(a!=0||b!=0)
    {
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
        cin>>a>>b;
    }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<gr[i].size();j++)
        {
            if(gr[i][j]<i)
            {
                paths[i]+=paths[gr[i][j]];
            }
        }
    }
    cout<<paths[V-1];
    return 0;
}