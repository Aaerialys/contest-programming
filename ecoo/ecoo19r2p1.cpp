#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("DATA11.txt", "r", stdin);
    for(int xx=0;xx<10;xx++)
    {
        string s;
        set<string> u;
        cin>>n;
        fork(0,n)
        {
            cin>>s;
            fori(0,s.size())
                s[i]=tolower(s[i]);
            for(int i=0;i<s.size()&&s[i]!='@';i++)
                if(s[i]=='.')
                {
                    s=s.substr(0,i)+s.substr(i+1,s.size()-i-1);
                    i--;
                }
            fori(0,s.size())
                if(s[i]=='+')
                {
                    forj(i,s.size())
                        if(s[j]=='@')
                            s=s.substr(0,i)+s.substr(j,s.size()-j);
                    break;
                }
            u.insert(s);
        }
        cout<<u.size()<<endl;
    }
    return 0;
}
/*
3
foo@bar.com
fO.o+baz123@bAR.com
foo@bar..com
3
c++@foo.com
c...@foo.com
.c+c@foo.com
*/