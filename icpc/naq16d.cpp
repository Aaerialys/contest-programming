#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,sum[5010],ma[15][5010],mi[15][5010];
string str;

int mini(int l,int r)
{
    if(l>r)
        return INT_MAX;
    int z=log2(r-l+1);
    return min(mi[z][l],mi[z][r-(1<<z)]);
}
int maxi(int l,int r)
{
    if(l>r)
        return INT_MIN;
    int z=log2(r-l+1);
    return max(ma[z][l],ma[z][r-(1<<z)]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>str; n=str.size();
    fori(1,n+1)
    {
        if(str[i-1]=='(')
            sum[i]=sum[i-1]+1;
        if(str[i-1]==')')
            sum[i]=sum[i-1]-1;
        mi[0][i]=ma[0][i]=sum[i];
    }
    fori(1,15)
        forj(0,5010-(1<<i)+1)
        {
            ma[i][j]=max(ma[i-1][j],ma[i-1][j+(1<<(i-1))]);
            mi[i][j]=min(mi[i-1][j],mi[i-1][j+(1<<(i-1))]);
        }
    if(sum[n]==0&&mini(1,n)>=0)
    {
        cout<<"possible";
        return 0;
    }
    fori(1,n+1)
        forj(i,str.size()+1)
        {
            if(mini(0,i-1)>=0&&sum[i-1]*2-maxi(i,j)>=0&&mini(j+1,n)-sum[j]*2+sum[i-1]*2>=0&&sum[n]-sum[j]*2+sum[i-1]*2==0)
            {
                cout<<"possible";
                return 0;
            }
        }
    cout<<"impossible";
    return 0;
}