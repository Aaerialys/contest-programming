#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    if(b.size()==7)
    {
        if(a=="416")
            cout<<"valuable";
        else if(a=="647"||a=="437")
            cout<<"valueless";
        else
            cout<<"invalid";
        return 0;
    }
    else
        cout<<"invalid";
    return 0;
}