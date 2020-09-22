#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    string str;
    fori(0,5)
    {
		int d=0,c=0,maxi=0,count=0,num=-1;
		getline(cin,str);
		for (int i=0; i<str.size(); i++) {
			if (str[i]=='(') {
				d++; c++;
			}
			else if (str[i]==')') {
				d--; c++;
			}
			if (d>maxi) maxi=d;
		}
		for (int i=0; i<str.size(); i++) {
			if ((int)str[i]>47) {
				if (num==-1) num=0;
				num*=10; num+=((int)str[i]-48);
			}
			else {
				if (num!=-1) count+=num;
				num=-1;
			}
		}
		if (str.size()<=2) cout<<0<<' '<<str<<'\n';
		else if (c==2 and maxi==1 and str.size()<=4) cout<<1<<' '<<count<<'\n';
		else cout<<c*2-maxi<<' '<<count<<'\n';
    }
    return 0;
}