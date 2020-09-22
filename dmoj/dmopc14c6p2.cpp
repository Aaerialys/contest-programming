#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,x1,x2,y1,y2;
    cin>>n>>a>>b;
    x1=y1=a;
    x2=y2=0;
    fori(1,n-1)
    {
        cin>>a>>b;
        x1-=max(b-x2,0);
        x2=max(x2-b,0);
        y2-=max(b-y1,0);
        y1=max(y1-b,0);
        x2+=a;
        y2+=a;
    }
    cout<<y1<<endl<<x1;
    return 0;
}