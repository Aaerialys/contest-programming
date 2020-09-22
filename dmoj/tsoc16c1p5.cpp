#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,q,x,y,z,k,fact[20];
    fact[1]=1;
    fori(2,20)
        fact[i]=fact[i-1]*i;
    cin>>n>>q;
    fori(0,q)
    {
        bool viz[20]={false};
        cin>>x;
        forj(0,n-1)
        {
            z=0;
            y=x/fact[n-j-1]+1;
            for(k=0;z<y;k++)
                if(!viz[k])
                    z++;
            viz[k-1]=true;
            cout<<k<<" ";
            x=x%fact[n-j-1];
        }
        forj(0,n)
            if(!viz[j])
                cout<<j+1;
        cout<<"\n";
    }
    return 0;
}