#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,t;

void out(int x,int m,string str)
{
    str+="+";
    if(m<=x&&x<n)
    {
        cout<<n<<"="<<str.substr(1)<<x<<"\n";
        t++;
    }
    fori(m,x)
        out(x-i,i,str+to_string(i));
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    out(n,1,"");
    cout<<"total="<<t;
    return 0;
}