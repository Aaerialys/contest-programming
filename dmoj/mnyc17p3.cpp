#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long x,y,M=1e9+7,m,p=1;
string s,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s>>t;
    fori(0,min(s.size(),t.size())+1)
    {
        if(x==y)
        {
            m=i;
        }
        x=(x+(s[s.size()-i-1]-'A')*p)%M; p=p*26%M;
        y=(y*26+t[i]-'A')%M;
    }
    cout<<s.substr(0,s.size()-m)<<t<<endl;
    return 0;
}