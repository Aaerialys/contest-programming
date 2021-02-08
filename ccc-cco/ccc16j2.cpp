#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int s[4][4],x;
    fori(0,4)
        forj(0,4)
            cin>>s[i][j];
    x=s[0][0]+s[0][1]+s[0][2]+s[0][3];
    fori(0,4)
        if(x!=s[i][0]+s[i][1]+s[i][2]+s[i][3]||x!=s[0][i]+s[1][i]+s[2][i]+s[3][i])
        {
            cout<<"not magic\n";
            return 0;
        }
    cout<<"magic\n";
    return 0;
}