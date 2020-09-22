#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,a,b;
    bool yes;
    cin>>n>>m>>k;
    int talk[m];
    vector<int> g1[n];
    fori(0,k)
    {
        cin>>a>>b;
        a--;
        b--;
        g1[a].push_back(b);
    }
    fori(0,n)
    {
        forj(i+1,n)
        {
            forj(0,m)
                talk[j]=0;
            forj(0,g1[i].size())
                talk[g1[i][j]]++;
            yes=false;
            fork(0,g1[j].size())
            {
                talk[g1[j][k]]++;
                if(talk[g1[j][k]]==2&&yes)
                {
                    cout<<"NO";
                    return 0;
                }
                if(talk[g1[j][k]]==2)
                {
                    yes=true;
                }
            }
        }
    }
    cout<<"YES";
    return 0;
}