#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fork(0,10)
    {
        long long n,m,l,a=0,t=0,b;
        cin>>n>>m>>l;
        long long res[n];
        vector<long long>regular;
        m*=1000000;
        fori(0,n)
        {
            cin>>res[i];
            res[i]=res[i]*1000000+110000-i;
        }
        sort(res,res+n);
        reverse(res,res+n);
        while(t<l)
        {
            a++;
            if(a==n)
            {
                regular.push_back(res[a-1]);
                t=l-(l-t-1)%a-1;
                break;
            }
            else
            {
                b=res[a-1]/m-res[a]/m;
                if(a*b+t<l)
                {
                    t+=a*b;
                    regular.push_back(res[a-1]);
                }
                else
                {
                    t=l-(l-t-1)%a-1;
                    regular.push_back(res[a-1]);
                    break;
                }
            }
        }
        b=regular.size();
        fori(0,b)
        {
            regular[i]=regular[i]%m;
        }
        sort(regular.begin(),regular.end());
        reverse(regular.begin(),regular.end());
        cout<<110000-regular[l-t-1]%1000000+1<<endl;
    }
    return 0;
}