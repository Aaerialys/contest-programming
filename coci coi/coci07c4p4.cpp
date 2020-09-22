#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int t,n,br[501],mu[5001],pre[5001],tu[5001],ans[501],x;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>t>>n;
    fori(1,n+1)
        cin>>br[i];
    mu[0]=INT_MAX;
    fori(1,n+1)
    {
        for(int j=t;j>=br[i];j--)
        {
            if(mu[j-br[i]]&&!mu[j])
            {
                mu[j]=i;
                pre[j]=j-br[i];
                x=max(x,j);
            }
        }
    }
    while(x!=0)
    {
        ans[mu[x]]=pre[x]+1;
        x=pre[x];
    }
    x=1;
    fori(1,n+1)
    {
        if(ans[i]==0)
        {
            ans[i]=x;
            x+=br[i];
        }
        cout<<ans[i]-1<<" ";
    }
    cout<<endl;
    return 0;
}