#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int pop[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a=0;
    unordered_map<string,int> number;
    unordered_map<int,string> name;
    string str;
    cin>>n;
    fori(0,n)
    {
        cin>>str;
        if(number.count(str)==0)
        {
            number.emplace(str,a);
            name.emplace(a,str);
            a++;
        }
        pop[number[str]]++;
    }
    fori(0,n-1)
    {
        cin>>str;
        pop[number[str]]--;
    }
    fori(0,n)
    {
        if(pop[i]>0)
            cout<<name[i]<<endl;
    }
    return 0;
}