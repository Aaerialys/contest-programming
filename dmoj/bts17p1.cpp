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
    fori(2,str.size())
        if(str[i]>='A'&&str[i]<='Z'&&str[i-1]==' ')
        {
            str=str.substr(0,i-1)+"."+str.substr(i-1,str.size()-i+1);
            i++;
        }
    str+=".";
    cout<<str;
    return 0;
}