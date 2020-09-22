#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,a,b,c;
    getline(cin,s);
    fori(0,s.size())
    {
        if(s[i]=='A')
        {
            a+="o.";
            b+="..";
            c+="..";
        }
        if(s[i]=='B')
        {
            a+="o.";
            b+="o.";
            c+="..";
        }
        if(s[i]=='C')
        {
            a+="oo";
            b+="..";
            c+="..";
        }
        if(s[i]=='D')
        {
            a+="oo";
            b+=".o";
            c+="..";
        }
        if(s[i]=='E')
        {
            a+="o.";
            b+=".o";
            c+="..";
        }
        if(s[i]=='F')
        {
            a+="oo";
            b+="o.";
            c+="..";
        }
        if(s[i]=='G')
        {
            a+="oo";
            b+="oo";
            c+="..";
        }
        if(s[i]=='H')
        {
            a+="o.";
            b+="oo";
            c+="..";
        }
        if(s[i]=='I')
        {
            a+=".o";
            b+="o.";
            c+="..";
        }
        if(s[i]=='J')
        {
            a+=".o";
            b+="oo";
            c+="..";
        }
        if(s[i]=='K')
        {
            a+="o.";
            b+="..";
            c+="o.";
        }
        if(s[i]=='L')
        {
            a+="o.";
            b+="o.";
            c+="o.";
        }
        if(s[i]=='M')
        {
            a+="oo";
            b+="..";
            c+="o.";
        }
        if(s[i]=='N')
        {
            a+="oo";
            b+=".o";
            c+="o.";
        }
        if(s[i]=='O')
        {
            a+="o.";
            b+=".o";
            c+="o.";
        }
        if(s[i]=='P')
        {
            a+="oo";
            b+="o.";
            c+="o.";
        }
        if(s[i]=='Q')
        {
            a+="oo";
            b+="oo";
            c+="o.";
        }
        if(s[i]=='R')
        {
            a+="o.";
            b+="oo";
            c+="o.";
        }
        if(s[i]=='S')
        {
            a+=".o";
            b+="o.";
            c+="o.";
        }
        if(s[i]=='T')
        {
            a+=".o";
            b+="oo";
            c+="o.";
        }
        if(s[i]=='U')
        {
            a+="o.";
            b+="..";
            c+="oo";
        }
        if(s[i]=='V')
        {
            a+="o.";
            b+="o.";
            c+="oo";
        }
        if(s[i]=='W')
        {
            a+=".o";
            b+="oo";
            c+=".o";
        }
        if(s[i]=='X')
        {
            a+="oo";
            b+="..";
            c+="oo";
        }
        if(s[i]=='Y')
        {
            a+="oo";
            b+=".o";
            c+="oo";
        }
        if(s[i]=='Z')
        {
            a+="o.";
            b+=".o";
            c+="oo";
        }
        if(s[i]==' ')
        {
            a+="..";
            b+="..";
            c+="..";
        }
    }
    cout<<a<<"\n"<<b<<"\n"<<c;
    return 0;
}