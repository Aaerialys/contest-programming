#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x,l=INT_MAX,r=0;
    cin>>n;
    fori(0,n)
    {
        forj(0,n)
        {
            cin>>x;
            if(x!=i*n+j+1)
            {
                l=min(l,j);
                r=max(r,j);
            }
        }
    }
    cout<<r-l+1<<endl;
    return 0;
}