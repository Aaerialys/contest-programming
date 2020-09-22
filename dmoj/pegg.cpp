#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long t,n,k,x,mf[34][34];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(1,34)
    {
        forj(1,34)
        {
            mf[i][j]=mf[i-1][j-1]+mf[i][j-1]+1;
        }
    }
    cin>>t;
    fori(0,t)
    {
        cin>>n>>k;
        x=lower_bound(mf[k],mf[k]+34,n)-mf[k];
        if(x>32)
            cout<<"Impossible\n";
        else
            cout<<x<<"\n";
    }
    return 0;
}