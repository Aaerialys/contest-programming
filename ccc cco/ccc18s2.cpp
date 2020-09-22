#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int flower[n][n];
    bool corr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>flower[i][j];
    }
    corr=true;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(flower[i][j]>=flower[i+1][j])
                corr=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(flower[i][j]>=flower[i][j+1])
                corr=false;
        }
    }
    if(corr==true)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<flower[i][j]<<" ";
            cout<<"\n";
        }
    }
    corr=true;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(flower[n-j-1][i]>=flower[n-j-1][i+1])
                corr=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(flower[n-j-1][i]>=flower[n-j-2][i])
                corr=false;
        }
    }
    if(corr==true)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<flower[n-j-1][i]<<" ";
            cout<<"\n";
        }
    }
    corr=true;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(flower[n-i-1][n-j-1]>=flower[n-i-2][n-j-1])
                corr=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(flower[n-i-1][n-j-1]>=flower[n-i-1][n-j-2])
                corr=false;
        }
    }
    if(corr==true)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<flower[n-i-1][n-j-1]<<" ";
            cout<<"\n";
        }
    }
    corr=true;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(flower[j][n-i-1]>=flower[j][n-i-2])
                corr=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(flower[j][n-i-1]>=flower[j+1][n-i-1])
                corr=false;
        }
    }
    if(corr==true)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<flower[j][n-i-1]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}