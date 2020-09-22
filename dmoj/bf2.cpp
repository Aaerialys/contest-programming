#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str,best="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    int k;
    cin>>str>>k;
    for(int i=0;i<str.length()-k;i++)
    {
        if(str.substr(i,k)<best)
            best=str.substr(i,k);
    }
    cout<<best;
    return 0;
}