#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str,str0,str1;
    getline(cin,str);
    getline(cin,str0);
    getline(cin,str1);
    int code[257];
    fori(0,257)
    {
        code[i]='.';
    }
    fori(0,str.size())
    {
        code[str0[i]]=str[i];
    }
    fori(0,str1.size())
    {
        cout<<(char)code[str1[i]];
    }
    return 0;
}