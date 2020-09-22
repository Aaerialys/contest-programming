#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string g;
    cin>>g;
    int q,a,b,n=g.length();
    int in[g.length()+1];
    in[0]=0;
    for(int i=0;i<n;i++)
    {
        in[i+1]=in[i];
        if(g[i]=='G')
        {
            in[i+1]++;
        }
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        cout<<in[b+1]-in[a]<<"\n";
    }
    return 0;
}