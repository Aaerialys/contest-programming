#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int work[10];
bool numb[10000000],numb2[10000000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int w,d,v;
    cin>>w>>d;
    fori(0,d)
    {
        cin>>v;
        work[v]=1;
        numb[v]=1;
    }
    fori(0,w)
    {
        forj(0,10000000)
            numb2[j]=0;
        forj(0,10000000)
        {
            if(numb[j])
            {
                fork(0,10)
                {
                    if(work[k])
                    {
                        numb2[j+k]=1;
                        numb2[j*k]=1;
                    }
                }
            }
        }
        forj(0,10000000)
        {
            numb[j]=numb2[j];
        }
    }
    cin>>v;
    fori(0,v)
    {
        cin>>w;
        if(numb2[w])
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    return 0;
}