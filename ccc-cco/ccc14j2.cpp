#include <bits/stdc++.h>

using namespace std;
 
int a,b,n;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    char x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x=='A')
            a++;
        else
            b++;
    }
    if(a==b)
        cout<<"Tie";
    else if(a>b)
        cout<<"A";
    else
        cout<<"B";
    return 0;
}