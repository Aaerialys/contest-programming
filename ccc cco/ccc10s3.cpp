#include <bits/stdc++.h>
    #define fori(a,b) for(int i=a;i<b;i++)
    #define forj(a,b) for(int j=a;j<b;j++)
    #define fork(a,b) for(int k=a;k<b;k++)

    using namespace std;
    int h,k,s=1;
    int house[1010];

    bool pos(int l)
    {
        int x=s,c=1,a;
        fori(0,h)
        {
            a=house[(s+i)%h]-house[x];
            if(a<0)
                a+=1000000;
            if(a>l)
            {
                x=(s+i)%h;
                c++;
            }
        }
        if(c>k)
        {
           return false;
        }
        return true;
    }

    int main()
    {
        cin.sync_with_stdio(0);
        cin.tie(0);
        int x,l,ll;
        cin>>h;
        fori(0,h)
            cin>>house[i];
        sort(house,house+h);
        s=1;
        fori(2,h)
        {
            if(house[i]-house[i-1]>=house[s]-house[s-1])
                s=i;
        }
        if(1000000-house[h-1]+house[0]>=house[s]-house[s-1])
            s=0;
        cin>>k;
        if(pos(0))
        {
            cout<<0;
            return 0;
        }
        x=1<<18;
        l=1<<19;
        fori(0,18)
        {
            if(pos(l-2))
                l-=x;
            if(!pos(l))
                l+=x;
            x=(x>>1);
        }
        l/=2;

        s--;
        if(s<0)
            s+=h;
        if(pos(0))
        {
            cout<<0;
            return 0;
        }
        x=1<<18;
        ll=1<<19;
        fori(0,18)
        {
            if(pos(ll-2))
                ll-=x;
            if(!pos(ll))
                ll+=x;
            x=(x>>1);
        }
        ll/=2;

        cout<<min(l,ll)<<endl;
        return 0;
    }