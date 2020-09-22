#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    bool prime=true;
    cin>>n;
    if(n<2) n=4;
    fori(2,n)
    {
        if(n%i==0)
            prime=false;
    }
    if(prime)
        cout<<"prime"<<endl;
    else
        cout<<"not"<<endl;
    return 0;
}