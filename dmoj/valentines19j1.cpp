#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,k,x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        if(x<1000)
            cout<<"Newbie\n";
        else if(x<1200)
            cout<<"Amateur\n";
        else if(x<1500)
            cout<<"Expert\n";
        else if(x<1800)
            cout<<"Candidate Master\n";
        else if(x<2200)
            cout<<"Master\n";
        else if(x<3000)
            cout<<"Grandmaster\n";
        else if(x<4000)
            cout<<"Target\n";
        else
            cout<<"Rainbow Master\n";
    }
    return 0;
}