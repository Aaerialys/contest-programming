#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int r,c,f[401][401],m,x,t;
char ch;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>c;
    fori(1,r+1)
        forj(1,c+1)
        {
            cin>>ch;
            if(ch=='X')
                f[i][j]=1;
        }
    fori(1,r+1)
        forj(1,c+1)
            f[i][j]+=f[i][j-1];
    fori(1,c+1)
    {
        forj(i,c+1)
        {
            x=m=0;
            fork(1,r+1)
            {
                if(f[k][j]-f[k][i-1]==0)
                    m++;
                else
                    m=0;
                x=max(x,m);
            }
            if(x!=0)
                t=max(t,(j-i+1+x)*2);
        }
    }
    cout<<t-1;
    return 0;
}