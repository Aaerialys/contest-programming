#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str;
    int u=0,l=0;
    getline (std::cin,str);
    for(int i=0;i<str.length();i++)
    {
        if(isupper(str[i])!=false&&str[i]!=' ')
        {
            u++;
        }
        else if(isupper(str[i])==false&&str[i]!=' ')
        {
            l++;
        }
    }
    if(u>l)
    {
        transform(str.begin(),str.end(),str.begin(),::toupper);
        cout<<str;
    }
    else if(l>u)
    {
        transform(str.begin(),str.end(),str.begin(),::tolower);
        cout<<str;
    }
    else
    {
        cout<<str;
    }
    return 0;
}