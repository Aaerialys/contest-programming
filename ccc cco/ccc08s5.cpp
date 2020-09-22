#include <bits/stdc++.h>

using namespace std;

int takeL[31][31][31][31];

int patr(int a,int b,int c,int d);

int rold(int a,int b,int c,int d)
{
    if(takeL[a][b][c][d]==0)
    {
        takeL[a][b][c][d]=2;
        if(a>=2&&b>=1&&d>=2&&patr(a-2,b-1,c,d-2)==1)
            takeL[a][b][c][d]=1;
        if(a>=1&&b>=1&&c>=1&&d>=1&&patr(a-1,b-1,c-1,d-1)==1)
            takeL[a][b][c][d]=1;
        if(c>=2&&d>=1&&patr(a,b,c-2,d-1)==1)
            takeL[a][b][c][d]=1;
        if(b>=3&&patr(a,b-3,c,d)==1)
            takeL[a][b][c][d]=1;
        if(a>=1&&d>=1&&patr(a-1,b,c,d-1)==1)
            takeL[a][b][c][d]=1;
    }
    return takeL[a][b][c][d];
}

int patr(int a,int b,int c,int d)
{
    if(takeL[a][b][c][d]==0)
    {
        takeL[a][b][c][d]=1;
        if(a>=2&&b>=1&&d>=2&&rold(a-2,b-1,c,d-2)==2)
            takeL[a][b][c][d]=2;
        if(a>=1&&b>=1&&c>=1&&d>=1&&rold(a-1,b-1,c-1,d-1)==2)
            takeL[a][b][c][d]=2;
        if(c>=2&&d>=1&&rold(a,b,c-2,d-1)==2)
            takeL[a][b][c][d]=2;
        if(b>=3&&rold(a,b-3,c,d)==2)
            takeL[a][b][c][d]=2;
        if(a>=1&&d>=1&&rold(a-1,b,c,d-1)==2)
            takeL[a][b][c][d]=2;
    }
    return takeL[a][b][c][d];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d,e,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<31;j++)
        {
            for(int k=0;k<31;k++)
            {
                for(int l=0;l<31;l++)
                {
                    for(int m=0;m<31;m++)
                    {
                        takeL[j][k][l][m]=0;
                    }
                }
            }
        }
        cin>>a>>b>>c>>d;
        e=patr(a,b,c,d);
        if(e==2)
            cout<<"Patrick"<<endl;
        else if(e==1)
            cout<<"Roland"<<endl;
    }
    return 0;
}