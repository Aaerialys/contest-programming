#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

bool f[100100][10],pos[100100][10];
int n,x,y,d,z;
stack<int> mov;
queue<int> out;
char ch;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,10)
        forj(0,n)
        {
            cin>>ch;
            if(ch=='.')
                f[j][i]=true;
        }
    pos[0][9]=true;
    fori(0,n-1)
    {
        if(pos[i][9]&&f[i+1][9])
            pos[i+1][9]=true;
        forj(0,9)
            if(pos[i][j]&&f[i+1][j+1])
                pos[i+1][j+1]=true;
        if(pos[i][0]&&f[i+1][0])
            pos[i+1][0]=true;
        forj(1,10)
            if(pos[i][j]&&f[i+1][j-1])
                pos[i+1][j-1]=true;
    }
    fori(0,10)
        if(pos[n-1][i])
            x=i;
    for(int i=n-1;i>0;i--)
    {
        mov.push(x);
        if(x<9&&pos[i-1][x+1])
            x++;
        else if(x>0&&pos[i-1][x-1])
            x--;
    }
    x=9; //cout<<9;
    fori(0,n-1)
    {
        y=mov.top(); mov.pop();
        //cout<<y;/*
        if((y<x||y==0)&&d==0)
        {
            out.push(i);
            z++;
        }
        if(y<x||y==0)
            d++;
        if((y>x||y==9)&&d>0)
            out.push(d);
        if(y>x||y==9)
            d=0;/**/
        x=y;
    }
    cout<<z<<"\n";
    while(!out.empty())
    {
        cout<<out.front()<<" ";
        out.pop();
        cout<<out.front()<<"\n";
        out.pop();
    }
    return 0;
}