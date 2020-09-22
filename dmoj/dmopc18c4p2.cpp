#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int t,n,br[701],mu[250000],x,sum;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(1,n+1)
    {
        cin>>br[i];
        sum+=br[i];
    }
    t=sum/2;
    mu[0]=INT_MAX;
    fori(1,n+1)
    {
        for(int j=t;j>=br[i];j--)
        {
            if(mu[j-br[i]]&&!mu[j])
            {
                mu[j]=i;
                x=max(x,j);
            }
        }
    }
    cout<<sum-2*x;
    return 0;
}