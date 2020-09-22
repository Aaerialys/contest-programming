#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,c,x;
    bool y=true;
    cin>>n>>c;
    int cut[c];
    fori(0,c)
    {
        cin>>cut[i];
    }
    fori(0,n)
    {
        cin>>x;
        forj(0,c)
        {
            while(gcd(x,cut[j])>1)
                x/=gcd(x,cut[j]);
        }
        if(x!=1)
            y=false;
    }
    if(y)
        cout<<"Y";
    else
        cout<<"N";
    return 0;
}