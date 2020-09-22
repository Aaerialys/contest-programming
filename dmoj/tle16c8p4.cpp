#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long d,n,p,fuel[100010],path[100010],a,b,x,y;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a;
    if(a==2)
    {
        cin>>n;
        if(n==0)
        {
            cout<<"10 1 1\n5 1";
            return 0;
        }
        if(n==1)
        {
            cout<<"10 1 1\n1 9";
            return 0;
        }
        if(n<60)
        {
            cout<<n<<" "<<n<<" "<<n-1<<"\n";
            fori(1,n)
                cout<<i<<" "<<1<<"\n";
            return 0;
        }
        a=b=0; x=1;
        fori(0,floor(log2(n)))
        {
            if(n&1<<i)
                b++;
        }
        a=min(n,69LL);
        y=a;
        cout<<a<<" "<<1<<" "<<b+floor(log2(n))+1;
        fori(0,floor(log2(n))+1)
        {
            if(n&1<<i)
            {
                cout<<"\n"<<x<<" "<<y-x;
                y--;
            }
            else
            {
                cout<<"\n"<<x<<" "<<y-x;
            }
            x++;
        }
        fori(a-b,a)
            cout<<"\n"<<i<<" "<<1;

        return 0;
    }
    cin>>d>>n>>p;
    fuel[0]=n; path[d]=1;
    fori(0,p)
    {
        cin>>a;
        cin>>fuel[a];
    }
    fori(1,d+1)
    {
        path[d-i]=2*path[d-i+1]-path[min(d+1,d-i+fuel[d-i]+1)];
        path[d-i]%=1000000007;
    }
    cout<<(path[0]-path[1]+1000000007)%1000000007<<endl;
    return 0;
}