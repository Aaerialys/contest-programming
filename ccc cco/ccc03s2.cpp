#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

string last(string str)
{
    int x=str.size();
    fori(1,x+1)
    {
        str[x-i]=tolower(str[x-i]);
        if(str[x-i]=='a'||str[x-i]=='e'||str[x-i]=='i'||str[x-i]=='o'||str[x-i]=='u')
            return str.substr(x-i,i);
        if(str[x-i]==' ')
            return str.substr(x-i+1,i-1);
    }
    return str;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    string str1,str2,str3,str4;
    cin>>n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    fori(0,n)
    {
        getline(cin,str1);
        getline(cin,str2);
        getline(cin,str3);
        getline(cin,str4);
        str1=last(str1);
        str2=last(str2);
        str3=last(str3);
        str4=last(str4);
        if(str1==str2&&str2==str3&&str3==str4)
            cout<<"perfect\n";
        else if(str1==str2&&str3==str4)
            cout<<"even\n";
        else if(str1==str3&&str2==str4)
            cout<<"cross\n";
        else if(str1==str4&&str2==str3)
            cout<<"shell\n";
        else
            cout<<"free\n";
    }
    return 0;
}