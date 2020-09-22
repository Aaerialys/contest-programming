#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,t,m[101],c[11];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fork(0,5)
    {
        cin>>t>>n;
        fori(0,n)
            cin>>c[i];
        fori(1,t+1)
        {
            m[i]=INT_MAX/2;
            forj(0,n)
                if(i>=c[j])
                    m[i]=min(m[i],m[i-c[j]]+1);
        }
        cout<<m[t]<<endl;
    }
    return 0;
}