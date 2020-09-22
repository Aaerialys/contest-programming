#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

string s;
long long l,k,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s>>k; s+=".";
    fori(0,s.size())
    {
        if(s[i]!=s[l])
        {
            t+=max(0LL,i-l-k+1);
            l=i;
        }
    }
    cout<<t;
    return 0;
}