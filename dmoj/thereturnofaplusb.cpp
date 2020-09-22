#include <bits/stdc++.h>
using namespace std;

int n;
string a,b;
int trans(string s)
{
    if(s=="1"||s=="one"||s=="un"||s=="一")
        return 1;
    if(s=="2"||s=="two"||s=="deux"||s=="二")
            return 2;
    if(s=="3"||s=="three"||s=="trois"||s=="三")
            return 3;
    if(s=="4"||s=="four"||s=="quatre"||s=="四")
            return 4;
    if(s=="5"||s=="five"||s=="cinq"||s=="五")
            return 5;
    if(s=="6"||s=="six"||s=="六")
            return 6;
    if(s=="7"||s=="seven"||s=="sept"||s=="七")
            return 7;
    if(s=="8"||s=="eight"||s=="huit"||s=="八")
            return 8;
    if(s=="9"||s=="nine"||s=="neuf"||s=="九")
            return 9;
    if(s=="10"||s=="ten"||s=="dix"||s=="十")
            return 10;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<trans(a)+trans(b)<<"\n";
    }
    return 0;
}
/**

*/