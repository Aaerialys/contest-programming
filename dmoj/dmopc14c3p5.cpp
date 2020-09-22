#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;
int dp[2100000];
int pre[2100000];
int pre2[2100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,cr=0;
    char ch;
    cin>>n>>m;
    int test[51]={0};
    fori(0,2100000)
        dp[i]=INT_MAX/2;
    fori(0,n)
    {
        forj(0,m)
        {
            cin>>ch;
            test[j]*=2;
            if(ch=='X')
                test[j]++;
        }
    }
    fori(0,m) cr=cr|test[i];
    fori(0,m)
    {
        dp[test[i]]=1;
        pre[test[i]]=0;
        pre2[test[i]]=i+1;
        forj(0,1048577)
        {
            if(dp[j|test[i]]>dp[j]+1)
            {
                dp[j|test[i]]=dp[j]+1;
                pre[j|test[i]]=j;
                pre2[j|test[i]]=test[i];
            }
        }
    }
    cout<<dp[cr]<<endl;
    queue<int> cases;
    int k;
    cases.push(cr);
    while(!cases.empty())
    {
        k=cases.front();
        cases.pop();
        if(pre[k]==0)
            cout<<pre2[k]<<" ";
        else
        {
            cases.push(pre[k]);
            cases.push(pre2[k]);
        }
    }
    cout<<endl;
    return 0;
}