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
    fori(0,str.size()-3)
        if(str.substr(i,4)=="java")
        {
            cout<<i;
            return 0;
        }
    cout<<str.size();
    return 0;
}