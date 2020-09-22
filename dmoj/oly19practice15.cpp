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
    getline(cin,str);
    fori(1,str.size())
    {
        if(!(str[i]=='I'&&str[i-1]==' '&&(str[i+1]==' '||str[i+1]=='.'))&&(i<2||str[i-2]!='.'))
            str[i]=tolower(str[i]);
    }
    cout<<str;
    return 0;
}