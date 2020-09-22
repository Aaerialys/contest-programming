#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long d,m,o,j;

long long f(string s)
{
    fori(0,s.size())
    {
        if(s[i]=='l')
            d++;
        if(s[i]=='o')
            m+=d;
        if(s[i]=='v')
            o+=m;
        if(s[i]=='e')
            j+=o;
    }
    return j;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string in;
    cin>>in;
    cout<<f(in);
    return 0;
}