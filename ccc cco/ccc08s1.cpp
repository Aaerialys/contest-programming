#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m=INT_MAX,t;
    string mc,tc;
    cin>>tc>>t;
    while(tc!="Waterloo")
    {
        if(m>t)
        {
            m=t;
            mc=tc;
        }
        cin>>tc>>t;
    }
    cout<<mc;
    return 0;
}