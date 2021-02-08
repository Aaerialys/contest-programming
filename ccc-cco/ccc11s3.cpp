#include <iostream>
#include <math.h>

using namespace std;

bool crystal(int x,int y,int m)
{
    int cry[5][5]={{0,0,0,0,0},{2,1,0,0,0},{2,2,1,0,0},{2,1,0,0,0},{0,0,0,0,0}};
    int c=pow(5,m-1),a=x/c,b=y/c;
    if(cry[a][b]==0||(cry[a][b]==1&&m==1))
    {
        return false;
    }
    else if(cry[a][b]==2)
    {
        return true;
    }
    else
    {
        return crystal(x%c,y%c,m-1);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int m,x,y;
        cin>>m>>x>>y;
        if(crystal(x,y,m)==true)
            cout<<"crystal"<<endl;
        else
        {
            cout<<"empty"<<endl;
        }
    }
    return 0;
}