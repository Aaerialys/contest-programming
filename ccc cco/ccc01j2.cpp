#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    fori(1,101)
    {
        if(a*i%b==1)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<"No such integer exists.";
    return 0;
}