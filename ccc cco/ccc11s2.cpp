#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m=0;
    char a;
    cin>>n;
    char key[n];
    for(int i=0;i<n;i++)
        cin>>key[i];
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==key[i])
            m++;
    }
    cout<<m;
    return 0;
}