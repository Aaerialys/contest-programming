#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int letter[26]={0};
    int ast=0;
    char c;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++)
    {
        letter[a[i]-'a']++;
    }
    for(int i=0;i<b.length();i++)
    {
        if(b[i]=='*')
            ast++;
        else
            letter[b[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(letter[i]>0)
            ast-=letter[i];
    }
    if(ast!=0)
        cout<<"N";
    else
        cout<<"A";
    return 0;
}