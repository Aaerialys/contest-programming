#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
bool pos[40000],pos2[40000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    int w[40];
    fork(0,5)
    {
        cin>>n;
        t=0;
        fori(0,n)
        {
            cin>>w[i];
            t+=w[i];
        }
        fori(0,40000)
        {
            pos[i]=false;
            pos2[i]=false;
        }
        pos[0]=true;
        fori(0,n)
        {
            forj(0,40000)
            {
                if(pos[j])
                {
                    pos2[abs(j-w[i])]=true;
                    pos2[j+w[i]]=true;
                }
            }
            forj(0,40000)
            {
                pos[j]=pos2[j];
                pos2[j]=false;
            }
        }
        fori(0,40000)
        {
            if(pos[i])
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}