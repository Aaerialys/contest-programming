#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    forj(0,5)
    {
        bool p;
        p=true;
        cin>>n;
        vector<int> card;
        int c[n];
        fori(0,n)
            cin>>c[i];
        fori(0,n)
        {
            a=c[n-i-1];
            if(a<0||a>i)
            {
                cout<<"IMPOSSIBLE";
                p=false;
                break;
            }
            card.insert(card.begin()+a,i);
        }
        if(p){
            fori(0,n)
            {
                c[card[i]]=n-i;
            }
            fori(0,n)
            {
                cout<<c[n-i-1]<<" ";
            }
        }
        cout<<endl;
    }
        return 0;
}