#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int year,day,mon,n;
    bool vote;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vote=false;
        cin>>year>>mon>>day;
        if(year<1989)
            vote=true;
        else if(year==1989)
        {
            if(mon<2)
                vote=true;
            else if(mon==2)
            {
                if(day<=27)
                    vote=true;
            }
        }
        if(vote)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}