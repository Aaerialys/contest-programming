#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a=INT_MAX,b=0,c=0,n,x,y,z;
    string aa,bb,cc;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>aa>>x>>y>>z;
        a=2*x+3*y+z;
        if(a>b||(a==b&&aa<bb))
        {
            c=b;
            cc=bb;
            b=a;
            bb=aa;
        }
        else if(a>c||(a==c&&aa<cc))
        {
            c=a;
            cc=aa;
        }
    }
    if(n==0){}
    else if(n==1)
        cout<<bb;
    else
        cout<<bb<<endl<<cc;
    return 0;
}