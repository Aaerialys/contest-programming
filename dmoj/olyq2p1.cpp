#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int s[100001];
int n,m;

bool pos(int x)
{
    int b=0,c=1;
    fori(1,n)
    {
        if(s[i]-s[b]>=x)
        {
            c++;
            b=i;
        }
    }
    if(c>=m)
        return true;
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fori(0,n)
    {
        cin>>s[i];
    }
    sort(s,s+n);
    int l=1<<30,x=1<<29;
    fori(0,30)
    {
        if(pos(l+1))
            l+=x;
        if(!pos(l))
            l-=x;
        x=(x>>1);
    }
    cout<<l;
    return 0;
}