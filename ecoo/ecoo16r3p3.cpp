#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;
string str;
string word[200010];

bool isEqual(int a,int b,int x)
{
    fori(a,b)
    {
        if(str[i]!=word[x][i-a])
            return false;
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,ll,x;
    cin>>n;
    fori(0,n) cin>>word[i];
    fork(0,10)
    {
        cin>>str;
        ll=str.length();
        int dp[ll+1];
        fori(0,ll+1) dp[i]=INT_MAX/2;
        dp[0]=-1;
        fori(0,ll)
        {
            forj(0,n)
            {
                x=word[j].length();
                if(i+1>=x&&dp[i-x+1]+1<dp[i+1]&&isEqual(i-x+1,i+1,j))
                    dp[i+1]=dp[i-x+1]+1;
            }
        }
        cout<<dp[ll]<<endl;
    }
    return 0;
}