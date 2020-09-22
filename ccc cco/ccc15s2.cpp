#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int J,A,a,b,t=0;
    char x;
    cin>>J>>A;
    int jersy[J]={0};
    for(int i=0;i<J;i++)
    {
        cin>>x;
        if(x=='S')
            jersy[i]=1;
        if(x=='M')
            jersy[i]=2;
        if(x=='L')
            jersy[i]=3;
    }
    for(int i=0;i<A;i++)
    {
        cin>>x>>a;
        a--;
        if(x=='S')
            b=1;
        if(x=='M')
            b=2;
        if(x=='L')
            b=3;
        if(jersy[a]>=b)
        {
            t++;
            jersy[a]=0;
        }
    }
    cout<<t;
    return 0;
}