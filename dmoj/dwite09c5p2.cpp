#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int prime[27]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
    int n,x;
    fori(0,5)
    {
        cin>>n;
        x=lower_bound(prime,prime+25,n)-prime;
        if(prime[x]==n)
        {
            if(prime[x+2]-n<=n-prime[x-2])
                cout<<prime[x+2]<<"\n";
            else
                cout<<prime[x-2]<<"\n";
        }
        else
        {
            if(prime[x+1]-n<=n-prime[x-2])
                cout<<prime[x+1]<<"\n";
            else
                cout<<prime[x-2]<<"\n";
        }
    }
    return 0;
}