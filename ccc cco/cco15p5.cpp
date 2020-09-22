#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,d,x,y,a,b;
double c,m[110][21000],tim[110],nt[110];
vector<int> pos;
bool be;

int pow(int x,int y)
{
    if(y==0)
        return 1;
    return pow(x,y-1)*x;
}

bool ply(int x,int y)
{
    fori(0,d)
        if(x/pow(12,i)%12==y)
            return true;
    return false;
}

int dif(int x,int y)
{
    a=0;
    fori(0,d)
        if(x/pow(12,i)%12!=y/pow(12,i)%12)
            a++;
    return a;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d; b=pow(12,d);
    fori(0,b)
    {
        be=true;
        forj(0,d)
        {
            if(j!=d-1&&i/pow(12,j)%12<=i/pow(12,j)/12%12)
                be=false;
        }
        if(be)
            pos.push_back(i);
    }
    fori(0,n)
    {
        cin>>tim[i]>>nt[i];
        nt[i]--;
    }
    fori(0,pos.size())
    {
        m[0][pos[i]]=0;
        if(ply(pos[i],nt[0]))
            m[0][pos[i]]=INT_MAX;
    }
    fori(1,n)
    {
       forj(0,pos.size())
        {
            m[i][pos[j]]=0;
            if(ply(pos[j],nt[i]))
            {
                fork(0,pos.size())
                {
                    if(dif(pos[j],pos[k])!=0)
                        m[i][pos[j]]=max(m[i][pos[j]],min(m[i-1][pos[k]],(tim[i]-tim[i-1])/dif(pos[j],pos[k])));
                    else
                        m[i][pos[j]]=max(m[i][pos[j]],m[i-1][pos[k]]);
                }
            }
        }
    }
    c=0;
    fori(0,pos.size())
        c=max(c,m[n-1][pos[i]]);
    if(c==INT_MAX)
        cout<<"0.00";
    else
        printf("%.2f",c);
    return 0;
}