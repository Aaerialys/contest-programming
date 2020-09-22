#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int ans(string s)
{
    int a,b,x=3,y,t;
    char ch=s[0];
    if(s[2]=='(')
    {
        t=1;
        while(t>0)
        {
            if(s[x]==')')
                t--;
            if(s[x]=='(')
                t++;
            x++;
        }
        a=ans(s.substr(3,x-4));
    }
    else
        a=s[2]-'0';
    y=x+2;
    if(s[y-1]=='(')
    {
        t=1;
        while(t>0)
        {
            if(s[y]==')')
                t--;
            if(s[y]=='(')
                t++;
            y++;
        }
        b=ans(s.substr(x+2,y-x-3));
    }
    else
        b=s[x+1]-'0';
    if(ch=='+')
        return a+b;
    if(ch=='-')
        return a-b;
    if(ch=='*')
        return a*b;
    if(ch=='q')
        return a/b;
    if(ch=='r')
        return a%b;
}

int main()
{
    string str;
    fori(0,10)
    {
        getline(cin,str);
        cout<<ans(str.substr(1,str.size()-2))<<"\n";
    }
    return 0;
}