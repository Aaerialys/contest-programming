#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int n,m;
int row[510][510];
int col[510][510];
char ch;

int main()
{
    cin>>n;
    fori(1,n+1)
    {
        forj(1,n+1)
        {
            cin>>ch;
            if(ch=='#')
            {
                row[i][j]=row[i][j-1]+1;
                col[j][i]=col[j][i-1]+1;
            }
            else
            {
                row[i][j]=row[i][j-1];
                col[j][i]=col[j][i-1];
            }
        }
    }
    fori(0,n)
    {
        forj(1,n+1-i)
        {
            fork(1,n+1-i)
            {
                if(row[j][k+i]==row[j][k-1]&&col[k][j+i]==col[k][j-1]&&row[j+i][k+i]==row[j+i][k-1]&&col[k+i][j+i]==col[k+i][j-1])
                    m=i;
            }
        }
    }
    cout<<m<<endl;
    return 0;
}