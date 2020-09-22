#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,q,a,b,c,choc[1000010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    fori(0,q)
    {
        cin>>a>>b>>c;
        choc[a]+=c;
        choc[b+1]-=c;
    }
    fori(1,n+1)
        choc[i]+=choc[i-1];
    fori(1,n+1)
        choc[i]+=choc[i-1];
    cin>>q;
    a=b=0;
    fori(1,n+1)
    {
        while(choc[i]-choc[a]>q)
            a++;
        b=max(b,i-a);
    }
    cout<<b<<endl;
    return 0;
}