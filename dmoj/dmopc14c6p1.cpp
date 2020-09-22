#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n;
string s[10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin.ignore();
    fori(0,n)
        getline(cin,s[i]);
    fori(1,n-1)
        if(s[i]=="Bessarion"&&(s[i-1]=="Leslie"&&s[i+1]=="Bayview"||s[i+1]=="Leslie"&&s[i-1]=="Bayview"))
        {
            cout<<"Y";
            return 0;
        }
    cout<<"N";
    return 0;
}