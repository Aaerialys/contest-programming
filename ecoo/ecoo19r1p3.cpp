#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

char f[12][110];
int J,w,h,l,g,m;
bool pass;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fork(0,10)
    {
        cin>>J>>w>>h;
        fori(0,12)
            forj(0,102)
                f[i][j]='@';
        ford(i,h-1,0)
            forj(0,w)
            {
                cin>>f[i][j];
                if(f[i][j]=='L')
                    l=j;
                if(f[i][j]=='G')
                    g=j;
            }
        fori(l,g+1)
        {
            if(i==g)
            {
                cout<<"CLEAR"<<endl;
                break;
            }
            if(f[1][i+1]=='@')
            {
                pass=false;
                forj(2,J+2)
                {
                    if(f[j][i]=='@'||f[j][i+2]=='@')
                        break;
                    if(f[j][i+1]=='.')
                    {
                        pass=true;
                        break;
                    }
                }
                if(f[1][i+2]=='@')
                    pass=false;
                if(!pass)
                {
                    cout<<i+2<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}