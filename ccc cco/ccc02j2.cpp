#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int a,b,c,d;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    while(s!="quit!")
    {
        if(s.size()>3&&s.substr(s.size()-2,2)=="or"&&s[s.size()-3]!='a'&&s[s.size()-3]!='e'&&s[s.size()-3]!='i'&&s[s.size()-3]!='o'&&s[s.size()-3]!='u'&&s[s.size()-3]!='y')
            s=s.substr(0,s.size()-2)+"our";
        cout<<s<<"\n";
        cin>>s;
    }
    return 0;
}