#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,x=0,t=0,m=1000000000007;
    string str1=".",str2;
    cin>>n;
    fori(0,n)
    {
        cin>>str2;
        if(toupper(str2[0])==toupper(str1[0]))
        {
            x++;
        }
        else
        {
            t+=x*(x+1)/2%m;
            x=1;
        }
        str1=str2;
    }
    t+=x*(x+1)/2%m;
    cout<<t;
    return 0;
}