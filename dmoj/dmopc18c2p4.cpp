#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long m,n,l,r,q=INT_MAX,numb[500001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fori(1,n+1)
    {
        cin>>numb[i];
        numb[i]+=numb[i-1];
    }
    while(r<=n)
    {
        if(numb[r]-numb[l]>=m)
        {
            q=min(q,r-l);
            l++;
        }
        else
            r++;
    }
    if(q==INT_MAX)
        cout<<-1;
    else
        cout<<q;
    return 0;
}