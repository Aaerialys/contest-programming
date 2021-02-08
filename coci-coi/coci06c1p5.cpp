#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

double prob[22][22];
double best[2097152];
int n;
double dp(int a,int b)
{
    if(a==-1)
    {
        return 1;
    }
    if(best[b]>=0)
    {
        return best[b];
    }
    fori(0,n)
    {
        if(!(b&(1<<i)))
        {
            best[b]=max(best[b],dp(a-1,b|(1<<i))*prob[a][i]);
        }
    }
    return best[b];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        forj(0,n)
        {
            cin>>prob[i][j];
            prob[i][j]/=100;
        }
    }
    fori(0,2097152)
        best[i]=-1;
    printf("%.7f\n", dp(n-1,0)*100.0);
    return 0;
}