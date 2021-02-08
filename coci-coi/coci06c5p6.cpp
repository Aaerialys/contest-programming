#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int n;
string s;
int rnk[N],rnk2[N],sa[N],lcp[N],shift,last; bool done;
void genSa(){
    rnk[n]=-1; iota(sa,sa+n+1,0);
    sort(sa,sa+n,[&](int a,int b){return s[a]<s[b];});
    for(int i=0;i<n;i++) rnk[sa[i]]=i&&s[sa[i]]==s[sa[i-1]]? rnk[sa[i-1]]: i;
    for(shift=1;!done;shift<<=1){
        last=0; done=true;
        for(int i=1;i<=n;i++)
            if(rnk[sa[i]]!=rnk[sa[i-1]]){
                sort(sa+last,sa+i,[&](int a,int b){return rnk[a+shift]<rnk[b+shift];});
                rnk2[sa[last]]=last;
                for(int j=last+1;j<i;j++){
                    if(rnk[sa[j]+shift]!=rnk[sa[j-1]+shift])
                        rnk2[sa[j]]=j;
                    else{
                        rnk2[sa[j]]=rnk2[sa[j-1]];
                        done=false;
                    }
                }
                for(int j=last+1;j<i;j++) rnk[sa[j]]=rnk2[sa[j]];
                last=i;
            }
    }
}
void genLcp(){
    last=0;
    for(int i=0;i<n;i++){
        if(rnk[i]==n-1){
            last=0;
            continue;
        }
        for(int j=sa[rnk[i]+1];i+last<n&&j+last<n&&s[i+last]==s[j+last];last++);
        lcp[rnk[i]]=last;
        if(last) last--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>s;
    genSa(); genLcp();
    cout<<*max_element(lcp,lcp+n);
    return 0;
}
/**
1 bbababb
*/