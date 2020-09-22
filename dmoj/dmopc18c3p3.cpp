#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,l,len[1000100];
long long t;
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>in;
    fori(0,n+1)
    {
        if(i==n||in[l]!=in[i])
        {
            forj(l,i)
                len[j]=i-l;
            l=i;
        }
    }
    fori(0,n)
        t+=min(min(i+1,n-i),len[i]);
    fori(0,n-1)
        t+=min(min(i+1,n-i-1),max(len[i],len[i+1]));
    cout<<t;
    return 0;
}