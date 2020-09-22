#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,N,m,a,b;
    char ch;
    cin>>n>>m;
    N=1<<n;
    int win[N<<1]={0};
    fori(0,N)
    {
        cin>>win[N+i];
    }
    for(int j=(N<<1)-1;j>1;j-=2)
    {
        win[j/2]=max(win[j],win[j-1]);
    }
    fori(0,m)
    {
        cin>>ch;
        if(ch=='R')
        {
            cin>>a>>b;
            a+=N-1;
            win[a]=b;
            while(a>1)
            {
                if(a%2==0)
                    a++;
                win[a/2]=max(win[a],win[a-1]);
                a/=2;
            }
        }
        if(ch=='W')
        {
            a=1;
            while(a<N)
            {
                if(win[a<<1]==win[a])
                    a=a<<1;
                else
                    a=(a<<1)+1;
            }
            cout<<a-N+1<<"\n";
        }
        if(ch=='S')
        {
            cin>>a;
            a+=N-1;
            n=win[a];
            b=-1;
            while(win[a]==n)
            {
                b++;
                a/=2;
            }
            cout<<b<<"\n";
        }
    }
    return 0;
}