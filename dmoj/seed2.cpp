#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int l,r=2e9,m,ans;
string s;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(l!=r)
    {
        m=l+(r-l)/2;
        cout<<m<<endl;
        cin>>s;
        if(s=="FLOATS")
            r=m;
        if(s=="SINKS")
            l=m+1;
        if(s=="OK")
            return 0;
    }
    return 0;
}