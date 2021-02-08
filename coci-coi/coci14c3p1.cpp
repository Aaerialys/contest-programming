#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int fr[8];
string in,f[8]={"`1QAZ","2WSX","3EDC","4RFV5TGB","6YHN7UJM","8IK,","9OL.","0P;/-['=]"};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>in;
    fori(0,in.size())
        forj(0,8)
            if(f[j].find(in[i])!=string::npos)
                fr[j]++;
    fori(0,8)
        cout<<fr[i]<<endl;
    return 0;
}