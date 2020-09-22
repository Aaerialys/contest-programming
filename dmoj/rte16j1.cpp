#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

string s;
int l,c,m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    getline(cin,s);
    fori(0,s.size())
    {
        if(s[i]=='L')
        {
            l++;
            c++;
        }
        if(s[i]!='L'&&s[i]!=' ')
        {
            m=max(c,m);
            c=0;
        }
    }
    m=max(c,m);
    cout<<l<<" "<<m;
    return 0;
}