#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int x=0;
    bool b=true;
    fori(0,s.size())
    {
        if(s[i]=='(')
            x++;
        if(s[i]==')')
            x--;
        if(x<0)
        {
            if(b)
            {
                b=false;
                x+=2;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    if(b&&x==2)
    {
        cout<<"YES";
        return 0;
    }
    if(x==0)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}