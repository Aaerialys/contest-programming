#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    long long n,m,k,a,b;
    cin>>n>>m>>k;
    long long pot[n+1]={0};
    pot[1]=m;
    fori(0,m)
    {
        cin>>a>>b;
        pot[a]--;
        if(b<n)
            pot[b+1]++;
    }
    fori(1,n+1)
        pot[i]+=pot[i-1];
    fori(1,n+1)
        pot[i]+=pot[i-1];
    a=b=0;
    m=LLONG_MAX;
    while(a<=n)
    {
        if(pot[a]-pot[b]<k)
            a++;
        else if(pot[a]-pot[b]>=k)
        {
            m=min(m,a-b);
            b++;
        }
    }
    if(m==LLONG_MAX)
        cout<<-1<<endl;
    else
        cout<<m<<endl;
    return 0;
}