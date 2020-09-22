#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a="";
    bool b=true;
    while (a!="False"&&a!="True")
    {
        cin>>a;
        b=!b;
    }
    if(a=="True")
        b=!b;
    if(b)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}