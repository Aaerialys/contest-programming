#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str,a,b;
    getline(cin,str);
    fori(0,str.size())
        if(str[i]==',')
        {
            a=str.substr(i+2,str.size()-i-3);
            b=str.substr(0,i);
        }
    if(a==""&&b=="")
        cout<<"";
    else if(a=="")
    {
        b[0]=toupper(b[0]);
        cout<<b;
    }
    else if(b=="")
    {
        a[0]=toupper(a[0]);
        cout<<a;
    }
    else
    {
        a[0]=toupper(a[0]);
        b[0]=tolower(b[0]);
        cout<<a<<" "<<b;
    }
    cout<<str[str.size()-1];
    return 0;
}