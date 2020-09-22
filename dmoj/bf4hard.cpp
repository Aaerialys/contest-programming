#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long M=1e9+7,k,ss,x;
string s,in;

long long fpow(long long a,long long b)
{
    if(b==0)
        return 1;
    long long t=fpow(a,b/2);
    if(b&1)
        return t*t%M*a%M;
    return t*t%M;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s>>in; x=fpow(26,(int)in.size());
    fori(0,in.size())
    {
        k=(k*26+in[i]-'a')%M;
        ss=(ss*26+s[i]-'a')%M;
    }
    fori(0,s.size()-in.size()+1)
    {
        if(k==ss)
        {
            cout<<i;
            return 0;
        }
        ss=(ss*26+s[i+in.size()]-'a'-x*(s[i]-'a')+M*100)%M;
    }
    cout<<-1;
    return 0;
}
