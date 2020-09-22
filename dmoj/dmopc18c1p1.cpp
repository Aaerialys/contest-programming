#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x=-1,z0=INT_MAX,z1=INT_MAX;
    cin>>n;
    n+=2;
    int numb[n];
    numb[0]=-1;
    numb[n-1]=INT_MAX;
    fori(1,n-1)
    {
        cin>>numb[i];
        if(numb[i]>0)
        {
            if(numb[i]<x)
            {
                cout<<"NO";
                return 0;
            }
            x=numb[i];
        }
    }
    fori(1,n-1)
    {
        if(numb[i]==0)
        {
            if(z0==INT_MAX)
                z0=i;
            z1=i;
            for(int j=i+1;j<n&&numb[j]==0;j++)
                x=numb[j+1];
            for(int j=i+1;j<n&&numb[j]==0;j++)
                numb[j]=x;
        }
    }
    if(z0<n&&z1<n&&numb[z0+1]<numb[z1-1])
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}