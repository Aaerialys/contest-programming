#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d,p[4]={461,431,420},q[4]={100,57,70},r[4]={130,160,118},s[4]={167,266,75};
    cin>>a>>b>>c>>d;
    cout<<"Your total Calorie count is "<<p[a-1]+q[b-1]+r[c-1]+s[d-1]<<'.';
    return 0;
}