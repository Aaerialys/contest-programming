#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int a,b;
	string s2;
	string s;
		for (int t=0; t<5; t++)
		{
		    getline(cin,s);
			//parce properties
			a=0;
			s2="";
				while (s[a]!='<')
					a++;
				while (s[a]!='>')
					s2+=s[a++];
			b=a;
			//nofollow
				if (s2.find("rel=\"nofollow\"")==-1)
				{
					a=s2.find("rel=");
						if (a==-1)
							s2+=" rel=\"nofollow\"";
						else
						{
							a+=5;
								while (s2[a]!='\"')
									a++;
								if (s2[a-1]=='\"')
									s2.insert(a,"nofollow");
								else
									s2.insert(a," nofollow");
						}
				}
			s2+='>';
			//parce rest of stuff
			a=b;
			a++;
				while (s[a]!='>')
					s2+=s[a++];
			s2+='>';
			//output
			cout << s2 << endl;
		}
	return(0);
}