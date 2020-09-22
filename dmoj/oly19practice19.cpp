#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,k,t,arr[1000100],l[1000100],r[1000100];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(0,1000100)
        l[i]=n+10;
    l[0]=r[0]=0;
    fori(1,n+1)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
        arr[i]%=k;
        l[arr[i]]=min(l[arr[i]],i);
        r[arr[i]]=max(l[arr[i]],i);
    }
    fori(0,k)
        t=max(t,r[i]-l[i]);
    if(t==0)
        cout<<-1;
    else
        cout<<t;
    return 0;
}