#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int a,b,s,x,y;
vector<int> n,o;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    fori(0,s)
    {
        cin>>y>>b; a=y;
        fori(0,n.size())
            n[i]-=n[i]*b/100;
        fori(0,o.size())
            o[i]-=o[i]*b/100;
        fori(0,n.size())
        {
            x=min(a,251-n[i]);
            n[i]+=x;
            a-=x;
        }
        while(a>0)
        {
            n.push_back(min(a,251));
            a-=min(a,251);
        }
        a=y;
        fori(0,o.size())
        {
            x=min(a,132-o[i]);
            o[i]+=x;
            a-=x;
        }
        while(a>0)
        {
            o.push_back(min(a,132));
            a-=min(a,132);
        }
    }
    cout<<o.size()-n.size();
    return 0;
}