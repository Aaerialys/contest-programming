#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,k,x,y,mx[3010][3010];
long long ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(0,n)
        forj(0,i+1)
            cin>>mx[i][j];
    if(n==1)
    {
        cout<<mx[0][0];
        return 0;
    }
    x=1;y=2;
    while(y<=k)
    {
        fori(0,n-y+1)
            forj(0,i+1)
                mx[i][j]=max(mx[i][j],max(mx[i+y-x][j],mx[i+y-x][j+y-x]));
        x=y;
        y=floor(x*1.5);
    }
    fori(0,n-k+1)
        forj(0,i+1)
            ans+=max(mx[i][j],max(mx[i+k-x][j],mx[i+k-x][j+k-x]));
    cout<<ans;
    return 0;
}