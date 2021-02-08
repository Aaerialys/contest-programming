#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x,y,m,a[101],b[101];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    forj(0,n)
    {
        cin>>x>>y;
        a[x]++; b[y]++;
        x=m=0; y=100;
        fori(0,100)
        {
            x+=a[i];
            while(x>=b[y])
            {
                if(x>0)
                    m=max(m,i+y);
                x-=b[y];
                y--;
            }
        }
        cout<<m<<"\n";
    }
    return 0;
}