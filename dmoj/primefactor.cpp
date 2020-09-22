#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x; y=x;
        for(int j=2;x>1;j++)
        {
            while(x%j==0)
            {
                cout<<j<<" ";
                x/=j;
            }
            if(x>1&&j>sqrt(x)+2)
            {
                cout<<x;
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}