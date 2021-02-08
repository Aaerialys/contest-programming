#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
vector<int> gr[100000];
long long in[100000],out[100000],paths[100000],dist[100000];
long long V,E,a,b;

int main()
{
    cin>>V>>E;
    fori(0,E)
    {
        cin>>a>>b;
        a--;
        b--;
        gr[a].push_back(b);
        in[b]++;
        out[a]++;
    }
    fori(0,V)
    {
        if(in[i]==0)
            paths[i]=1;
        a=gr[i].size();
        paths[i]%=1000000007;
        dist[i]%=1000000007;
        forj(0,a)
        {
            paths[gr[i][j]]+=paths[i];
            dist[gr[i][j]]+=dist[i]+paths[i];
        }
    }
    a=0;
    fori(0,V)
    {
        if(out[i]==0)
            a+=dist[i];
    }
    cout<<a%1000000007;
    return 0;
}