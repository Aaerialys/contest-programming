#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,n;
    cin>>n>>a;
    fori(1,n)
    {
        cin>>b;
        if(b>=a)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}