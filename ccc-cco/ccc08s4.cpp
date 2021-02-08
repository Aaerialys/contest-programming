#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define forl(a,b) for(int l=a;k<b;k++)

using namespace std;

int n,c[4],m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int d=0;d<n;d++)
    {
        m=0;
        fori(0,4)
            cin>>c[i];
        sort(c,c+4);
        do{
        vector<int> p[3],p2[2],p3;
        fori(0,3)
        {
            p[i].push_back(c[i]+c[i+1]);
            p[i].push_back(c[i]-c[i+1]);
            p[i].push_back(c[i]*c[i+1]);
            if(c[i]%c[i+1]==0)
                p[i].push_back(c[i]/c[i+1]);
        }
        fori(0,2)
        {
            forj(0,p[i].size())
            {
                p2[i].push_back(p[i][j]+c[i+2]);
                p2[i].push_back(p[i][j]-c[i+2]);
                p2[i].push_back(p[i][j]*c[i+2]);
                if(c[i+2]!=0&&p[i][j]%c[i+2]==0)
                    p2[i].push_back(p[i][j]/c[i+2]);
            }
            forj(0,p[i+1].size())
            {
                p2[i].push_back(c[i]+p[i+1][j]);
                p2[i].push_back(c[i]-p[i+1][j]);
                p2[i].push_back(c[i]*p[i+1][j]);
                if(p[i+1][j]!=0&&c[i]%p[i+1][j]==0)
                    p2[i].push_back(c[i]/p[i+1][j]);
            }
        }
        fori(0,p2[0].size())
        {
            p3.push_back(p2[0][i]+c[3]);
            p3.push_back(p2[0][i]-c[3]);
            p3.push_back(p2[0][i]*c[3]);
            if(c[3]!=0&&p2[0][i]%c[3]==0)
                p3.push_back(p2[0][i]/c[3]);
        }
        fori(0,p2[1].size())
        {
            p3.push_back(c[0]+p2[1][i]);
            p3.push_back(c[0]-p2[1][i]);
            p3.push_back(c[0]*p2[1][i]);
            if(p2[1][i]!=0&&c[0]%p2[1][i]==0)
                p3.push_back(c[0]/p2[1][i]);
        }
        fori(0,p[0].size())
            forj(0,p[2].size())
            {
                p3.push_back(p[0][i]+p[2][j]);
                p3.push_back(p[0][i]-p[2][j]);
                p3.push_back(p[0][i]*p[2][j]);
                if(p[2][j]!=0&&p[0][i]%p[2][j]==0)
                    p3.push_back(p[0][i]/p[2][j]);
            }
        fori(0,p3.size())
            if(p3[i]<=24)
                m=max(m,p3[i]);
        }while(next_permutation(c,c+4));
        cout<<m<<endl;
    }
    return 0;
}