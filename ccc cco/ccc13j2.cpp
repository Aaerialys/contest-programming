#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    fori(0,str.size())
        if(str[i]!='I'&&str[i]!='O'&&str[i]!='S'&&str[i]!='H'&&str[i]!='Z'&&str[i]!='X'&&str[i]!='N')
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
    return 0;
}