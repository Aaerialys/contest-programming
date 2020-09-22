#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

bool b,f,t,l,c;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    fori(0,s.size())
    {
        if(s[i]=='B')
            b=true;
        if(s[i]=='T')
            t=true;
        if(s[i]=='F')
            f=true;
        if(s[i]=='L')
            l=true;
        if(s[i]=='C')
            c=true;
    }
    if(!b)
        cout<<'B';
    if(!t)
        cout<<'T';
    if(!f)
        cout<<'F';
    if(!l)
        cout<<'L';
    if(!c)
        cout<<'C';
    if(b&&t&&f&&l&&c)
        cout<<"NO MISSING PARTS";
    return 0;
}