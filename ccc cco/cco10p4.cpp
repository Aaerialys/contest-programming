#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int best[6][3001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t,n,bgt,a,b,c;
    vector<int> price[6];
    vector<int> value[6];
    cin>>t>>n;
    fori(0,n)
    {
        cin>>a>>b>>c;
        price[c].push_back(a);
        value[c].push_back(b);
    }
    cin>>bgt;
    fori(1,t+1)
    {
        forj(1,bgt+1)
        {
            fork(0,price[i].size())
            {
                if(j>=price[i][k])
                    best[i][j]=max(best[i][j],best[i-1][j-price[i][k]]+value[i][k]);
            }
        }
    }
    cout<<best[t][bgt]<<endl;
    return 0;
}