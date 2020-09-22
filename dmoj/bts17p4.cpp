#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int l,r=1e6,mid,ans=INT_MAX,n,m,j,x,y,mud[100010];

bool pos(int t)
{
    x=0;
    fori(1,n+2)
    {
        if(i-x>j)
            return false;
        if(mud[i]<=t)
            x=i;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,100010)
        mud[i]=INT_MAX;
    cin>>n>>m>>j;
    fori(0,m)
    {
        cin>>x>>y;
        mud[x]=y;
    }
    while(l<r)
    {
        mid=(l+r)/2;
        if(pos(mid))
        {
            ans=min(ans,mid);
            r=mid;
        }
        else
            l=mid+1;
    }
    if(ans==INT_MAX)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}