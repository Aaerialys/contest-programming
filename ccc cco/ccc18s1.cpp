#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    double m=INT_MAX,a,c;
    cin>>n;
    int vil[n];
    for(int i=0;i<n;i++)
    {
        cin>>vil[i];
    }
    sort(vil,vil+n);
    for(int i=1;i<n-1;i++)
    {
        a=vil[i+1]-vil[i-1];
        c=a/2;
        if(m>c)
            m=c;
    }
    printf("%.1f",m);
    return 0;
}