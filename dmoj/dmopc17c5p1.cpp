#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    fori(0,str.size())
    {
        if(str[i]=='0') str[i]='O';
        if(str[i]=='1') str[i]='l';
        if(str[i]=='3') str[i]='E';
        if(str[i]=='4') str[i]='A';
        if(str[i]=='5') str[i]='S';
        if(str[i]=='6') str[i]='G';
        if(str[i]=='8') str[i]='B';
        if(str[i]=='9') str[i]='g';
    }
    cout<<str;
    return 0;
}