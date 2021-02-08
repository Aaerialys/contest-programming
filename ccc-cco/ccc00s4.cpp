#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,c;
    cin>>n>>c;
    int best[n+1]={0};
    int club[c];
    for(int i=0;i<c;i++)
        cin>>club[i];
    for(int i=1;i<=n;i++)
    {
        best[i]=10000000;
        for(int j=0;j<c;j++)
        {
            if(i>=club[j]&&best[i-club[j]]+1<best[i])
            {
                best[i]=best[i-club[j]]+1;
            }
        }
    }
    if(best[n]>=10000000)
        cout<<"Roberta acknowledges defeat.";
    else
        cout<<"Roberta wins in "<<best[n]<<" strokes.";
    return 0;
}