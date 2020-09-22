#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,ma=INT_MAX,mb=0,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if (b>mb)
        {
            mb=b;
            ma=a;
        }
        else if(b==mb&&a<ma)
        {
            mb=b;
            ma=a;
        }
    }
    cout<<ma<<" "<<mb;
    return 0;
}