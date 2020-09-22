#include <bits/stdc++.h>
#include "secret.h"
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;


int ans[1001][1001],n;

void ask(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    fori(mid+2,r+1)
        ans[mid+1][i]=Secret(ans[mid+1][i-1],ans[i][i]);
    for(int i=mid-1;i>=l;i--)
        ans[i][mid]=Secret(ans[i][i],ans[i+1][mid]);
    ask(l,mid);
    ask(mid+1,r);
}

void Init(int N,int A[])
{
    fori(0,N)
        forj(0,N)
            ans[i][j]=0;
    fori(0,N)
        ans[i][i]=A[i];
    ask(0,N-1);
    n=N;
}

int Query(int L,int R)
{
    int l=0,r=n-1,mid=(l+r)/2;
    while(mid<L||mid>R)
    {
        while(mid<L)
        {
            l=mid+1;
            mid=(l+r)/2;
        }
        while(mid>R)
        {
            r=mid;
            mid=(l+r)/2;
        }
    }
    if(L==mid+1)
        return ans[mid+1][R];
    if(R==mid)
        return ans[L][mid];
    return Secret(ans[L][mid],ans[mid+1][R]);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N,A[1000],a,b,c;
    cin>>N;
    fori(0,N)
        cin>>A[i];
    Init(N,A);
    fori(0,N)
    {
        forj(i,N)
        {
            i=5; j=5;
            c=A[i];
            fork(i+1,j+1)
                c=Secret(c,A[k]);
            if(Query(i,j)!=c)
                cout<<i<<" "<<j<<" "<<Query(i,j)<<" "<<c<<"\n";
        }
    }
    fori(0,N)
        cin>>A[i];
    return 0;
}
/*
find the midpoint m from 0-n
ask her from each number to m
find midpoint m2 from 0-m
ask her for each number between 0-m to m2
find midpoint m3 from m-n
ask her for each number m-n to m3
so on...

query l-r
find the highest level midpoint m1,m2,m3... between l-r
you know what is l-m, and m-r
ask her what the answer for those 2 are
that is the answer

*/