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
    int h,s; h=s=0;
    getline(cin,str);
    if(str.size()<3)
    {
        cout<<"none";
        return 0;
    }
    fori(0,str.size()-3)
    {
        if(str.substr(i,3)==":-)")
            h++;
        if(str.substr(i,3)==":-(")
            s++;
    }
    if(h==0&&s==0)
        cout<<"none";
    else if(h==s)
        cout<<"unsure";
    if(h>s)
        cout<<"happy";
    if(h<s)
        cout<<"sad";
    return 0;
}