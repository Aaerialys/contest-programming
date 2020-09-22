#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x,numb[16],win[32770][3];

int game(int l,int g)
{
    bool in,de; in=de=true; int last=-1;
    if(win[g][l])
        return win[g][l];
    fori(0,n)
    {
        if(!(g&(1<<i)))
        {
            if(last==-1)
                last=i;
            if(numb[i]>numb[last])
                de=false;
            if(numb[i]<numb[last])
                in=false;
            last=i;
        }
    }
    if(de||in)
        return win[g][l]=3-l;
    fori(0,n)
    {
        if(!(g&(1<<i)))
        {
            if(game(3-l,g|(1<<i))==l)
            {
                return win[g][l]=l;
            }
        }
    }
    return win[g][l]=3-l;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fork(0,5)
    {
        forj(0,3)
        {
            fori(0,32770)
                win[i][1]=win[i][2]=0;
            cin>>n;
            fori(0,n)
                cin>>numb[i];
            x=game(1,0);
            if(x==1)
                cout<<"A";
            if(x==2)
                cout<<"B";
        }
        cout<<"\n";
    }
    return 0;
}