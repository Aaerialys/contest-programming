#include <bits/stdc++.h>
#define f1 for(int i=0;i<n;i++)

using namespace std;

int ball[405];
int rice[405][405];
int n,m;

int com(int l,int r)
{
    if(rice[l][r]!=0)
        return rice[l][r];
    if(l==r+1)
        return rice[l][r]=0;
    if(l>r)
        return rice[l][r]=-1;
    if(l==r)
        return rice[l][r]=ball[r]-ball[r-1];
    int rr=r,ll=l;
    while(ll<rr)
    {
        if(com(l,ll)!=-1&&com(l,ll)==com(rr,r)&&com(ll+1,rr-1)!=-1)
            return rice[l][r]=com(ll+1,rr-1)+com(l,ll)+com(rr,r);
        if(ball[ll]-ball[l-1]>ball[r]-ball[rr-1])
            rr--;
        else
            ll++;
    }
    return rice[l][r]=-1;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ball[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ball[i];
        ball[i]+=ball[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(com(i,j)>m)
                m=rice[i][j];
        }
    }
    cout<<m<<endl;
    return 0;
}