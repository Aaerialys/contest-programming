#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,numb[1002],best[1002][1002],t,c=0;
int b(int x,int y);

int a(int x,int y)
{
    if(best[x][y])
        return best[x][y];
    return best[x][y]=max(b(x-1,y)+numb[y+x-1],b(x-1,y+1)+numb[y]);
}
int b(int x,int y)
{
    if(best[x][y])
        return best[x][y];
    if(numb[y+x-1]>numb[y])
        return best[x][y]=a(x-1,y);
    return best[x][y]=a(x-1,y+1);
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n!=0)
    {
        c++;
        t=0;
        fori(0,1002)
            forj(0,1002)
                best[i][j]=0;
        fori(0,n)
            cin>>numb[i];
        fori(0,n)
        {
            if(n%2==1)
            {
                best[2][i]=min(numb[i],numb[i+1]);
                best[1][i]=numb[i];
            }
            else
            {
                best[2][i]=max(numb[i],numb[i+1]);
            }
            t+=numb[i];
        }
        cout<<"In game "<<c<<", the greedy strategy might lose by as many as "<<2*a(n,0)-t<<" points.\n";
        cin>>n;
    }
    return 0;
}