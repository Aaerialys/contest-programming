#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x,y; x=y=0;
    string s;
    cin>>s;
    fori(0,s.size())
    {
        x=(x<<4);
        if(s[i]>='0'&&s[i]<='9')
            x+=s[i]-'0';
        if(s[i]>='A'&&s[i]<='F')
            x+=s[i]-'A'+10;
        if(s[i]>='a'&&s[i]<='f')
            x+=s[i]-'a'+10;
    }
    cin>>s;
    fori(0,s.size())
    {
        y=(y<<4);
        if(s[i]>='0'&&s[i]<='9')
            y+=s[i]-'0';
        if(s[i]>='A'&&s[i]<='F')
            y+=s[i]-'A'+10;
        if(s[i]>='a'&&s[i]<='f')
            y+=s[i]-'a'+10;
    }
    if(x+y>1061109567)
        cout<<"Yes";
    else
        cout<<"No";
}