#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,t;
bool prime[2000000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(2,2000000)
    {
        if(!prime[i])
            for(int j=i*2;j<2000000;j+=i)
                prime[j]=true;
    }
    cin>>t;
    forj(0,t)
    {
        cin>>n;
        fori(2,n)
            if((!prime[i])&&(!prime[2*n-i]))
            {
                cout<<i<<" "<<2*n-i<<"\n";
                break;
            }
    }
    return 0;
}