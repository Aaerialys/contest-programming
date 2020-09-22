#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

double n,m,x;
string s,in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>in>>x;
        if(x>m)
        {
            m=x;
            s=in;
        }
    }
    cout<<s;
    return 0;
}