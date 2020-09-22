#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,m,numb[100001],s,t=0;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fori(0,n)
    {
        cin>>numb[i];
    }
    sort(numb,numb+n);
    fori(0,n)
    {
        s=upper_bound(numb,numb+n,m-numb[i])-numb-1;
        if(s!=i&&s>=0)
            t=max(t,numb[i]+numb[s]);
    }
    cout<<t<<endl;
    return 0;
}