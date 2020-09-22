#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    string a,b,c;
    bool free;
    cin>>n;
    fori(0,n)
    {
        cin>>a>>b>>c;
        free=true;
        m=min(a.size(),b.size());
        if(a.substr(0,m)==b.substr(0,m))
            free=false;
        if(a.substr(a.size()-m,m)==b.substr(b.size()-m,m))
            free=false;
        m=min(a.size(),c.size());
        if(a.substr(0,m)==c.substr(0,m))
            free=false;
        if(a.substr(a.size()-m,m)==c.substr(c.size()-m,m))
            free=false;
        m=min(b.size(),c.size());
        if(b.substr(0,m)==c.substr(0,m))
            free=false;
        if(b.substr(b.size()-m,m)==c.substr(c.size()-m,m))
            free=false;
        if(free)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}