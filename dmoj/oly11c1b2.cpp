#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int convert2(string s)
{
    int t=0;
    fori(0,s.size())
    {
        t*=2;
        t+=s[i]-'0';
    }
    return t;
}
int convert3(string s)
{
    int t=0;
    fori(0,s.size())
    {
        t*=3;
        t+=s[i]-'0';
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a,b;
    unordered_set<int> numb;
    cin>>a>>b;
    fori(0,a.size())
    {
        a[i]=(char)((1-a[i]+'0')+'0');
        numb.insert(convert2(a));
        a[i]=(char)((1-a[i]+'0')+'0');
    }
    fori(0,b.size())
    {
        b[i]=(char)((b[i]-'0'+1)%3+'0');
        if(numb.find(convert3(b))!=numb.end())
        {
            cout<<convert3(b);
            return 0;
        }
        b[i]=(char)((b[i]-'0'+1)%3+'0');
        if(numb.find(convert3(b))!=numb.end())
        {
            cout<<convert3(b);
            return 0;
        }
        b[i]=(char)((b[i]-'0'+1)%3+'0');
    }
    return 0;
}