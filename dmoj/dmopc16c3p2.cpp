#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,k,d,jack[100010],a,b,c,M=1e7;
char ch;
stack<pair<char,int>> v;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>d;
    fori(0,n)
    {
        a=i;
        cin>>ch;
        if(ch=='B')
            cin>>a;
        v.push({ch,a});
    }
    jack[k+1]=1;
    a=k;
    while(!v.empty())
    {
        ch=v.top().first;
        if(ch=='T')
        {
            if(jack[a]==0)
                jack[a]=jack[a+1];
            a--;
        }
        if(ch=='B')
        {
            b=v.top().second;
            if(jack[a]==0)
                jack[a]=min(M,jack[a+1]*b);
            else
                jack[a]=min(M,jack[a]*b);
        }
        v.pop();
    }
    fori(1,k+1)
    {
        if(jack[i]>d)
            cout<<"dust\n";
        else
            cout<<jack[i]<<"\n";
    }
    return 0;
}