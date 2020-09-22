#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c,n;
    cin>>n;
    fori(0,n)
    {
        cin>>a>>b>>c;
        if(a*b==c)
            cout<<"POSSIBLE DOUBLE SIGMA\n";
        else
            cout<<"16 BIT S/W ONLY\n";
    }
    return 0;
}