#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    string b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        a=0;
        for(int i=0;i<b.length();i++)
        {
            a+=b[i]-'0';
        }
        while(a>=10)
        {
            a=a/10+a%10;
        }
        cout<<a<<endl;
    }
    return 0;
}