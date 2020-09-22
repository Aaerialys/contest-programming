#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    std::cout.precision(9);
    int n,r,a,b;
    cin>>n>>r;
    vector<int> in[n];
    int out[n]={0};
    double pos[n]={0.0};
    for(int i=0;i<r;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        in[b].push_back(a);
        out[a]++;
    }
    pos[0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<in[i].size();j++)
        {
            pos[i]+=pos[in[i][j]]/out[in[i][j]];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(out[i]==0)
            cout<<pos[i]<<"\n";
    }
    return 0;
}