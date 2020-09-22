#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    fori(0,5)
    {
        cin>>n;
        if(n<=0)
            n=1;
        a=floor(log(n)/log(2));
        b=ceil(log(n)/log(2));
        a=1<<a;
        b=1<<b;
        if(n-a<b-n)
            cout<<a<<endl;
        else
            cout<<b<<endl;
    }
    return 0;
}